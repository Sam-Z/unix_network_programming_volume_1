#include"unp.h"

int main(int argc, char **argv)
{
    // 1. 参数校验
    if (argc != 2){
        err_quit("usage: a.out <IPaddress>\n");
        exit(0);
    }

    // 2. 建立socket
    int sockfd = 0;
    if ( (sockfd = socket(AF_INET, SOCK_STREAM, 0)) < 0){
        err_sys("socket error!\n");
        exit(0);
    }

    // 3. 建立连接
    struct sockaddr_in  addr;
    memset(&addr, 0, sizeof(addr));
    addr.sin_family = AF_INET;
    addr.sin_port   = htons(MY_DAY_TIME_SERVER_PORT);
    if (inet_pton(AF_INET, argv[1], &addr.sin_addr) < 0){
        err_quit("inet_pton error for %s\n", argv[1]);
        exit(0); 
    }
    if ( connect(sockfd, (struct sockaddr *) &addr, sizeof(addr)) < 0){
        err_sys("connect error!\n");
        exit(0); 
    }

    // 4. 读取数据
    char recvline[MAXLINE+1];
    int n = 0;
    while( (n = read(sockfd, recvline, MAXLINE)) > 0 ){
        recvline [n] = 0;
        printf("%s\n", recvline);
    }

    if (n<0){
        err_sys("read error!\n");
    }

    exit(0);
}
