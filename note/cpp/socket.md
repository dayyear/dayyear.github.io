## socket

### hello world

1. 编写测试程序

   > socket_test.cpp

   ```c++
   #include <winsock2.h>
   #include <fstream>
   
   #define RCVBUFSIZE 16
   
   int main(void) {
       WSADATA wsadata;
       WSAStartup(WINSOCK_VERSION, &wsadata);
   
       const char* host = "sxd.xd.com";
   
       struct hostent *hostent;
       if ((hostent = gethostbyname(host)) == NULL)
           return 1;
   
       unsigned short port = 80;
       struct sockaddr_in addr;
       memset(&addr, 0, sizeof(sockaddr));
       addr.sin_family = AF_INET;
       addr.sin_addr.s_addr = *((unsigned long*) hostent->h_addr_list[0]);
       addr.sin_port = htons(port);
   
       int sock = socket(PF_INET, SOCK_STREAM, IPPROTO_TCP);
   
       if (connect(sock, (struct sockaddr *) &addr, sizeof(addr)) < 0)
           return 2;
   
       const char* msg = "GET / HTTP/1.1\r\nHost: sxd.xd.com\r\nConnection: close\r\n\r\n";
       if (send(sock, msg, strlen(msg), 0) != (int) strlen(msg))
           return 3;
   
       std::ofstream file("sxd.html", std::ios::binary | std::ios::out);
       char buffer[RCVBUFSIZE];
       int bytesRcvd;
       for (;;) {
           bytesRcvd = recv(sock, buffer, RCVBUFSIZE - 1, 0);
           if (bytesRcvd == 0)
               break;
           if (bytesRcvd < 0)
               return 4;
           buffer[bytesRcvd] = '\0';
           file << buffer;
       }
       file.close();
       
       closesocket(sock);
   
       WSACleanup();
       getchar();
       return 0;
   }
   ```

1. 编译、链接
   ```bash
   g++ -std=c++11 -O3 -Wall -c -fmessage-length=0 -o socket_test.o socket_test.cpp 
   g++ -o socket_test.exe socket_test.o -lws2_32 
   pause
   ```

1. 运行

   > sxd.html

   ```http
   HTTP/1.1 200 OK
   Date: Wed, 03 Oct 2018 13:00:07 GMT
   Content-Type: text/html; charset=UTF-8
   Transfer-Encoding: chunked
   Connection: close
   Set-Cookie: aliyungf_tc=AQAAAGXIp2QfkQEAV8R5tDH2FzNAfsW9; Path=/; HttpOnly
   Cache-Control: max-age=3, must-revalidate
   WP-Super-Cache: Served supercache file from PHP
   
   323d
   <!DOCTYPE html>
   <html dir="ltr" lang="zh-CN">
   ...
   ```
