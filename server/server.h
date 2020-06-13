//
// Created by extremer on 08.06.20.
//

#ifndef GRIDSERVER_SERVER_H
#define GRIDSERVER_SERVER_H

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

#endif //GRIDSERVER_SERVER_H
