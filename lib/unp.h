#ifndef __UNP_H
#define __UNP_H


#include <sys/types.h>
#include <sys/socket.h>
#include <sys/time.h>
#include <arpa/inet.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>

#define MAXLINE (256)
#define LISTENQ (1024)
#define MY_DAY_TIME_SERVER_PORT (45000)

int Socket(int family, int type, int protocol);
int Bind(int sockfd, const struct sockaddr *addr, socklen_t  addrlen);
int Listen(int sockfd, int backlog);
int Accept(int sockfd, struct sockaddr *addr, socklen_t *len);
int Write(int sockfd, char *buffer, int len);
int Close(int sockfd);

#endif
