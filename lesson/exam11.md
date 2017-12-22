### Hello world
```
#include <iostream>
using namespace std;

int main() {
   cout << "Hello world";
   return 0;
}
// cl /c hello.cpp
// link hello.obj
```

### Hello world with windows
```
#include "windows.h"  
int APIENTRY wWinMain(_In_ HINSTANCE hInstance,    
                     _In_opt_ HINSTANCE hPrevInstance,    
                     _In_ LPWSTR    lpCmdLine,    
                     _In_ int       nCmdShow)     
{  
  MessageBox(NULL, "Hello world", "Windows", MB_ABORTRETRYIGNORE|MB_ICONERROR);  
  return 0;  
} 
// cl /c hello.cpp
// link hello.obj user32.lib
```

### 基本数据类型
```
#include <iostream>
using namespace std;

int main() {
   cout << "Size of char : " << sizeof(char) << endl;
   cout << "Size of int : " << sizeof(int) << endl;
   cout << "Size of short int : " << sizeof(short int) << endl;
   cout << "Size of long int : " << sizeof(long int) << endl;
   cout << "Size of float : " << sizeof(float) << endl;
   cout << "Size of double : " << sizeof(double) << endl;
   cout << "Size of wchar_t : " << sizeof(wchar_t) << endl;
   
   return 0;
}
```

### 局部变量的声明与使用
```
#include <iostream>
using namespace std;

int main () {
   // Variable definition:
   int a, b;
   int c;
   float f;
 
   // actual initialization
   a = 10;
   b = 20;
   c = a + b;
 
   cout << c << endl ;

   f = 70.0/3.0;
   cout << f << endl ;
 
   return 0;
}
```

### 全局变量的声明与使用
```
#include <iostream>
using namespace std;
 
// Global variable declaration:
int g;
 
int main () {
   // Local variable declaration:
   int a, b;
 
   // actual initialization
   a = 10;
   b = 20;
   g = a + b;
  
   cout << g;
 
   return 0;
}
```

### const
```
#include <iostream>
using namespace std;

int main() {
   const int  LENGTH = 10;
   const int  WIDTH  = 5;
   const char NEWLINE = '\n';
   int area;  
   
   area = LENGTH * WIDTH;
   cout << area;
   cout << NEWLINE;
   return 0;
}
```

### 变量类型转换
```
#include <iostream>
using namespace std;
 
/* This program shows the difference between
   * signed and unsigned integers.
*/
int main() {
   short int i;           // a signed short integer
   short unsigned int j;  // an unsigned short integer

   j = 50000;

   i = j;
   cout << i << " " << j;

   return 0;
}
```