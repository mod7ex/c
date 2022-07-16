#include <stdio.h>
#include <sys/socket.h>
#include <sys/types.h>
#include <netinet/in.h>

#define PORT 8080

void main()
{
    char buffer[] = "hello from server";
    char recv_buffer[512];

    int client_socket; // used for accepting connection
    int server_socket = socket(AF_INET, SOCK_STREAM, 0);  // creating socket

    struct sockaddr_in server_addr; // Structure required by the `bind()`

    server_addr.sin_family = AF_INET; // Decalaring the type
    server_addr.sin_port = htons(PORT); // Declaring the port number
    server_addr.sin_addr.s_addr = INADDR_ANY; // Declaring the host

    bind(server_socket, (struct server_addr*) &server_addr, sizeof(server_addr)); // Bind the server

    if(listen(server_socket, 5) > 0) 
    {
        printf("Server listening on port %d... \n", PORT);

        while (client_socket = accept(server_socket, NULL, NULL))
        {
            printf("Client connected \n");

            send(client_socket, buffer, sizeof(buffer), 0); 

            if(recv(client_socket, &recv_buffer, sizeof(recv_buffer), 0) > 0)
            {
                printf("Client has sent : %s \n", recv_buffer);
            }
            
            else
            {
                printf("Something went wrong\n");
                close(server_socket);
            }

            printf("\n\n\n\n");
        }
    }
    else
    {
        printf("Something went wrong\n");
        exit(1);
    }

}