#include <arpa/inet.h>
#include <stdio.h>
#include <string.h>
#include <sys/socket.h>
#include <unistd.h>

#define PORT 8000
#define MAX_DATA 10

int Comm_send(char data)
{
    int sock = 0;
	struct sockaddr_in serv_addr;
	char tx_data[MAX_DATA];

    memset(tx_data, '0', MAX_DATA);
    tx_data[0] = data;

	if ((sock = socket(AF_INET, SOCK_STREAM, 0)) < 0) {
		printf("\n Socket creation error \n");
		return -1;
	}

	serv_addr.sin_family = AF_INET;
	serv_addr.sin_port = htons(PORT);

	// Convert IPv4 and IPv6 addresses from text to binary form
	if (inet_pton(AF_INET, "127.0.0.1", &serv_addr.sin_addr)<= 0) 
    {
		printf("\nInvalid address/ Address not supported \n");
		return -1;
	}

	if ( connect(sock, (struct sockaddr*)&serv_addr,sizeof(serv_addr))< 0) 
    {
		printf("\nConnection Failed \n");
		return -1;
	}

	send(sock, tx_data, sizeof(tx_data), 0);

	// closing the connected socket
	close(sock);

	return 0;
}