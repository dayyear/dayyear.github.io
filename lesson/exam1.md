### 基本语法
    using System;
    namespace RectangleApplication
    {
       class Rectangle 
       {
          // member variables
          double length;
          double width;
          public void Acceptdetails()
          {
             length = 4.5;    
             width = 3.5;
          }
          
          public double GetArea()
          {
             return length * width; 
          }
          
          public void Display()
          {
             Console.WriteLine("Length: {0}", length);
             Console.WriteLine("Width: {0}", width);
             Console.WriteLine("Area: {0}", GetArea());
          }
       }
       
       class ExecuteRectangle 
       {
          static void Main(string[] args) 
          {
             Rectangle r = new Rectangle();
             r.Acceptdetails();
             r.Display();
             Console.ReadLine(); 
          }
       }
    }
    
### 类型转换1
    using System;
    namespace TypeConversionApplication 
    {
       class ExplicitConversion 
       {
          static void Main(string[] args) 
          {
             double d = 5673.74; 
             int i;
             
             // cast double to int.
             i = (int)d;
             Console.WriteLine(i);
             Console.ReadKey();
          }
       }
    }
    
### 类型转换2
    using System;
    namespace TypeConversionApplication 
    {
       class StringConversion
       {
          static void Main(string[] args)
          {
             int i = 75;
             float f = 53.005f;
             double d = 2345.7652;
             bool b = true;
    
             Console.WriteLine(i.ToString());
             Console.WriteLine(f.ToString());
             Console.WriteLine(d.ToString());
             Console.WriteLine(b.ToString());
             Console.ReadKey();
                
          }
       }
    }
    
### 变量
    using System;
    namespace VariableDefinition 
    {
       class Program 
       {
          static void Main(string[] args) 
          {
             short a;
             int b ;
             double c;
    
             /* actual initialization */
             a = 10;
             b = 20;
             c = a + b;
             Console.WriteLine("a = {0}, b = {1}, c = {2}", a, b, c);
             Console.ReadLine();
          }
       }
    }
    
### 常量
    using System;
    namespace DeclaringConstants
    {
        class Program
        {
            static void Main(string[] args)
            {
                // constant declaration 
                const double pi = 3.14159;   
                
                double r;
                Console.WriteLine("Enter Radius: ");
                r = Convert.ToDouble(Console.ReadLine());
                double areaCircle = pi * r * r;
                Console.WriteLine("Radius: {0}, Area: {1}", r, areaCircle);
                Console.ReadLine();
            }
        }
    }
    
### if语句
    using System;
    namespace DecisionMaking
    {
       class Program
       {
          static void Main(string[] args)
          {
             /* local variable definition */
             int a = 10;
             /* check the boolean condition using if statement */
             if (a < 20)
             {
                /* if condition is true then print the following */
                Console.WriteLine("a is less than 20");
             }
             Console.WriteLine("value of a is : {0}", a);
             Console.ReadLine();
          }
       }
    }
    
### if...else语句
    using System;
    namespace DecisionMaking
    {
       class Program 
       {
          static void Main(string[] args)
          {
             /* local variable definition */
             int a = 100;
             
             /* check the boolean condition */
             if (a == 10)
             {
                /* if condition is true then print the following */
                Console.WriteLine("Value of a is 10");
             }
             
             else if (a == 20)
             {
                /* if else if condition is true */
                Console.WriteLine("Value of a is 20");
             }
             
             else if (a == 30)
             {
                /* if else if condition is true  */
                Console.WriteLine("Value of a is 30");
             }
             
             else
             {
                /* if none of the conditions is true */
                Console.WriteLine("None of the values is matching");
             }
             Console.WriteLine("Exact value of a is: {0}", a);
             Console.ReadLine();
          }
       }
    }
    
### if嵌套语句
    using System;
    namespace DecisionMaking
    {
       class Program
       {
          static void Main(string[] args)
          {
             //* local variable definition */
             int a = 100;
             int b = 200;
             
             /* check the boolean condition */
             if (a == 100)
             {
                /* if condition is true then check the following */
                if (b == 200)
                {
                   /* if condition is true then print the following */
                   Console.WriteLine("Value of a is 100 and b is 200");
                }
             }
             Console.WriteLine("Exact value of a is : {0}", a);
             Console.WriteLine("Exact value of b is : {0}", b);
             Console.ReadLine();
          }
       }
    }
    
### switch语句
    using System;
    namespace DecisionMaking
    {
       class Program
       {
          static void Main(string[] args)
          {
             /* local variable definition */
             char grade = 'B';
             
             switch (grade)
             {
                case 'A':
                   Console.WriteLine("Excellent!");
                   break;
                case 'B':
                case 'C':
                   Console.WriteLine("Well done");
                   break;
                case 'D':
                   Console.WriteLine("You passed");
                   break;
                case 'F':
                   Console.WriteLine("Better try again");
                   break;
                   default:
                Console.WriteLine("Invalid grade");
                   break;
             }
             Console.WriteLine("Your grade is  {0}", grade);
             Console.ReadLine();
          }
       }
    }
    
### switch嵌套语句
    using System;
    namespace DecisionMaking
    {
       class Program 
       {
          static void Main(string[] args)
          {
             int a = 100;
             int b = 200;
             
             switch (a) 
             {
                case 100: 
                Console.WriteLine("This is part of outer switch ");
                switch (b)
                {
                   case 200:
                   Console.WriteLine("This is part of inner switch ");
                   break;
                }
                break;
             }
             Console.WriteLine("Exact value of a is : {0}", a);
             Console.WriteLine("Exact value of b is : {0}", b);
             Console.ReadLine();
          }
       }
    } 
    
### while循环
    using System;
    namespace Loops 
    {
       class Program
       {
          static void Main(string[] args)
          {
             /* local variable definition */
             int a = 10;
    
             /* while loop execution */
             while (a < 20)
             {
                Console.WriteLine("value of a: {0}", a);
                a++;
             }
             Console.ReadLine();
          }
       }
    } 
    
### for循环
    using System;
    namespace Loops
    {
       class Program
       {
          static void Main(string[] args)
          {
             /* for loop execution */
             for (int a = 10; a < 20; a = a + 1)
             {
                Console.WriteLine("value of a: {0}", a);
             }
             Console.ReadLine();
          }
       }
    } 
    
### do...while循环
    using System;
    namespace Loops
    {
       class Program
       {
          static void Main(string[] args)
          {
             /* local variable definition */
             int a = 10;
             
             /* do loop execution */
             do
             {
                Console.WriteLine("value of a: {0}", a);
                a = a + 1;
             } 
             while (a < 20);
             Console.ReadLine();
          }
       }
    } 
    
### 嵌套循环
    using System;
    namespace Loops
    {
       class Program
       {
          static void Main(string[] args)
          {
             /* local variable definition */
             int i, j;
             for (i = 2; i < 100; i++)
             {
                for (j = 2; j <= (i / j); j++)
                if ((i % j) == 0) break;  // if factor found, not prime
                if (j > (i / j))
                Console.WriteLine("{0} is prime", i);
             }
             Console.ReadLine();
          }
       }
    } 
    
### 死循环
    using System;
    namespace Loops
    {
       class Program
       {
          static void Main(string[] args)
          {
             for (; ; )
             {
                Console.WriteLine("Hey! I am Trapped");
             }
          }
       }
    } 
