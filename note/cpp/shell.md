## shell

1. 编写测试程序
   
   > shell_test.cpp
   
   ```c++
   #include <cstring>  // strchr()
   #include <iostream> // std::cout, std::cerr
   #include <memory>   // std::shared_ptr
   #include <sstream>  // std::ostringstream
   
   void exec(const char* command) {
       const int BUFFER_SIZE = 8;
       char buffer[BUFFER_SIZE];
       std::ostringstream oss;
       std::shared_ptr<FILE> pipe(popen(command, "r"), pclose);
       if (!pipe)
           throw std::runtime_error("popen() failed!");
       while (fgets(buffer, BUFFER_SIZE, pipe.get())) {
           oss << buffer;
           int len = strlen(buffer);
           if (!len)
               throw std::runtime_error("strlen(buffer) == 0");
           if (buffer[len - 1] == '\n' || feof(pipe.get())) {
               std::cout << oss.str() << std::flush;
               oss.str("");
               continue;
           }
           if (len != BUFFER_SIZE - 1)
               throw std::runtime_error("strlen(buffer) != BUFFER_SIZE - 1");
       }
       if (ferror(pipe.get()))
           throw std::runtime_error("fgets() failed!");
   } //exec
   
   int main() {
       try {
           exec("dir");
       } catch (const std::exception& ex) {
           std::cerr << ex.what() << "\n";
           return 1;
       }
       return 0;
   } //main
   ```

1. 编译、链接
   
   ```bash
   g++ -std=c++11 -O3 -Wall -c -fmessage-length=0 -o shell_test.o shell_test.cpp 
   g++ -o shell_test.exe shell_test.o
   pause
   ```
