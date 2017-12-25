### register 存储类
- register 存储类用于定义存储在寄存器中而不是 RAM 中的局部变量。这意味着变量的最大尺寸等于寄存器的大小（通常是一个词），且不能对它应用一元的 '&' 运算符（因为它没有内存位置）。
- 寄存器只用于需要快速访问的变量，比如计数器。
```
register int  miles;
```

### static 存储类
1. static 存储类指示编译器在程序的生命周期内保持局部变量的存在，而不需要在每次它进入和离开作用域时进行创建和销毁。因此，使用 static 修饰局部变量可以在函数调用之间保持局部变量的值。
2. static 修饰符也可以应用于全局变量。当 static 修饰全局变量时，会使变量的作用域限制在声明它的文件内。
3. 在 C++ 中，当 static 用在类数据成员上时，会导致仅有一个该成员的副本被类的所有对象共享。
```
#include <iostream>
 
// 函数声明 
void func(void);
 
static int count = 10; /* 全局变量 */
 
int main()
{
    while(count--)
    {
       func();
    }
    return 0;
}
// 函数定义
void func( void )
{
    static int i = 5; // 局部静态变量
    i++;
    std::cout << "变量 i 为 " << i ;
    std::cout << " , 变量 count 为 " << count << std::endl;
}
/*输出
变量 i 为 6 , 变量 count 为 9
变量 i 为 7 , 变量 count 为 8
变量 i 为 8 , 变量 count 为 7
变量 i 为 9 , 变量 count 为 6
变量 i 为 10 , 变量 count 为 5
变量 i 为 11 , 变量 count 为 4
变量 i 为 12 , 变量 count 为 3
变量 i 为 13 , 变量 count 为 2
变量 i 为 14 , 变量 count 为 1
变量 i 为 15 , 变量 count 为 0*/
```

### extern 存储类
- 第一个文件：main.cpp
```
#include <iostream>
 
int count ;
extern void write_extern();
 
int main()
{
   count = 5;
   write_extern();
}
```
- 第二个文件：support.cpp
```
#include <iostream>
 
extern int count;
 
void write_extern(void)
{
   std::cout << "Count is " << count << std::endl;
}
```
- 编译
```
cl /c main.cpp
cl /c support.cpp
```
- 链接
```
link main.obj support.obj
```

### 算术运算符
运算符 | 描述 | 实例
----|------|----
+      | 把两个操作数相加 | A + B 将得到 30
-      | 从第一个操作数中减去第二个操作数 | A - B 将得到 -10
*      | 把两个操作数相乘 | A * B 将得到 200
/      | 分子除以分母 | B / A 将得到 2
%      | 取模运算符，整除后的余数 | B % A 将得到 0
++     | 自增运算符，整数值增加 1 | A++ 将得到 11
--     | 自减运算符，整数值减少 1 | A-- 将得到 9

