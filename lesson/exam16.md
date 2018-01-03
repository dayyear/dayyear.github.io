### 数学运算

```
#include <iostream>
#include <cmath>
using namespace std;

int main()
{
	// 数字定义
	short s = 10;
	int i = -1000;
	long l = 100000;
	float f = 230.47;
	double d = 200.374;
	// 数学运算
	cout << "sin(d)     :" << sin(d) << endl;
	cout << "abs(i)     :" << abs(i) << endl;
	cout << "floor(d)   :" << floor(d) << endl;
	cout << "sqrt(f)    :" << sqrt(f) << endl;
	cout << "pow( d, 2) :" << pow(d, 2) << endl;
	return 0;
}

/*输出
sin(d)     :-0.634939
abs(i)     :1000
floor(d)   :200
sqrt(f)    :15.1812
pow( d, 2) :40149.7
*/
```

### 随机数

```
#include <iostream>
#include <ctime>
#include <cstdlib>
using namespace std;

int main()
{
	int i, j;
	// 设置种子
	srand(static_cast<unsigned int>(time(NULL)));
	/* 生成 10 个随机数 */
	for (i = 0; i < 10; i++)
	{
		// 生成实际的随机数
		j = rand();
		cout << "随机数： " << j << endl;
	}
	return 0;
}
/*输出
随机数： 8049
随机数： 10085
随机数： 27860
随机数： 6745
随机数： 5951
随机数： 21338
随机数： 32023
随机数： 16994
随机数： 21740
随机数： 14399
*/
```

### 声明数组

```
double balance[10];
```

### 初始化数组

```
double balance[5] = {1000.0, 2.0, 3.4, 7.0, 50.0};
double balance[] = {1000.0, 2.0, 3.4, 7.0, 50.0};
```

### 访问数组元素

```
#include <iostream>
using namespace std;
 
#include <iomanip>
using std::setw;
 
int main ()
{
   int n[ 10 ]; // n 是一个包含 10 个整数的数组
 
   // 初始化数组元素          
   for ( int i = 0; i < 10; i++ )
   {
      n[ i ] = i + 100; // 设置元素 i 为 i + 100
   }
   cout << "Element" << setw( 13 ) << "Value" << endl;
 
   // 输出数组中每个元素的值                     
   for ( int j = 0; j < 10; j++ )
   {
      cout << setw( 7 )<< j << setw( 13 ) << n[ j ] << endl;
   }
 
   return 0;
}
/*输出
Element        Value
      0          100
      1          101
      2          102
      3          103
      4          104
      5          105
      6          106
      7          107
      8          108
      9          109
*/
```

### 多维数组

```
#include <iostream>
using namespace std;
 
int main ()
{
   // 一个带有 5 行 2 列的数组
   int a[5][2] = { {0,0}, {1,2}, {2,4}, {3,6},{4,8}};
 
   // 输出数组中每个元素的值                      
   for ( int i = 0; i < 5; i++ )
      for ( int j = 0; j < 2; j++ )
      {
         cout << "a[" << i << "][" << j << "]: ";
         cout << a[i][j]<< endl;
      }
 
   return 0;
}
/*输出
a[0][0]: 0
a[0][1]: 0
a[1][0]: 1
a[1][1]: 2
a[2][0]: 2
a[2][1]: 4
a[3][0]: 3
a[3][1]: 6
a[4][0]: 4
a[4][1]: 8
*/
```

### 指向数组的指针

```
#include <iostream>
using namespace std;
 
int main ()
{
   // 带有 5 个元素的整型数组
   double balance[5] = {1000.0, 2.0, 3.4, 17.0, 50.0};
   double *p;

   p = balance;
 
   // 输出数组中每个元素的值
   cout << "使用指针的数组值 " << endl; 
   for ( int i = 0; i < 5; i++ )
   {
       cout << "*(p + " << i << ") : ";
       cout << *(p + i) << endl;
   }

   cout << "使用 balance 作为地址的数组值 " << endl;
   for ( int i = 0; i < 5; i++ )
   {
       cout << "*(balance + " << i << ") : ";
       cout << *(balance + i) << endl;
   }
 
   return 0;
}
/*输出
使用指针的数组值
*(p + 0) : 1000
*(p + 1) : 2
*(p + 2) : 3.4
*(p + 3) : 17
*(p + 4) : 50
使用 balance 作为地址的数组值
*(balance + 0) : 1000
*(balance + 1) : 2
*(balance + 2) : 3.4
*(balance + 3) : 17
*(balance + 4) : 50
*/
```

### 传递数组给函数

```
#include <iostream>
using namespace std;
 
// 函数声明
double getAverage(int arr[], int size);

int main ()
{
   // 带有 5 个元素的整型数组
   int balance[5] = {1000, 2, 3, 17, 50};
   double avg;

   // 传递一个指向数组的指针作为参数
   avg = getAverage( balance, 5 ) ;
 
   // 输出返回值
   cout << "平均值是：" << avg << endl; 
    
   return 0;
}

double getAverage(int arr[], int size)
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
/*输出
平均值是：214.4
*/
```

### 从函数返回数组

```
#include <iostream>
#include <cstdlib>
#include <ctime>
 
using namespace std;
 
// 要生成和返回随机数的函数
int * getRandom( )
{
  static int  r[10];
 
  // 设置种子
  srand( static_cast<unsigned int>(time( NULL )) );
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
/*输出
10279
11214
6625
25221
5685
16319
27907
16513
26964
9573
*(p + 0) : 10279
*(p + 1) : 11214
*(p + 2) : 6625
*(p + 3) : 25221
*(p + 4) : 5685
*(p + 5) : 16319
*(p + 6) : 27907
*(p + 7) : 16513
*(p + 8) : 26964
*(p + 9) : 9573
*/
```