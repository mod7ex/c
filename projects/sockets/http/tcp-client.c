#include <sys/socket.h>
#include <sys/types.h>
#include <sys/time.h>
#include <sys/ioctl.h>
#include <signal.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <arpa/inet.h>
#include <stdarg.h>
#include <errno.h>
#include <fcntl.h>
#include <netdb.h>

#define SERVER_PORT 80 // standard HTTP port

#define MAXLINE 4096 // size of the buffer for reading data

#define SA struct sockaddr

void err_n_die(const char *fmt, ...);

void main(int argc, char **argv)
{
    int sock_fd, rcv_bytes, client_fd;

    struct sockaddr_in server_addr;

    char sendline[MAXLINE];
    char recvline[MAXLINE];

    if(argc < 2) err_n_die("usage: > %s <server address>", argv[0]); // usage check !

    if((sock_fd = socket(AF_INET, SOCK_STREAM, 0)) < 0) 
    {
        // AF_INET (address family internet)
        // 0 for TCP
        err_n_die("Error while creating the socket !");
    }

    bzero(&server_addr, sizeof(server_addr)); // zero out the bytes
    server_addr.sin_family = AF_INET;
    server_addr.sin_port = htons(SERVER_PORT); /* htons (host to network, short [network standard byte order]) Chat server */

    if(inet_pton(AF_INET, argv[1], &server_addr.sin_addr) <= 0)
    {
        /* inet_pton (port to network [network standard byte order]) */
        err_n_die("inet_pton error for %s", argv[1]);
    }

    if((client_fd = connect(sock_fd, (SA *) &server_addr, sizeof(server_addr))) < 0)
    {
        err_n_die("connection faild !");
    }

    // We are connected. prepare the message
    sprintf(sendline, "GET / HTTP/1.1\r\n\r\n");

    /*
        send the request --making sure you send it all
        this code is a bit fragile, since it bails if only some of the bytes are sent

        --> normally, you want to retry , unless the return value was -1;
    */

    memset(recvline, 0, MAXLINE);

    // send the message to server in order to get a responce
    send(sock_fd, sendline, strlen(sendline), 0);

    // Now read the server's responce
    while ((rcv_bytes = read(sock_fd, recvline, MAXLINE-1))>0)
    {
        printf("\n--------------------------\n\n");
        printf("--> %s", recvline);
        printf("\n--------------------------\n");
    }

    if(rcv_bytes<0) err_n_die("read error");

    close(client_fd); // closing the connected socket
    exit(0); // end successfully
}

void err_n_die(const char *fmt, ...)
{
    int errno_save;
    va_list ap;

    // any system or library call can set errno, so we need to save it now
    errno_save = errno;

    // print out the fmt+args to standard out
    va_start(ap, fmt);
    vfprintf(stdout, fmt, ap);
    fprintf(stdout, "\n");
    fflush(stdout);

    // print out error message if errno was set
    if(errno_save != 0)
    {
        fprintf(stdout, "(errno = %d) : %s \n", errno_save, strerror(errno_save));
        fprintf(stdout, "\n");
        fflush(stdout);
    }

    va_end(ap);

    // this is the ..and_die part. terminate with an error.
    exit(1);
}