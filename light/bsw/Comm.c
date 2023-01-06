#include <arpa/inet.h>
#include <stdio.h>
#include <string.h>
#include <sys/socket.h>
#include <unistd.h>

#define PORT 8000
#define MAX_DATA 10

typedef struct 
{
	int server_fd;
	struct sockaddr_in address;
	char buffer[MAX_DATA];
}Comm_MainStruct;

/////////////////////////////////////////////
// Global variables
/////////////////////////////////////////////
Comm_MainStruct g_CommMainStruct;

/////////////////////////////////////////////
// Functions definitions
/////////////////////////////////////////////
int Comm_init()
{
    int opt = 1;
 
    // Creating socket file descriptor
    if ((g_CommMainStruct.server_fd = socket(AF_INET, SOCK_STREAM, 0)) < 0) 
	{
        perror("socket failed");
        return -1;
    }
 
    // Forcefully attaching socket to the port 8080
    if (setsockopt(g_CommMainStruct.server_fd, SOL_SOCKET,SO_REUSEADDR | SO_REUSEPORT, &opt, sizeof(opt))) 
	{
        perror("setsockopt");
        return -1;
    }
    g_CommMainStruct.address.sin_family = AF_INET;
    g_CommMainStruct.address.sin_addr.s_addr = INADDR_ANY;
    g_CommMainStruct.address.sin_port = htons(PORT);
 
    // Forcefully attaching socket to the port 8080
    if (bind(g_CommMainStruct.server_fd, (struct sockaddr*)&(g_CommMainStruct.address), sizeof(g_CommMainStruct.address))< 0) 
	{
        perror("bind failed");
        return -1;
    }
    if (listen(g_CommMainStruct.server_fd, 3) < 0) 
	{
        perror("listen");
        return -1;
    }

	return 0;
}

char Comm_receive()
{
	int socket;
	int addrlen;
	int ret;
    if ((socket= accept(g_CommMainStruct.server_fd, (struct sockaddr*)&g_CommMainStruct.address,(socklen_t*)&addrlen))< 0) 
	{
        perror("accept");
		return -1;
    }

    ret = read(socket, g_CommMainStruct.buffer, MAX_DATA);

    // closing the connected socket
    close(socket);

	return g_CommMainStruct.buffer[0];
}