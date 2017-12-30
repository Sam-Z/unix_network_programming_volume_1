#include "unp.h"
#include <time.h>

int main(int argc, char **argv)
{
    int listenfd, connfd;
    struct sockaddr_in servaddr;
    char buffer[MAXLINE];
    time_t ticks;

    listenfd = Socket(AF_INET, SOCK_STREAM, 0);

    bzero(&servaddr, sizeof(servaddr));
    servaddr.sin_family = AF_INET;
    servaddr.sin_addr.s_addr = htonl(INADDR_ANY);
    servaddr.sin_port        = htons(MY_DAY_TIME_SERVER_PORT);

    Bind(listenfd, (struct sockaddr *) &servaddr, sizeof(servaddr));

    Listen(listenfd, LISTENQ);

    for(;;){
        connfd = Accept(listenfd, (struct sockaddr *)NULL, NULL);

        ticks = time(NULL);

        snprintf(buffer, sizeof(buffer), "MY_DAY_TIME_SERVER:%s.24s\n", ctime(&ticks));

        Write(connfd, buffer, strlen(buffer));

        Close(connfd);
    }
}
