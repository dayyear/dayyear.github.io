## sqlite

1. 到页面`https://www.sqlite.org/download.html`

   - 下载`sqlite-amalgamation-3250300.zip`，解压至`D:\cpp\library\sqlite\src`
   - 下载`sqlite-dll-win32-x86-3250300.zip`，解压至`D:\cpp\library\sqlite\dll`

1. 编写测试程序

   > sqlite_test.cpp

   ```c++
   #include <stdio.h>
   #include <sqlite3.h>
   
   static int callback(void *NotUsed, int argc, char **argv, char **azColName){
     int i;
     for(i=0; i<argc; i++){
       printf("%s = %s\n", azColName[i], argv[i] ? argv[i] : "NULL");
     }
     printf("\n");
     return 0;
   }
   
   int main(int argc, char **argv){
     sqlite3 *db;
     char *zErrMsg = 0;
     int rc;
   
     if( argc!=3 ){
       fprintf(stderr, "Usage: %s DATABASE SQL-STATEMENT\n", argv[0]);
       return(1);
     }
     rc = sqlite3_open(argv[1], &db);
     if( rc ){
       fprintf(stderr, "Can't open database: %s\n", sqlite3_errmsg(db));
       sqlite3_close(db);
       return(1);
     }
     rc = sqlite3_exec(db, argv[2], callback, 0, &zErrMsg);
     if( rc!=SQLITE_OK ){
       fprintf(stderr, "SQL error: %s\n", zErrMsg);
       sqlite3_free(zErrMsg);
     }
     sqlite3_close(db);
     getchar();
     return 0;
   }
   ```

1. 编译、链接和运行
   
   - 方法1：将`sqlite3.dll`作为库文件链接`-lsqlite3`，运行时**需要**`sqlite3`的动态链接库`sqlite3.dll`，可参考[How to use dynamics sqlite library in c++ project & mingw?](https://stackoverflow.com/questions/45825320/how-to-use-dynamics-sqlite-library-in-c-project-mingw)
   
   ```bash
   g++ -std=c++11 -ID:\cpp\library\sqlite\src -O3 -Wall -c -fmessage-length=0 -o sqlite_test.o sqlite_test.cpp
   g++ -LD:\cpp\library\sqlite\dll -o sqlite_test.exe sqlite_test.o -lsqlite3
   set PATH=%PATH%;D:\cpp\library\sqlite\dll
   sqlite_test sxd.sqlite "select * from user"
   pause
   ```

   - 方法2：将`sqlite3.dll`作为目标文件链接，运行时**需要**`sqlite3`的动态链接库`sqlite3.dll`，可参考[How to use dynamics sqlite library in c++ project & mingw?](https://stackoverflow.com/questions/45825320/how-to-use-dynamics-sqlite-library-in-c-project-mingw)
   
   ```bash
   g++ -std=c++11 -ID:\cpp\library\sqlite\src -O3 -Wall -c -fmessage-length=0 -o sqlite_test.o sqlite_test.cpp
   g++  -o sqlite_test.exe sqlite_test.o D:\cpp\library\sqlite\dll\sqlite3.dll
   set PATH=%PATH%;D:\cpp\library\sqlite\dll
   sqlite_test sxd.sqlite "select * from user"
   pause
   ```

   - 方法3：利用`mingw32`自带的`sqlite3`库链接`-lsqlite3`(`mingw-7.3.0`版本和`mingw-8.1.0`版本的实际链接文件为`libsqlite3.a`，运行时**不需要**`sqlite3`的动态链接库；`mingw-7.2.0`版本的实际链接文件为`libsqlite3.dll.a`，运行时**需要**`sqlite3`的动态链接库`libsqlite3-0.dll`)，**推荐使用**
   
   ```bash
   g++ -std=c++11 -ID:\cpp\green\mingw32-8.1.0\opt\include -O3 -Wall -c -fmessage-length=0 -o sqlite_test.o sqlite_test.cpp
   g++ -LD:\cpp\green\mingw32-8.1.0\opt\lib -o sqlite_test.exe sqlite_test.o -lsqlite3
   sqlite_test sxd.sqlite "select * from user"
   pause
   ```


   
   
   