//
// Created by extremer on 14.06.20.
//

#ifndef GRIDDISPLAY_SERVER_H
#define GRIDDISPLAY_SERVER_H

#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <netdb.h>
#include <unistd.h>
#include <errno.h>
#include <stdio.h>
#include <string.h>
#include <cctype>
#include <cstdlib>
#include <iostream>
#include <vector>
#include "RaceField.h"
#include "StringUtil.h"

#define ISVALIDSOCKET(s) ((s) >= 0)
#define CLOSESOCKET(s) close(s)
#define SOCKET int
#define GETSOCKETERRNO() (errno)

class Server {

    struct addrinfo hints{};
    SOCKET socket_listen;
    fd_set master;
    SOCKET max_socket;

public:
    virtual ~Server();

public:
    Server();

    void initialiseServer();

    //Getters
    [[nodiscard]] const addrinfo &getHints() const;
    [[nodiscard]] int getSocketListen() const;
    const fd_set & getMaster() const;
    [[nodiscard]] int getMaxSocket() const;

    void setMaxSocket(int maxSocket);

    void fdSetWithMaster(int socketClient);

    void disconnectClient(int socketNumber);
};


#endif //GRIDDISPLAY_SERVER_H
