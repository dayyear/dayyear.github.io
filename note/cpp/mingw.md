## mingw
### install

1. [点击下载](https://sourceforge.net/projects/mingw-w64/files/Toolchains%20targetting%20Win32/Personal%20Builds/mingw-builds/7.2.0/threads-posix/dwarf/i686-7.2.0-release-posix-dwarf-rt_v5-rev1.7z/download)至`E:\CPP\down\i686-7.2.0-release-posix-dwarf-rt_v5-rev1.7z`

1. 解压` i686-7.2.0-release-posix-dwarf-rt_v5-rev1.7z`至`E:\CPP\green\mingw32-posix\`

1. `copy E:\CPP\green\mingw32-posix\bin\i686-w64-mingw32-gcc.exe E:\CPP\green\mingw32-posix\bin\mingw32-gcc.exe`

1. `PATH`中增加`E:\CPP\green\mingw32-posix\bin\; E:\CPP\green\mingw32-posix\opt\bin\;`

1. 编写测试程序
   > test.cpp
   
   ```c
   #include <ctime>
   #include <cstdlib>
   #include <iostream>
   
   int main() {
       /* use current time as seed for random generator */
       std::time_t now = std::time(NULL);
       std::cout << "now: " << now << "\n";
       std::srand(now);
       /* random sequence in [0, 1) */
       for (int i = 0; i < 10; i++)
           std::cout << std::rand() / (RAND_MAX + 1.0) << "\n";
       getchar();
       return 0;
   }
   ```

1. 编译、链接
   ```bash
   g++ -std=c++11 -O3 -Wall -fmessage-length=0 -o test.exe test.cpp
   ```

- x86_64 vs i686
   > - `x86_64`: Toolchains targetting Win64
   > - `i686`: Toolchains targetting Win32

- posix vs win32
   > https://stackoverflow.com/questions/13212342/whats-the-difference-between-thread-posixs-and-thread-win32-in-gcc-port-of-windo
   >
   > In short, for this version of mingw, the threads-posix release will use the posix API and **allow the use of std::thread**, and the threads-win32 will use the win32 API, and **disable the std::thread part of the standard**.

   > https://stackoverflow.com/questions/17242516/mingw-w64-threads-posix-vs-win32
   > - `posix`: enable C++11/C11 multithreading features. Makes libgcc depend on libwinpthreads, so that even if you don't directly call pthreads API, you'll be distributing the winpthreads DLL. There's nothing wrong with distributing one more DLL with your application.
   > - `win32`: No C++11 multithreading features.

- sjlj vs dwarf vs seh
   > - `sjlj`: setjmp/longjmp, available for 32 bit and 64 bit
   > - `dwarf`: DW2, dwarf-2, available for 32 bit only
   > - `seh`: zero overhead exception, available for 64 bit only
