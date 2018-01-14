### C++ 字符串

C++ 提供了以下两种类型的字符串表示形式：
1. C 风格字符串
2. C++ 引入的 string 类类型

### C 风格字符串

```
char greeting[6] = {'H', 'e', 'l', 'l', 'o', '\0'};
char greeting[] = "Hello";
```

![C/C++ 中定义的字符串的内存表示](http://www.runoob.com/wp-content/uploads/2014/08/string_representation.jpg)

```
#include <iostream>
 
using namespace std;
 
int main ()
{
   char greeting[6] = {'H', 'e', 'l', 'l', 'o', '\0'};
 
   cout << "Greeting message: ";
   cout << greeting << endl;
 
   return 0;
}
/*输出
Greeting message: Hello
*/
```

C++ 中有大量的函数用来操作以 null 结尾的字符串

序号 | 函数 | 目的
---- | ---- | ----
1 | strcpy(s1, s2); | 复制字符串 s2 到字符串 s1。
2 | strcat(s1, s2); | 连接字符串 s2 到字符串 s1 的末尾。
3 | strlen(s1);     | 返回字符串 s1 的长度。
4 | strcmp(s1, s2); | 如果 s1 和 s2 是相同的，则返回 0；如果 s1<s2 则返回值小于 0；如果 s1>s2 则返回值大于 0。
5 | strchr(s1, ch); | 返回一个指针，指向字符串 s1 中字符 ch 的第一次出现的位置。
6 | strstr(s1, s2); | 返回一个指针，指向字符串 s1 中字符串 s2 的第一次出现的位置。

```
#include <iostream>
#include <cstring>
 
using namespace std;
 
int main ()
{
   char str1[11] = "Hello";
   char str2[11] = "World";
   char str3[11];
   int  len ;
 
   // 复制 str1 到 str3
   strcpy( str3, str1);
   cout << "strcpy( str3, str1) : " << str3 << endl;
 
   // 连接 str1 和 str2
   strcat( str1, str2);
   cout << "strcat( str1, str2): " << str1 << endl;
 
   // 连接后，str1 的总长度
   len = strlen(str1);
   cout << "strlen(str1) : " << len << endl;
 
   return 0;
}
/*输出
strcpy( str3, str1) : Hello
strcat( str1, str2): HelloWorld
strlen(str1) : 10
*/
```

### C++ 中的 String 类

```
#include <iostream>
#include <string>
 
using namespace std;
 
int main ()
{
   string str1 = "Hello";
   string str2 = "World";
   string str3;
   int  len ;
 
   // 复制 str1 到 str3
   str3 = str1;
   cout << "str3 : " << str3 << endl;
 
   // 连接 str1 和 str2
   str3 = str1 + str2;
   cout << "str1 + str2 : " << str3 << endl;
 
   // 连接后，str3 的总长度
   len = str3.size();
   cout << "str3.size() :  " << len << endl;
 
   return 0;
}
/*输出
str3 : Hello
str1 + str2 : HelloWorld
str3.size() :  10
*/
```

string类提供了一系列针对字符串的操作
1. append() -- 在字符串的末尾添加字符
2. find() -- 在字符串中查找字符串
4. insert() -- 插入字符
5. length() -- 返回字符串的长度
6. replace() -- 替换字符串
7. substr() -- 返回某个子字符串
8. ...

```
#include <iostream>
#include <string>
using namespace std;

int main()
{
    //定义一个string类对象
    string http = "www.taobao.com";

   //打印字符串长度
   cout << http.length() << endl;

    //拼接
    http.append("/C++");
    cout << http << endl;

    //删除
    int pos = http.find("/C++"); //查找"C++"在字符串中的位置
    cout << pos << endl;
    http.replace(pos, 4, "");   //从位置pos开始，之后的4个字符替换为空，即删除
    cout << http <<endl;

    //找子串runoob
    int first = http.find_first_of("."); //从头开始寻找字符'.'的位置
    int last = http.find_last_of(".");   //从尾开始寻找字符'.'的位置
    cout << http.substr(first+1, last-first-1) << endl; //提取"taobao"子串并打印

    return 0;
}
/*输出
14
www.taobao.com/C++
14
www.taobao.com
taobao
*/
```
