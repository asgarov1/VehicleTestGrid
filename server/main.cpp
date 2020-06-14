#include <sys/stat.h>
#include <sys/types.h>
#include <unistd.h>
#include <fcntl.h>
#include <iostream>
#include "RaceField.h"
#include "StringUtil.h"
#include "Server.h"

bool clientIsRegistered(const RaceField &raceField, int socketNumber);

using namespace std;

int main(int argc, char *argv[]) {
    if (argc < 5) {
        fprintf(stderr, "usage: gridserver –x NUM –y NUM\n");
        return 1;
    }

    RaceField raceField(argc, argv);

    //Setting up griddisplay pipe
    int fd;
    char *myfifo = "/tmp/myfifo";
    mkfifo(myfifo, 0666);

    Server server;

    //Waiting for connections
    cout << "Server is running, ready for connections..." << endl;
    while (true) {
        fd_set reads;
        reads = server.getMaster();
        if (select(server.getMaxSocket() + 1, &reads, 0, 0, 0) < 0) {
            fprintf(stderr, "select() failed. (%d)\n", GETSOCKETERRNO());
            return 1;
        }

        SOCKET i;
        for (i = 1; i <= server.getMaxSocket(); ++i) {
            if (FD_ISSET(i, &reads)) {

                if (i == server.getSocketListen()) {
                    struct sockaddr_storage client_address{};
                    socklen_t client_len = sizeof(client_address);
                    SOCKET socket_client = accept(server.getSocketListen(),
                                                  (struct sockaddr *) &client_address,
                                                  &client_len);
                    if (!ISVALIDSOCKET(socket_client)) {
                        fprintf(stderr, "accept() failed. (%d)\n",
                                GETSOCKETERRNO());
                        return 1;
                    }

                    server.fdSetWithMaster(socket_client);
                    if (socket_client > server.getMaxSocket())
                        server.setMaxSocket(socket_client);

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
                        server.disconnectClient(i);
                        continue;
                    }
                    if (!clientIsRegistered(raceField, i)) {
                        string receivedLetter = string(read).substr(0,
                                                                    1); //message contains \n and ip, therefore I have to use substr
                        if (!raceField.isFull() && StringUtil::isSingleCapitalLetter(receivedLetter) &&
                            !raceField.letterIsTaken(receivedLetter)) {
                            string position = raceField.placeCar(i, receivedLetter);
                            string message = "Registration OK. Start position: " + position + ".";
                            send(i, message.c_str(), message.length(), 0);
                        } else {
                            string message = "Registration FAILED\n";
                            send(i, message.c_str(), message.length(), 0);
                            server.disconnectClient(i);
                        }
                    } else {
                        string receivedLetter = string(read).substr(0, 1);
                        if (!raceField.moveCar(i, receivedLetter)) {
                            string message = "Vehicle has been eliminated.\n";
                            send(i, message.c_str(), message.length(), 0);
                            server.disconnectClient(i);

                            if(raceField.isWasClash() && raceField.getLastVictimCarIndex() != -1){
                                send(raceField.getLastVictimCarIndex(), message.c_str(), message.length(), 0);
                                server.disconnectClient(raceField.getLastVictimCarIndex());
                                raceField.setWasClash(false);
                            }
                        } else {
                            string message = "Enter move: ";
                            send(i, message.c_str(), message.length(), 0);
                        }
                        string field = StringUtil::flatMapVectorOfVectorsIntoMessage(raceField.getFields());
                        fd = open(myfifo, O_WRONLY);
                        write(fd, field.c_str(), field.length() + 1);
                    }
                }
            } //if FD_ISSET
        } //for i to max_socket
    }//while(1)
    return 0;
}

bool clientIsRegistered(const RaceField &raceField,
                        int socketNumber) {
    return StringUtil::isSingleCapitalLetter(raceField.getCarName(socketNumber));
}

