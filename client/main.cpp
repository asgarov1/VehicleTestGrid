#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <netdb.h>
#include <unistd.h>
#include <errno.h>

#define ISVALIDSOCKET(s) ((s) >= 0)
#define CLOSESOCKET(s) close(s)
#define SOCKET int
#define GETSOCKETERRNO() (errno)

#include <stdio.h>
#include <string.h>
#include <cctype>
#include <cstdlib>
#include <string>
#include <iostream>

#include "../SERVER_SETTINGS.h"

//#define PORT "8080"
//#define HOSTNAME "127.0.0.1"

bool isRegistered = false;

int main(int argc, char *argv[]) {
    if (argc < 2) {
        fprintf(stderr, "usage: vehicleclient CHAR\n");
        return 1;
    }

    //Configuring remote address
    struct addrinfo hints;
    memset(&hints, 0, sizeof(hints));
    hints.ai_socktype = SOCK_STREAM;
    struct addrinfo *peer_address;
    if (getaddrinfo(HOSTNAME, PORT, &hints, &peer_address)) {
        fprintf(stderr, "getaddrinfo() failed. (%d)\n", GETSOCKETERRNO());
        return 1;
    }


    //Remote address is
    char address_buffer[100];
    char service_buffer[100];
    getnameinfo(peer_address->ai_addr, peer_address->ai_addrlen,
                address_buffer, sizeof(address_buffer),
                service_buffer, sizeof(service_buffer),
                NI_NUMERICHOST);
//    printf("%s %s\n", address_buffer, service_buffer);


    //Creating socket
    SOCKET socket_peer;
    socket_peer = socket(peer_address->ai_family,
                         peer_address->ai_socktype, peer_address->ai_protocol);
    if (!ISVALIDSOCKET(socket_peer)) {
        fprintf(stderr, "socket() failed. (%d)\n", GETSOCKETERRNO());
        return 1;
    }


    //Connecting
    if (connect(socket_peer,
                peer_address->ai_addr, peer_address->ai_addrlen)) {
        fprintf(stderr, "connect() failed. (%d)\n", GETSOCKETERRNO());
        return 1;
    }
    freeaddrinfo(peer_address);

    //Connected
    while (1) {
        fd_set reads;
        FD_ZERO(&reads);
        FD_SET(socket_peer, &reads);
#if !defined(_WIN32)
        FD_SET(0, &reads);
#endif
        struct timeval timeout;
        timeout.tv_sec = 0;
        timeout.tv_usec = 100000;

        if (select(socket_peer + 1, &reads, 0, 0, &timeout) < 0) {
            fprintf(stderr, "select() failed. (%d)\n", GETSOCKETERRNO());
            return 1;
        }

        if (!isRegistered) {
            std::string carName = argv[1];
            send(socket_peer, carName.c_str(), carName.length(), 0);
        }

        if (FD_ISSET(socket_peer, &reads)) {
            char read[4096];
            int bytes_received = recv(socket_peer, read, 4096, 0);
            if (bytes_received < 1) {
                break;
            }
            if (std::string(read).find_first_of("Registration OK") != std::string::npos) {
                std::cout << std::string(read) << std::endl;
                isRegistered = true;
                memset(read, 0, sizeof(read));
            } else {
                printf("  %.*s",
                       bytes_received, read);
            }
        }


        if (FD_ISSET(0, &reads)) {
            char read[4096];
            if (!fgets(read, 4096, stdin)) break;
            send(socket_peer, read, strlen(read), 0);
        }
    } //end while(1)

    CLOSESOCKET(socket_peer);
    return 0;
}