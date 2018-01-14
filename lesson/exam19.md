### C++指针

```
int    *ip;    /* 一个整型的指针 */
double *dp;    /* 一个 double 型的指针 */
float  *fp;    /* 一个浮点型的指针 */
char   *ch;    /* 一个字符型的指针 */
```

&运算符访问的地址
```
#include <iostream>
 
using namespace std;
 
int main ()
{
   int  var1;
   char var2[10];
 
   cout << "var1 变量的地址： ";
   cout << &var1 << endl;
 
   cout << "var2 变量的地址： ";
   cout << &var2 << endl;
 
   return 0;
}
/*输出
var1 变量的地址： 002EFC64
var2 变量的地址： 002EFC68
*/
```

### C++ 中使用指针

```
#include <iostream>
 
using namespace std;
 
int main ()
{
   int  var = 20;   // 实际变量的声明
   int  *ip;        // 指针变量的声明
 
   ip = &var;       // 在指针变量中存储 var 的地址
 
   cout << "Value of var variable: ";
   cout << var << endl;
 
   // 输出在指针变量中存储的地址
   cout << "Address stored in ip variable: ";
   cout << ip << endl;
 
   // 访问指针中地址的值
   cout << "Value of *ip variable: ";
   cout << *ip << endl;
 
   return 0;
}
/*输出
Value of var variable: 20
Address stored in ip variable: 001CF9D4
Value of *ip variable: 20
*/
```

### C++ 指针详解

概念 | 描述
---- | ----
C++ Null 指针 | C++ 支持空指针。NULL 指针是一个定义在标准库中的值为零的常量。
C++ 指针的算术运算 | 可以对指针进行四种算术运算：++、--、+、-
C++ 指针 vs 数组 | 指针和数组之间有着密切的关系。
C++ 指针数组 | 可以定义用来存储指针的数组。
C++ 指向指针的指针 | C++ 允许指向指针的指针。
C++ 传递指针给函数 | 通过引用或地址传递参数，使传递的参数在调用函数中被改变。
C++ 从函数返回指针 | C++ 允许函数返回指针到局部变量、静态变量和动态内存分配。

### C++ Null 指针

```
#include <iostream>

using namespace std;

int main ()
{
   int  *ptr = NULL;

   cout << "ptr 的值是 " << ptr << endl;
 
   return 0;
}
/*输出
ptr 的值是 00000000
*/
```

```
if(ptr)     /* 如果 ptr 非空，则... */
if(!ptr)    /* 如果 ptr 为空，则... */
```

### C++ 指针的算术运算

- 递增一个指针

```
#include <iostream>

using namespace std;
const int MAX = 3;

int main ()
{
   int  var[MAX] = {10, 100, 200};
   int  *ptr;

   // 指针中的数组地址
   ptr = var;
   for (int i = 0; i < MAX; i++)
   {
      cout << "Address of var[" << i << "] = ";
      cout << ptr << endl;

      cout << "Value of var[" << i << "] = ";
      cout << *ptr << endl;

      // 移动到下一个位置
      ptr++;
   }
   return 0;
}
/*输出
Address of var[0] = 0046FED0
Value of var[0] = 10
Address of var[1] = 0046FED4
Value of var[1] = 100
Address of var[2] = 0046FED8
Value of var[2] = 200
*/
```

- 递减一个指针

```
#include <iostream>

using namespace std;
const int MAX = 3;

int main ()
{
   int  var[MAX] = {10, 100, 200};
   int  *ptr;

   // 指针中最后一个元素的地址
   ptr = &var[MAX-1];
   for (int i = MAX; i > 0; i--)
   {
      cout << "Address of var[" << i << "] = ";
      cout << ptr << endl;

      cout << "Value of var[" << i << "] = ";
      cout << *ptr << endl;

      // 移动到下一个位置
      ptr--;
   }
   return 0;
}
/*输出
Address of var[3] = 0041F7A0
Value of var[3] = 200
Address of var[2] = 0041F79C
Value of var[2] = 100
Address of var[1] = 0041F798
Value of var[1] = 10
*/
```

- 指针的比较

```
#include <iostream>

using namespace std;
const int MAX = 3;

int main ()
{
   int  var[MAX] = {10, 100, 200};
   int  *ptr;

   // 指针中第一个元素的地址
   ptr = var;
   int i = 0;
   while ( ptr <= &var[MAX - 1] )
   {
      cout << "Address of var[" << i << "] = ";
      cout << ptr << endl;

      cout << "Value of var[" << i << "] = ";
      cout << *ptr << endl;

      // 指向上一个位置
      ptr++;
      i++;
   }
   return 0;
}
/*输出
Address of var[0] = 0018FDE8
Value of var[0] = 10
Address of var[1] = 0018FDEC
Value of var[1] = 100
Address of var[2] = 0018FDF0
Value of var[2] = 200
*/
```

### C++ 指针 vs 数组

```
#include <iostream>
 
using namespace std;
const int MAX = 3;
 
int main ()
{
   int  var[MAX] = {10, 100, 200};
   int  *ptr;
 
   // 指针中的数组地址
   ptr = var;
   for (int i = 0; i < MAX; i++)
   {
      cout << "var[" << i << "]的内存地址为 ";
      cout << ptr << endl;
 
      cout << "var[" << i << "] 的值为 ";
      cout << *ptr << endl;
 
      // 移动到下一个位置
      ptr++;
   }
   return 0;
}
/*输出
var[0]的内存地址为 0043FC88
var[0] 的值为 10
var[1]的内存地址为 0043FC8C
var[1] 的值为 100
var[2]的内存地址为 0043FC90
var[2] 的值为 200
*/
```

**然而，指针和数组并不是完全互换的。**

```
#include <iostream>
 
using namespace std;
const int MAX = 3;
 
int main ()
{
   int  var[MAX] = {10, 100, 200};
 
   for (int i = 0; i < MAX; i++)
   {
      *var = i;      // 这是正确的语法
      var++;         // 这是不正确的
   }
   *(var + 2) = 500; // 这是正确的语法
   return 0;
}
```

### C++ 指针数组

```
#include <iostream>
 
using namespace std;
const int MAX = 3;
 
int main ()
{
   int  var[MAX] = {10, 100, 200};
   int *ptr[MAX];
 
   for (int i = 0; i < MAX; i++)
   {
      ptr[i] = &var[i]; // 赋值为整数的地址
   }
   for (int i = 0; i < MAX; i++)
   {
      cout << "Value of var[" << i << "] = ";
      cout << *ptr[i] << endl;
   }
   return 0;
}
/*输出
Value of var[0] = 10
Value of var[1] = 100
Value of var[2] = 200
*/
```

```
#include <iostream>
using namespace std;

const int MAX = 4;

int main(int argc, const char * argv[]) {

    const char *names[MAX] = {
        "Zara Ali",
        "Hina Ali",
        "Nuha Ali",
        "Sara Ali",
    };

    for (int i = 0; i < MAX; i++) {
        cout << " --- names[i]              = " << names[i] << endl;
        cout << " --- *names[i]             = " << *names[i] << endl;
        cout << endl;
        cout << " --- (*names[i] + 1)       = " << (*names[i] + 1) << endl;
        cout << " --- (char)(*names[i] + 1) = " << (char)(*names[i] + 1) << endl;
        cout << " ------------------------------------ " << endl;
    }
    return 0;
}
/*输出
 --- names[i]              = Zara Ali
 --- *names[i]             = Z

 --- (*names[i] + 1)       = 91
 --- (char)(*names[i] + 1) = [
 ------------------------------------
 --- names[i]              = Hina Ali
 --- *names[i]             = H

 --- (*names[i] + 1)       = 73
 --- (char)(*names[i] + 1) = I
 ------------------------------------
 --- names[i]              = Nuha Ali
 --- *names[i]             = N

 --- (*names[i] + 1)       = 79
 --- (char)(*names[i] + 1) = O
 ------------------------------------
 --- names[i]              = Sara Ali
 --- *names[i]             = S

 --- (*names[i] + 1)       = 84
 --- (char)(*names[i] + 1) = T
 ------------------------------------
*/
```

### C++ 指向指针的指针（多级间接寻址）

```
#include <iostream>
 
using namespace std;
 
int main ()
{
   int  var;
   int  *ptr;
   int  **pptr;

   var = 3000;

   // 获取 var 的地址
   ptr = &var;

   // 使用运算符 & 获取 ptr 的地址
   pptr = &ptr;

   // 使用 pptr 获取值
   cout << "Value of var :" << var << endl;
   cout << "Value available at *ptr :" << *ptr << endl;
   cout << "Value available at **pptr :" << **pptr << endl;

   return 0;
}
/*输出
Value of var :3000
Value available at *ptr :3000
Value available at **pptr :3000
*/
```

### C++ 传递指针给函数

```
#include <iostream>
#include <ctime>
 
using namespace std;
void getSeconds(unsigned long *par);

int main ()
{
   unsigned long sec;


   getSeconds( &sec );

   // 输出实际值
   cout << "Number of seconds :" << sec << endl;

   return 0;
}

void getSeconds(unsigned long *par)
{
   // 获取当前的秒数
   *par = time( NULL );
   return;
}
/*输出
Number of seconds :1515898881
*/
```

复习以前的例子

```
#include <iostream>
using namespace std;
 
// 函数声明
double getAverage(int *arr, int size);
 
int main ()
{
   // 带有 5 个元素的整型数组
   int balance[5] = {1000, 2, 3, 17, 50};
   double avg;
 
   // 传递一个指向数组的指针作为参数
   avg = getAverage( balance, 5 ) ;
 
   // 输出返回值
   cout << "Average value is: " << avg << endl; 
    
   return 0;
}

double getAverage(int *arr, int size)
{
  int    i, sum = 0;       
  double avg;          
 
  for (i = 0; i < size; ++i)
  {
    sum += arr[i];
   }
 
  avg = double(sum) / size;
 
  return avg;
}
```

### C++ 从函数返回指针

复习以前的例子

```
#include <iostream>
#include <ctime>
#include <cstdlib>
 
using namespace std;
 
// 要生成和返回随机数的函数
int * getRandom( )
{
  static int  r[10];
 
  // 设置种子
  srand( (unsigned)time( NULL ) );
  for (int i = 0; i < 10; ++i)
  {
    r[i] = rand();
    cout << r[i] << endl;
  }
 
  return r;
}
 
// 要调用上面定义函数的主函数
int main ()
{
   // 一个指向整数的指针
   int *p;
 
   p = getRandom();
   for ( int i = 0; i < 10; i++ )
   {
       cout << "*(p + " << i << ") : ";
       cout << *(p + i) << endl;
   }
 
   return 0;
}
```