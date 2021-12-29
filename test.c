#include <stdio.h>
#include <sys/socket.h> 
#include <string.h>
#include <stdlib.h>
#include <arpa/inet.h>
#include "khook/engine.h"
#define VNI_HEAD_INT 17367553
#define VNI_HEAD_HEX 0x01090201
#define ETH_ALEN 6 //以太网地址长度
typedef struct ethhdr {
	unsigned char	h_dest[ETH_ALEN];	/* 目的地址	*/
	unsigned char	h_source[ETH_ALEN];	/* 源地址   */
	unsigned short	h_proto;            /* 类型：0x0800 IP数据报、0x0806 ARP请求/应答、0x8035 RARP请求/应答*/
} ETHHDR;

int main(){
    int a = 0x01020901;// 1921的大端表示，linux主机字节序和网络字节序都是大端有也即 1->9->2->1
    long b = 1921;
    char c[4] = {0};
    memcpy(c,&a,sizeof(a));
    printf("c[0]=%d,c[1]=%d,c[2]=%d,c[3]=%d\n",c[0],c[1],c[2],c[3]);
    htonl(a);
    memcpy(c,&a,sizeof(a));
    printf("转换为网络字序后:\n");
    printf("c[0]=%d,c[1]=%d,c[2]=%d,c[3]=%d\n",c[0],c[1],c[2],c[3]);
    ntohl(a);
    memcpy(c,&a,sizeof(a));
    printf("转换为主机字序后:\n");
    printf("c[0]=%d,c[1]=%d,c[2]=%d,c[3]=%d\n",c[0],c[1],c[2],c[3]);
    if(VNI_HEAD_HEX==VNI_HEAD_INT){
        printf("VNI_HEAD_HEX = VNI_HEAD_INT\n");
    }else{
        printf("VNI_HEAD_HEX != VNI_HEAD_INT\n");
    }
    printf("%d\n",sizeof(VNI_HEAD_HEX));
    printf("a=%d\n",a);
    printf("sizeof(int)=%d\n",sizeof(int));
    printf("sizeof(VNI_HEAD_HEX)=%d\n",a);

    printf("%d\n",sizeof(b));
    a++;
    return a;
}