#include<stdio.h>
//#include<stdlib.h>
#include<sys/types.h>
#include<sys/socket.h>
#include<netinet/in.h>
int main()
{
	int sockfd;
	struct sockaddr_in serv_addr;
	char a[50],a1[50];
	sockfd=socket(AF_INET,SOCK_STREAM,0);
	if(sockfd<0)
	{
		printf("\n Socket failed\n");
		//exit(0);
	}
	serv_addr.sin_family=AF_INET;
	serv_addr.sin_addr.s_addr=inet_addr("192.168.200.150");
	serv_addr.sin_port=htons(3500);
	if(connect(sockfd,(struct sockaddr *)&serv_addr,sizeof(serv_addr))<0)
	{
		printf("\nConnection failed\n");
		//exit(0);
	}
	printf("\ENter the msg : \n");
	scanf("%s",a);
	write(sockfd,a,50);
	read(sockfd,a1,50);
	printf("\n client received the message %s",a1);
	close(sockfd);
	}

