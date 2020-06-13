#include "server.h"
#include <sys/stat.h>
#include <sys/types.h>
#include <unistd.h>
#include <fcntl.h>
#include "../SERVER_SETTINGS.h"


void disconnectClient(fd_set &master, int socketNumber);

bool clientIsRegistered(const RaceField &raceField, int socketNumber);

using namespace std;

int main(int argc, char *argv[]) {
    if (argc < 5) {
        fprintf(stderr, "usage: gridserver –x NUM –y NUM\n");
        return 1;
    }

    RaceField raceField(argc, argv);

    //Configuring local address
    struct addrinfo hints{};
    memset(&hints, 0, sizeof(hints));
    hints.ai_family = AF_INET;
    hints.ai_socktype = SOCK_STREAM;
    hints.ai_flags = AI_PASSIVE;

    struct addrinfo *bind_address;
    getaddrinfo(nullptr, PORT, &hints, &bind_address);


    //Creating socket
    SOCKET socket_listen;
    socket_listen = socket(bind_address->ai_family,
                           bind_address->ai_socktype, bind_address->ai_protocol);
    if (!ISVALIDSOCKET(socket_listen)) {
        fprintf(stderr, "socket() failed. (%d)\n", GETSOCKETERRNO());
        return 1;
    }


    //Binding socket to local address
    if (bind(socket_listen,
             bind_address->ai_addr, bind_address->ai_addrlen)) {
        fprintf(stderr, "bind() failed. (%d)\n", GETSOCKETERRNO());
        return 1;
    }
    freeaddrinfo(bind_address);


    //Listening
    if (listen(socket_listen, 10) < 0) {
        fprintf(stderr, "listen() failed. (%d)\n", GETSOCKETERRNO());
        return 1;
    }

    fd_set master;
    FD_ZERO(&master);
    FD_SET(socket_listen, &master);
    SOCKET max_socket = socket_listen;

    int fd;
    char * myfifo = "/tmp/myfifo";
    mkfifo(myfifo, 0666);

    //Waiting for connections
    while (true) {
        fd_set reads;
        reads = master;
        if (select(max_socket + 1, &reads, 0, 0, 0) < 0) {
            fprintf(stderr, "select() failed. (%d)\n", GETSOCKETERRNO());
            return 1;
        }

//        try {
        SOCKET i;
        for (i = 1; i <= max_socket; ++i) {
            if (FD_ISSET(i, &reads)) {

                if (i == socket_listen) {
                    struct sockaddr_storage client_address{};
                    socklen_t client_len = sizeof(client_address);
                    SOCKET socket_client = accept(socket_listen,
                                                  (struct sockaddr *) &client_address,
                                                  &client_len);
                    if (!ISVALIDSOCKET(socket_client)) {
                        fprintf(stderr, "accept() failed. (%d)\n",
                                GETSOCKETERRNO());
                        return 1;
                    }

                    FD_SET(socket_client, &master);
                    if (socket_client > max_socket)
                        max_socket = socket_client;

                    char address_buffer[100];
                    getnameinfo((struct sockaddr *) &client_address,
                                client_len,
                                address_buffer, sizeof(address_buffer), 0, 0,
                                NI_NUMERICHOST);
//                    printf("New connection from %s\n", address_buffer);
                } else {
                    char read[1024];
                    int bytes_received = recv(i, read, 1024, 0);
                    if (bytes_received < 1) {
                        disconnectClient(master, i);
                        continue;
                    }
                    if (!clientIsRegistered(raceField, i)) {
                        string receivedLetter = string(read).substr(0,1); //message contains \n and ip, therefore I have to use substr
                        if (!raceField.isFull() && StringUtil::isSingleCapitalLetter(receivedLetter) && !raceField.letterIsTaken(receivedLetter)) {
                            string position = raceField.placeCar(i, receivedLetter);
                            string message = "Registration OK. Start position: " + position + ".";
                            send(i, message.c_str(), message.length(), 0);
                        } else {
                            string message = "Registration FAILED\n";
                            send(i, message.c_str(), message.length(), 0);
                            disconnectClient(master, i);
                        }
                    } else {
                        string receivedLetter = string(read).substr(0, 1);
                        if (!raceField.moveCar(i, receivedLetter)) {
                            string message = "Vehicle has been eliminated.\n";
                            send(i, message.c_str(), message.length(), 0);
                            disconnectClient(master, i);
                        } else {
                            string message = "Enter move: ";
                            send(i, message.c_str(), message.length(), 0);
                        }
                        string field = StringUtil::flatMapVectorOfVectorsIntoMessage(raceField.getFields());
//                        cout << field; //no need to display, griddisplay takes car of that

                        fd = open(myfifo, O_WRONLY);
                        write(fd, field.c_str(), field.length()+1);
                    }
                }
            } //if FD_ISSET
        } //for i to max_socket
    }
//        catch (...) {
//
//            break;
//        }
    //while(1)

    printf("Closing listening socket...\n");
    CLOSESOCKET(socket_listen);

    printf("Finished.\n");
    return 0;
}

bool clientIsRegistered(const RaceField &raceField,
                        int socketNumber) {
    return StringUtil::isSingleCapitalLetter(raceField.getCarName(socketNumber));
}

void disconnectClient(fd_set &master, int socketNumber) {
    FD_CLR(socketNumber, &master);
    CLOSESOCKET(socketNumber);
}
