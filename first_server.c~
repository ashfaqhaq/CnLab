#include<stdio.h>
#include<sys/types.h>
#include<sys/socket.h>
#include<netinet/in.h>
int main()
{ 
   int sockfd,newsockfd,client;
   struct sockaddr_in serv_addr,cli_addr;
   char a[50];
   sockfd=socket(AF_INET,SOCK_STREAM,0);
   if(sockfd<0)
   {
     printf("socket failed");
     return 0;
  }
serv_addr.sin_family=AF_INET;
 serv_addr.sin_addr.s_addr=inet_addr("192.168.200.150");
serv_addr.sin_port=htons(3500);
if(bind(sockfd,(struct sockaddr*)&serv_addr,sizeof(serv_addr))<0)
{
  printf(" bind failed");
  return 0;
}
if(listen(sockfd,5)<0)
 {
   printf("\n listen failed");
   return 0;
}
client=sizeof(cli_addr);
printf("\n waiting for client");
newsockfd=accept(sockfd,(struct sockaddr*)&cli_addr,&client);
read(newsockfd,a,50);
printf("\n server received:%s",a);
write(newsockfd,a,50);
close(newsockfd);
}

