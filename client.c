#include<stdio.h>
#include<string.h>      
#include<sys/socket.h>
#include<arpa/inet.h>  
#include<unistd.h>
#include<stdlib.h>
#define PORT 8080

int main(int argc, char const* argv[])
{
	int sock, clientsock;
	struct sockaddr_in server;
	char hostname[100], ip_address[100];
	
	//socket creation
	sock = socket(AF_INET ,SOCK_STREAM ,0);
	if (sock == -1)
	{
		printf("Socket failed to create \n");
		return 1;
	}
	//assign ip address of server and port	
	server.sin_addr.s_addr = inet_addr("192.168.202.5");
	server.sin_family = AF_INET;
	server.sin_port = htons(PORT);

	//Connect to server
	if ((clientsock = connect(sock, (struct sockaddr *)&server, sizeof(server))) < 0)
	{
		printf("Connection failed \n");
		return -1;
	}
	else
	{
		printf("Connected to server \n");
	}
	//Ask for domain name

		printf("Enter the domain name: \n ");
		scanf("%s",hostname);
		
		
		//Send domain to server
		if( send(sock ,hostname ,strlen(hostname) , 0) < 0)
		{
			printf("Failed to send data \n ");
			return -1;
		}
		else
		{
			printf("\n Data sent to server\n");
		}
		//Receive domain from server
		if(recv(sock, ip_address, 100, 0) < 0)
		{
			printf("Failed to receive data from server \n");
		}
		
		printf("IP address: ");
		puts(ip_address);
	    printf(" \n Thank you! \n ");
		 
		 //closing the socket
		 close(clientsock);
		 
	return 0;
}