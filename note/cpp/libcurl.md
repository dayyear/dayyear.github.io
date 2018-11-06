## libcurl
### install with ssl

1. [点击下载](https://curl.haxx.se/download/curl-7.61.1.zip)至`E:\CPP\down\curl-7.61.1.zip`，并解压至`E:\CPP\library\curl-7.61.1\`

1. [点击下载](https://bintray.com/vszakats/generic/download_file?file_path=openssl-1.1.1-win32-mingw.zip)至`E:\CPP\down\openssl-1.1.1_6-win32-mingw.zip`，并解压至`E:\CPP\library\openssl-1.1.1\`，参考`https://github.com/curl/curl-for-win`和`https://curl.haxx.se/windows/`

1. 设置环境变量，`set OPENSSL_PATH=E:/CPP/library/openssl-1.1.1`

1. 运行`E:\CPP\library\curl-7.61.1>mingw32-make mingw32-ssl >> make.txt`，将会在`lib`和`src`目录下分别产生库文件和可执行文件

1. 编写测试程序 

   > curl_test.cpp

   ```c
   #include <iostream>
   #include <fstream>
   #include <sstream>
   #include <curl/curl.h>
   
   static size_t write_callback(char *ptr, size_t size, size_t nmemb, void *userdata) {
       ((std::ostringstream *) userdata)->write((char*) ptr, size * nmemb);
       return size * nmemb;
   }
   
   int main(void) {
       /* Start a libcurl easy session */
       CURL* curl = curl_easy_init();
       if (curl) {
           /* provide the URL to use in the request */
           curl_easy_setopt(curl, CURLOPT_URL, "http://www.xd.com/");
           /* specify data to POST to server */
           // curl_easy_setopt(curl, CURLOPT_POSTFIELDS, "name=daniel&project=curl");
           /* verify the peer's SSL certificate */
           curl_easy_setopt(curl, CURLOPT_SSL_VERIFYPEER, 0L);
           /* follow HTTP 3xx redirects */
           curl_easy_setopt(curl, CURLOPT_FOLLOWLOCATION, 1L);
           /* set verbose mode on/off */
           curl_easy_setopt(curl, CURLOPT_VERBOSE, 1L);
           /* set callback for writing received data */
           curl_easy_setopt(curl, CURLOPT_WRITEFUNCTION, write_callback);
           /* pointer to pass to header callback */
           std::ostringstream oss_head;
           curl_easy_setopt(curl, CURLOPT_HEADERDATA, &oss_head);
           /* custom pointer passed to the write callback */
           std::ostringstream oss_body;
           curl_easy_setopt(curl, CURLOPT_WRITEDATA, &oss_body);
           /* perform a blocking file transfer */
           CURLcode res = curl_easy_perform(curl);
           if (res != CURLE_OK)
               std::cerr << curl_easy_strerror(res) << "\n";
           /* save response head and body to file */
           std::ofstream file("xd.html", std::ios::binary | std::ios::out);
           file << oss_head.str() << oss_body.str();
           file.close();
           /* End a libcurl easy handle */
           curl_easy_cleanup(curl);
       }
       getchar();
       return 0;
   }
   ```

1. 编译、链接
   ```bash
   /* 静态链接 */
   g++ -std=c++11 -DCURL_STATICLIB -IE:\\CPP\\library\\curl-7.61.1\\include -O3 -Wall -c -fmessage-length=0 -o curl_test_static.o curl_test.cpp
   g++ -static -o curl_test_static.exe curl_test_static.o -LE:\\CPP\\library\\curl-7.61.1\\lib -lcurl -LE:/CPP/library/openssl-1.1.1/lib -lssl -lcrypto -lwldap32 -lws2_32
   pause
   ```
   ```bash
   /* 动态链接(运行时需libcurl.dll、libcrypto-1_1.dll、libssl-1_1.dll，推荐) */
   g++ -std=c++11 -IE:\\CPP\\library\\curl-7.61.1\\include -O3 -Wall -c -fmessage-length=0 -o curl_test.o curl_test.cpp
   g++ -LE:\\CPP\\library\\curl-7.61.1\\lib -o curl_test.exe curl_test.o -lcurldll
   pause
   ```

- `-O3`: Optimize most.
- `-Wall`: All warnings.
- `-c`: Compile and assemble, but do not link.
- `-fmessage-length=n`: Try to format error messages so that they fit on lines of about n characters. The default is **72** characters for g++ and 0 for the rest of the front ends supported by GCC. **If n is zero, then no line-wrapping is done; each error message appears on a single line.**
- `-static`: On systems that support dynamic linking, this prevents linking with the shared libraries. On other systems, this option has no effect. 
