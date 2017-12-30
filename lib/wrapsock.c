#include<sys/types.h>
#include<sys/socket.h>
#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
int Socket(int family, int type, int protocol)
{
    int n = 0;

    if ((n = socket(family, type, protocol)) < 0){
        printf("socket error!\n");
        exit(0);
    }

    return(n);
}


int Bind(int sockfd, const struct sockaddr *addr, socklen_t addrlen)
{
    int rtn = 0;
    
    if ( (rtn = bind(sockfd, addr, addrlen)) < 0){
        printf("bind error!\n");
        exit(0);
    }

    return(rtn);
}


int Listen(int sockfd, int backlog)
{
    int rtn = 0;

    if ( (rtn = listen(sockfd, backlog)) < 0){
        printf("listen error");
        exit(0);
    }

    return(rtn);
}

int Accept(int sockfd,  struct sockaddr * addr, socklen_t * len)
{
    int rtn = 0;

    if ((rtn = accept(sockfd, addr, len)) < 0){
        printf("accept error \n");
        exit(0);
    }
    
    return(rtn);
}

int Write(int sockfd, char *buffer, int len)
{
    int rtn = 0;

    if((rtn = write(sockfd, buffer, len))<0){
        printf("write error\n");
        exit(0);
    }

    return(rtn);
}

int Close(int sockfd)
{
    int rtn = 0;

    if((rtn = close(sockfd))<0){
        printf("close error\n");
        exit(0);
    }

    return(rtn);
}
