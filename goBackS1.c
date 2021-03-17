#include<stdio.h>
#include<stdlib.h>

#include<sys/types.h>
#include<sys/socket.h>

#include<netinet/in.h>
#include<unistd.h>

#include<string.h>

int main()
{
int fid=socket(AF_INET,SOCK_STREAM,0);
if(fid==0)
printf("\n Error creating socket ");

struct sockaddr_in server_address;
server_address.sin_family=AF_INET;
server_address.sin_port=htons(9090);
server_address.sin_addr.s_addr=INADDR_ANY;

if(bind(fid,(struct sockaddr *)&server_address, sizeof(server_address))<0)
printf("\n Error binding ");

if(listen(fid,5)<0)
printf("\n Error listening ");

int client_fid=accept(fid,NULL,NULL);
if(client_fid<0)
printf("\n Error accepting ");

int ack, val;
while(1)
{
read(client_fid,&val,sizeof(val));
memset(&val,'\0',sizeof(val));

printf("\n Received Till : ");
scanf("%d", &ack);

send(client_fid,&ack,sizeof(ack),0);
if(ack==15)
break;
memset(&ack,'\0',sizeof(ack));
}

return 0;
}

