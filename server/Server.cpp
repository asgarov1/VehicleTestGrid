//
// Created by extremer on 14.06.20.
//

#include "Server.h"
#include "../SERVER_SETTINGS.h"

Server::Server() {
    initialiseServer();
}

void Server::initialiseServer() {
//Configuring local address
    memset(&hints, 0, sizeof(hints));
    hints.ai_family = AF_INET;
    hints.ai_socktype = SOCK_STREAM;
    hints.ai_flags = AI_PASSIVE;

    struct addrinfo *bind_address;
    getaddrinfo(nullptr, PORT, &hints, &bind_address);


    //Creating socket
    socket_listen = socket(bind_address->ai_family,
                           bind_address->ai_socktype, bind_address->ai_protocol);
    if (!ISVALIDSOCKET(socket_listen)) {
        fprintf(stderr, "socket() failed. (%d)\n", GETSOCKETERRNO());
        exit(1);
    }

    //By default Kernel still holds resources for a few seconds so you can't immediately restart program due to binding problems
    //Setting of SO_REUSEADDR solves the issue
    int myTrue = 1;
    setsockopt(socket_listen,SOL_SOCKET,SO_REUSEADDR,&myTrue,sizeof(int));

    //Binding socket to local address
    if (bind(socket_listen,
             bind_address->ai_addr, bind_address->ai_addrlen)) {
        fprintf(stderr, "bind() failed. (%d)", GETSOCKETERRNO());
        exit(1);
    }
    freeaddrinfo(bind_address);


    //Listening
    if (listen(socket_listen, 10) < 0) {
        fprintf(stderr, "listen() failed. (%d)\n", GETSOCKETERRNO());
        exit(1);
    }

    FD_ZERO(&master);
    FD_SET(socket_listen, &master);
    max_socket = socket_listen;
}

Server::~Server() {
    CLOSESOCKET(socket_listen);
}

const addrinfo &Server::getHints() const {
    return hints;
}

int Server::getSocketListen() const {
    return socket_listen;
}

const fd_set & Server::getMaster() const {
    return master;
}

int Server::getMaxSocket() const {
    return max_socket;
}

void Server::setMaxSocket(int maxSocket) {
    max_socket = maxSocket;
}

void Server::fdSetWithMaster(int socketClient) {
    FD_SET(socketClient, &master);
}

void Server::disconnectClient(int socketNumber) {
    FD_CLR(socketNumber, &master);
    CLOSESOCKET(socketNumber);
}
