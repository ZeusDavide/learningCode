#include "tool.h"
#include <netinet/in.h>
#include <arpa/inet.h>
// socket
#include <sys/types.h>
#include <sys/socket.h>

#include <string.h>


namespace Tool{

    unsigned long int host2Netlong(unsigned long int hostlong){
        return htonl(hostlong);
    }
    unsigned short int host2NetShort(unsigned short int hostshort){
        return htons(hostshort);
    }
    unsigned long int net2Hostlong(unsigned long int netlong){
        return ntohl(netlong);
    }
    unsigned short int net2HostShort(unsigned short int netshort){
        return ntohs(netshort);
    }

    bool isBig(){
        // 匿名联合体
        union{
            short value;
            char union_bytes[sizeof(short)];
        } test;
        test.value = 0x0102;
        if((test.union_bytes[0]==1)&&(test.union_bytes[1]==2)){
            return true;
        }else{
            return false;
        }
    // short
    //  01  [1]
    //  02  [0]
    // 数据大端  数据的低位保存在内存的高地址中
    }

    int tcp_socket(){
        return socket(PF_INET,SOCK_STREAM,0);
    }
    int udp_socket(){
        return socket(PF_INET,SOCK_DGRAM,0);
    }

    int socketBind(int sockfd,const char * ip,int port){
        struct sockaddr_in address;
        bzero(&address,sizeof(address));
        address.sin_family = AF_INET;
        inet_pton(AF_INET,ip,&address.sin_addr);
        address.sin_port = htons(port);

        return bind(sockfd,(struct sockaddr*)&address,sizeof(address));
    }

}