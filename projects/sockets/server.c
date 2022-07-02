#include <stdio.h>
#include <sys/socket.h>
#include <sys/types.h>
#include <netinet/in.h>

void main()
{
    int server_socket; // used for creating socket
    int client_socket; // used for accepting connection
    struct sockaddr_in server_addr; // Structure required by the `bind()`
    char buffer[500] = "hello from server";
    char recv_buffer[500];

    server_socket = socket(AF_INET, SOCK_STREAM, 0);

    server_addr.sin_family = AF_INET; // Decalaring the type
    server_addr.sin_port = htons(9001); // Declaring the port number
    server_addr.sin_addr.s_addr = INADDR_ANY; // Declaring the host

    bind(server_socket, (struct server_addr*) &server_addr, sizeof(server_addr)); // Bind the server

    listen(server_socket, 5);

    while (client_socket = accept(server_socket, NULL, NULL))
    { 
        printf("Client connected \n");

        send(client_socket, buffer, sizeof(buffer), 0); 

        if(recv(client_socket, &recv_buffer, sizeof(recv_buffer), 0) > 0)
        {
            printf("Client has sent : %s \n", recv_buffer);

            // close(server_socket);
        }else
        {
            printf("Something went wrong\n");
        }

        printf("\n\n\n\n");
    }
}