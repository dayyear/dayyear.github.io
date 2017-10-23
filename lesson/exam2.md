### 方法定义
    class NumberManipulator {
    
       public int FindMax(int num1, int num2) {
          /* local variable declaration */
          int result;
    
          if (num1 > num2)
             result = num1;
          else
             result = num2;
    
          return result;
       }
       ...
    }
    
### 方法调用（同一个类）
    using System;
    
    namespace CalculatorApplication {
    
       class NumberManipulator {
       
          public int FindMax(int num1, int num2) {
             /* local variable declaration */
             int result;
             
             if (num1 > num2)
                result = num1;
             else
                result = num2;
             return result;
          }
          
          static void Main(string[] args) {
             /* local variable definition */
             int a = 100;
             int b = 200;
             int ret;
             NumberManipulator n = new NumberManipulator();
    
             //calling the FindMax method
             ret = n.FindMax(a, b);
             Console.WriteLine("Max value is : {0}", ret );
             Console.ReadLine();
          }
       }
    }
    
### 方法调用（不同类）
    using System;
    
    namespace CalculatorApplication {
    
       class NumberManipulator {
       
          public int FindMax(int num1, int num2) {
             /* local variable declaration */
             int result;
             
             if(num1 > num2)
                result = num1;
             else
                result = num2;
             
             return result;
          }
       }
       
       class Test {
       
          static void Main(string[] args) {
             /* local variable definition */
             int a = 100;
             int b = 200;
             int ret;
             NumberManipulator n = new NumberManipulator();
             
             //calling the FindMax method
             ret = n.FindMax(a, b);
             Console.WriteLine("Max value is : {0}", ret );
             Console.ReadLine();
          }
       }
    }
    
### 方法的递归调用
    using System;
    
    namespace CalculatorApplication {
    
       class NumberManipulator {
       
          public int factorial(int num) {
             /* local variable declaration */
             int result;
             if (num == 1) {
                return 1;
             }
             else {
                result = factorial(num - 1) * num;
                return result;
             }
          }
          
          static void Main(string[] args) {
             NumberManipulator n = new NumberManipulator();
             //calling the factorial method {0}", n.factorial(6));
             Console.WriteLine("Factorial of 7 is : {0}", n.factorial(7));
             Console.WriteLine("Factorial of 8 is : {0}", n.factorial(8));
             Console.ReadLine();
          }
       }
    }
    
### 方法参数的值传递
    using System;
    
    namespace CalculatorApplication {
    
       class NumberManipulator {
       
          public void swap(int x, int y) {
             int temp;
             
             temp = x; /* save the value of x */
             x = y;    /* put y into x */
             y = temp; /* put temp into y */
          }
          
          static void Main(string[] args) {
             NumberManipulator n = new NumberManipulator();
             
             /* local variable definition */
             int a = 100;
             int b = 200;
             
             Console.WriteLine("Before swap, value of a : {0}", a);
             Console.WriteLine("Before swap, value of b : {0}", b);
             
             /* calling a function to swap the values */
             n.swap(a, b);
             
             Console.WriteLine("After swap, value of a : {0}", a);
             Console.WriteLine("After swap, value of b : {0}", b);
             
             Console.ReadLine();
          }
       }
    }
    
### 方法参数的引用传递
    using System;
    
    namespace CalculatorApplication {
    
       class NumberManipulator {
       
          public void swap(ref int x, ref int y) {
             int temp;
    
             temp = x; /* save the value of x */
             x = y;    /* put y into x */
             y = temp; /* put temp into y */
          }
       
          static void Main(string[] args) {
             NumberManipulator n = new NumberManipulator();
             
             /* local variable definition */
             int a = 100;
             int b = 200;
    
             Console.WriteLine("Before swap, value of a : {0}", a);
             Console.WriteLine("Before swap, value of b : {0}", b);
    
             /* calling a function to swap the values */
             n.swap(ref a, ref b);
    
             Console.WriteLine("After swap, value of a : {0}", a);
             Console.WriteLine("After swap, value of b : {0}", b);
     
             Console.ReadLine();
    
          }
       }
    }
    
### 方法参数的输出
    using System;
    
    namespace CalculatorApplication {
    
       class NumberManipulator {
       
          public void getValues(out int x, out int y ) {
              Console.WriteLine("Enter the first value: ");
              x = Convert.ToInt32(Console.ReadLine());
              Console.WriteLine("Enter the second value: ");
              y = Convert.ToInt32(Console.ReadLine());
          }
          
          static void Main(string[] args) {
             NumberManipulator n = new NumberManipulator();
             
             /* local variable definition */
             int a , b;
             
             /* calling a function to get the values */
             n.getValues(out a, out b);
             
             Console.WriteLine("After method call, value of a : {0}", a);
             Console.WriteLine("After method call, value of b : {0}", b);
             Console.ReadLine();
          }
       }
    }
    
### 可空类型
    using System;
    
    namespace CalculatorApplication {
    
       class NullablesAtShow {
       
          static void Main(string[] args) {
             int? num1 = null;
             int? num2 = 45;
             double? num3 = new double?();
             double? num4 = 3.14157;
             
             bool? boolval = new bool?();
    
             // display the values
             Console.WriteLine("Nullables at Show: {0}, {1}, {2}, {3}", num1, num2, num3, num4);
             Console.WriteLine("A Nullable boolean value: {0}", boolval);
             Console.ReadLine();
          }
       }
    }
    
### ??操作符
    using System;
    
    namespace CalculatorApplication {
    
       class NullablesAtShow {
       
          static void Main(string[] args) {
             double? num1 = null;
             double? num2 = 3.14157;
             double num3;
             num3 = num1 ?? 5.34;      
             Console.WriteLine(" Value of num3: {0}", num3);
             num3 = num2 ?? 5.34;
             Console.WriteLine(" Value of num3: {0}", num3);
             Console.ReadLine();
          }
       }
    }
    
### 数组定义
    double[] balance;
    
### 数组初始化
    double[] balance = new double[10];
    
### 数组赋值
    double[] balance = new double[10];
    balance[0] = 4500.0;
    
    double[] balance = { 2340.0, 4523.69, 3421.0};
    
    int [] marks = new int[5]  { 99,  98, 92, 97, 95};
    
    int [] marks = new int[]  { 99,  98, 92, 97, 95};
    
    int [] marks = new int[]  { 99,  98, 92, 97, 95};
    int[] score = marks;
    
### 数组元素
    using System;
    
    namespace ArrayApplication {
    
       class MyArray {
       
          static void Main(string[] args) {
             int []  n = new int[10]; /* n is an array of 10 integers */
             int i,j;
    
             /* initialize elements of array n */
             for ( i = 0; i < 10; i++ ) {
                n[ i ] = i + 100;
             }
             
             /* output each array element's value */
             for (j = 0; j < 10; j++ ) {
                Console.WriteLine("Element[{0}] = {1}", j, n[j]);
             }
             Console.ReadKey();
          }
       }
    }
    
    using System;
    
    namespace ArrayApplication {
    
       class MyArray {
       
          static void Main(string[] args) {
             int []  n = new int[10]; /* n is an array of 10 integers */
             
             /* initialize elements of array n */
             for ( int i = 0; i < 10; i++ ) {
                n[i] = i + 100;
             }
             
             /* output each array element's value */
             foreach (int j in n ) {
                int i = j-100;
                Console.WriteLine("Element[{0}] = {1}", i, j);
                
             }
             Console.ReadKey();
          }
       }
    }
    
### 多维数组
    using System;
    
    namespace ArrayApplication {
    
       class MyArray {
       
          static void Main(string[] args) {
             /* an array with 5 rows and 2 columns*/
             int[,] a = new int[5, 2] {{0,0}, {1,2}, {2,4}, {3,6}, {4,8} };
             int i, j;
             
             /* output each array element's value */
             for (i = 0; i < 5; i++) {
                
                for (j = 0; j < 2; j++) {
                   Console.WriteLine("a[{0},{1}] = {2}", i, j, a[i,j]);
                }
             }
             Console.ReadKey();
          }
       }
    }
    
### 数组作为方法参数
    using System;
    
    namespace ArrayApplication {
    
       class MyArray {
       
          double getAverage(int[] arr, int size) {
             int i;
             double avg;
             int sum = 0;
             
             for (i = 0; i < size; ++i) {
                sum += arr[i];
             }
             avg = (double)sum / size;
             return avg;
          }
          
          static void Main(string[] args) {
             MyArray app = new MyArray();
             
             /* an int array with 5 elements */
             int [] balance = new int[]{1000, 2, 3, 17, 50};
             double avg;
    
             /* pass pointer to the array as an argument */
             avg = app.getAverage(balance, 5 ) ;
    
             /* output the returned value */
             Console.WriteLine( "Average value is: {0} ", avg );
             Console.ReadKey();
          }
       }
    }
    
### 参数数组
    using System;
    
    namespace ArrayApplication {
    
       class ParamArray {
       
          public int AddElements(params int[] arr) {
             int sum = 0;
             
             foreach (int i in arr) {
                sum += i;
             }
             return sum;
          }
       }
          
       class TestClass {
          
          static void Main(string[] args) {
             ParamArray app = new ParamArray();
             int sum = app.AddElements(512, 720, 250, 567, 889);
             Console.WriteLine("The sum is: {0}", sum);
             Console.ReadKey();
          }
       }
    }
    
### Array类的静态方法
    using System;
    
    namespace ArrayApplication {
    
       class MyArray {
       
          static void Main(string[] args) {
             int[] list = { 34, 72, 13, 44, 25, 30, 10 };
             int[] temp = list;
             Console.Write("Original Array: ");
             
             foreach (int i in list) {
                Console.Write(i + " ");
             }
             Console.WriteLine();
             
             // reverse the array
             Array.Reverse(temp);
             Console.Write("Reversed Array: ");
             
             foreach (int i in temp) {
                Console.Write(i + " ");
             }
             Console.WriteLine();
             
             //sort the array
             Array.Sort(list);
             Console.Write("Sorted Array: ");
             
             foreach (int i in list) {
                Console.Write(i + " ");
             }
             Console.WriteLine();
             Console.ReadKey();
          }
       }
    }
    
### 创建字符串
    using System;
    
    namespace StringApplication {
    
       class Program {
       
          static void Main(string[] args) {
             //from string literal and string concatenation
             string fname, lname;
             fname = "Rowan";
             lname = "Atkinson";
             
             string fullname = fname + lname;
             Console.WriteLine("Full Name: {0}", fullname);
             
             //by using string constructor { 'H', 'e', 'l', 'l','o' };
             string greetings = new string(letters);
             Console.WriteLine("Greetings: {0}", greetings);
             
             //methods returning string { "Hello", "From", "Tutorials", "Point" };
             string message = String.Join(" ", sarray);
             Console.WriteLine("Message: {0}", message);
             
             //formatting method to convert a value
             DateTime waiting = new DateTime(2012, 10, 10, 17, 58, 1);
             string chat = String.Format("Message sent at {0:t} on {0:D}", waiting);
             Console.WriteLine("Message: {0}", chat);
          }
       }
    }
    
### 字符串方法-比较Compare
    using System;
    
    namespace StringApplication {
    
       class StringProg {
       
          static void Main(string[] args) {
             string str1 = "This is test";
             string str2 = "This is text";
    
             if (String.Compare(str1, str2) == 0) {
                Console.WriteLine(str1 + " and " + str2 +  " are equal.");
             } else {
                Console.WriteLine(str1 + " and " + str2 + " are not equal.");
             }
             Console.ReadKey() ;
          }
       }
    }
    
### 字符串方法-包含Contains
    using System;
    
    namespace StringApplication {
    
       class StringProg {
       
          static void Main(string[] args) {
             string str = "This is test";
             
             if (str.Contains("test")) {
                Console.WriteLine("The sequence 'test' was found.");
             }
             Console.ReadKey() ;
          }
       }
    }
    
### 字符串方法-子字符串Substring
    using System;
    
    namespace StringApplication {
    
       class StringProg {
       
          static void Main(string[] args) {
             string str = "Last night I dreamt of San Pedro";
             Console.WriteLine(str);
             string substr = str.Substring(23);
             Console.WriteLine(substr);
          }
       }
    }
    
### 字符串方法-查找IndexOf
    using System;
    
    public class Example
    {
       public static void Main()
       {
          String str = "animal";
          String toFind = "n";
          int index = str.IndexOf("n");
          Console.WriteLine("Found '{0}' in '{1}' at position {2}",
                            toFind, str, index);
       }
    }
    // The example displays the following output:
    //        Found 'n' in 'animal' at position 1
    
### 字符串方法-替换Replace
    using System;
    
    public class ReplaceTest {
        public static void Main() {
    
            string errString = "This docment uses 3 other docments to docment the docmentation";
    
            Console.WriteLine("The original string is:{0}'{1}'{0}", Environment.NewLine, errString);
    
            // Correct the spelling of "document".
    
            string correctString = errString.Replace("docment", "document");
    
            Console.WriteLine("After correcting the string, the result is:{0}'{1}'",
                    Environment.NewLine, correctString);
        }
    }
    //
    // This code example produces the following output:
    //
    // The original string is:
    // 'This docment uses 3 other docments to docment the docmentation'
    //
    // After correcting the string, the result is:
    // 'This document uses 3 other documents to document the documentation'
    //
    
### 字符串方法-串联Join
    using System;
    
    namespace StringApplication {
    
       class StringProg {
       
          static void Main(string[] args) {
             string[] starray = new string[]{"Down the way nights are dark",
                "And the sun shines daily on the mountain top",
                "I took a trip on a sailing ship",
                "And when I reached Jamaica",
                "I made a stop"};
    
             string str = String.Join("\n", starray);
             Console.WriteLine(str);
          }
       }
    }
    
### 字符串方法-分割Split
    class TestStringSplit
    {
        static void Main()
        {
            char[] delimiterChars = { ' ', ',', '.', ':', '\t' };
    
            string text = "one\ttwo three:four,five six seven";
            System.Console.WriteLine("Original text: '{0}'", text);
    
            string[] words = text.Split(delimiterChars);
            System.Console.WriteLine("{0} words in text:", words.Length);
    
            foreach (string s in words)
            {
                System.Console.WriteLine(s);
            }
    
            // Keep the console window open in debug mode.
            System.Console.WriteLine("Press any key to exit.");
            System.Console.ReadKey();
        }
    }
    /* Output:
        Original text: 'one     two three:four,five six seven'
        7 words in text:
        one
        two
        three
        four
        five
        six
        seven
     */
     
### 字符串方法-分割Split(RemoveEmptyEntries参数)
    class TestStringSplit  
    {  
        static void Main()  
        {  
            string[] separatingChars = { "<<", "..." };  
    
            string text = "one<<two......three<four";  
            System.Console.WriteLine("Original text: '{0}'", text);  
    
            string[] words = text.Split(separatingChars, System.StringSplitOptions.RemoveEmptyEntries );  
            System.Console.WriteLine("{0} substrings in text:", words.Length);  
    
            foreach (string s in words)  
            {  
                System.Console.WriteLine(s);  
            }  
    
            // Keep the console window open in debug mode.  
            System.Console.WriteLine("Press any key to exit.");  
            System.Console.ReadKey();  
        }  
    }  
    /* Output:  
        Original text: 'one<<two......three<four'  
        3 words in text:  
        one  
        two  
        three<four  
    */
    
    
### 结构
    using System;
    
    struct Books {
       public string title;
       public string author;
       public string subject;
       public int book_id;
    };  
    
    public class testStructure {
    
       public static void Main(string[] args) {
          Books Book1;   /* Declare Book1 of type Book */
          Books Book2;   /* Declare Book2 of type Book */
    
          /* book 1 specification */
          Book1.title = "C Programming";
          Book1.author = "Nuha Ali"; 
          Book1.subject = "C Programming Tutorial";
          Book1.book_id = 6495407;
    
          /* book 2 specification */
          Book2.title = "Telecom Billing";
          Book2.author = "Zara Ali";
          Book2.subject =  "Telecom Billing Tutorial";
          Book2.book_id = 6495700;
    
          /* print Book1 info */
          Console.WriteLine( "Book 1 title : {0}", Book1.title);
          Console.WriteLine("Book 1 author : {0}", Book1.author);
          Console.WriteLine("Book 1 subject : {0}", Book1.subject);
          Console.WriteLine("Book 1 book_id :{0}", Book1.book_id);
    
          /* print Book2 info */
          Console.WriteLine("Book 2 title : {0}", Book2.title);
          Console.WriteLine("Book 2 author : {0}", Book2.author);
          Console.WriteLine("Book 2 subject : {0}", Book2.subject);
          Console.WriteLine("Book 2 book_id : {0}", Book2.book_id);       
    
          Console.ReadKey();
       }
    }
    
### 枚举
    using System;
    
    namespace EnumApplication {
    
       class EnumProgram {
          enum Days { Sun, Mon, tue, Wed, thu, Fri, Sat };
    
          static void Main(string[] args) {
             int WeekdayStart = (int)Days.Mon;
             int WeekdayEnd = (int)Days.Fri;
             Console.WriteLine("Monday: {0}", WeekdayStart);
             Console.WriteLine("Friday: {0}", WeekdayEnd);
             Console.ReadKey();
          }
       }
    }
    
### List 泛型类
    using System;
    using System.Collections.Generic;
    
    public class Example
    {
        public static void Main()
        {
            List<string> dinosaurs = new List<string>();
    
            Console.WriteLine("\nCapacity: {0}", dinosaurs.Capacity);
    
            dinosaurs.Add("Tyrannosaurus");
            dinosaurs.Add("Amargasaurus");
            dinosaurs.Add("Mamenchisaurus");
            dinosaurs.Add("Deinonychus");
            dinosaurs.Add("Compsognathus");
    
            Console.WriteLine();
            foreach(string dinosaur in dinosaurs)
            {
                Console.WriteLine(dinosaur);
            }
    
            Console.WriteLine("\nCapacity: {0}", dinosaurs.Capacity);
            Console.WriteLine("Count: {0}", dinosaurs.Count);
    
            Console.WriteLine("\nContains(\"Deinonychus\"): {0}",
                dinosaurs.Contains("Deinonychus"));
    
            Console.WriteLine("\nInsert(2, \"Compsognathus\")");
            dinosaurs.Insert(2, "Compsognathus");
    
            Console.WriteLine();
            foreach(string dinosaur in dinosaurs)
            {
                Console.WriteLine(dinosaur);
            }
    
            Console.WriteLine("\ndinosaurs[3]: {0}", dinosaurs[3]);
    
            Console.WriteLine("\nRemove(\"Compsognathus\")");
            dinosaurs.Remove("Compsognathus");
    
            Console.WriteLine();
            foreach(string dinosaur in dinosaurs)
            {
                Console.WriteLine(dinosaur);
            }
    
            dinosaurs.TrimExcess();
            Console.WriteLine("\nTrimExcess()");
            Console.WriteLine("Capacity: {0}", dinosaurs.Capacity);
            Console.WriteLine("Count: {0}", dinosaurs.Count);
    
            dinosaurs.Clear();
            Console.WriteLine("\nClear()");
            Console.WriteLine("Capacity: {0}", dinosaurs.Capacity);
            Console.WriteLine("Count: {0}", dinosaurs.Count);
        }
    }
    
    /* This code example produces the following output:
    
    Capacity: 0
    
    Tyrannosaurus
    Amargasaurus
    Mamenchisaurus
    Deinonychus
    Compsognathus
    
    Capacity: 8
    Count: 5
    
    Contains("Deinonychus"): True
    
    Insert(2, "Compsognathus")
    
    Tyrannosaurus
    Amargasaurus
    Compsognathus
    Mamenchisaurus
    Deinonychus
    Compsognathus
    
    dinosaurs[3]: Mamenchisaurus
    
    Remove("Compsognathus")
    
    Tyrannosaurus
    Amargasaurus
    Mamenchisaurus
    Deinonychus
    Compsognathus
    
    TrimExcess()
    Capacity: 5
    Count: 5
    
    Clear()
    Capacity: 5
    Count: 0
     */
     
    
### I/O类
    1.BinaryReader
    Reads primitive data from a binary stream.
    2.BinaryWriter
    Writes primitive data in binary format.
    3.BufferedStream
    A temporary storage for a stream of bytes.
    4.Directory
    Helps in manipulating a directory structure.
    5.DirectoryInfo
    Used for performing operations on directories.
    6.DriveInfo
    Provides information for the drives.
    7.File
    Helps in manipulating files.
    8.FileInfo
    Used for performing operations on files.
    9.FileStream
    Used to read from and write to any location in a file.
    10.MemoryStream
    Used for random access to streamed data stored in memory.
    11.Path
    Performs operations on path information.
    12.StreamReader
    Used for reading characters from a byte stream.
    13.StreamWriter
    Is used for writing characters to a stream.
    14.StringReader
    Is used for reading from a string buffer.
    15.StringWriter
    Is used for writing into a string buffer.
    
### FileStream类
    using System;
    using System.IO;
    
    namespace FileIOApplication {
       
       class Program {
          
          static void Main(string[] args) {
             FileStream F = new FileStream("test.dat", FileMode.OpenOrCreate, 
                FileAccess.ReadWrite);
             
             for (int i = 1; i <= 20; i++) {
                F.WriteByte((byte)i);
             }
             
             F.Position = 0;
             for (int i = 0; i <= 20; i++) {
                Console.Write(F.ReadByte() + " ");
             }
             F.Close();
             Console.ReadKey();
          }
       }
    }
    
### 读文本文件StreamReader
    using System;
    using System.IO;
    
    namespace FileApplication {
    
       class Program {
       
          static void Main(string[] args) {
             
             try {
                // Create an instance of StreamReader to read from a file.
                // The using statement also closes the StreamReader.
                using (StreamReader sr = new StreamReader("c:/jamaica.txt")) {
                   string line;
    
                   // Read and display lines from the file until 
                   // the end of the file is reached. 
                   while ((line = sr.ReadLine()) != null) {
                      Console.WriteLine(line);
                   }
                }
             } catch (Exception e) {
                // Let the user know what went wrong.
                Console.WriteLine("The file could not be read:");
                Console.WriteLine(e.Message);
             }
             Console.ReadKey();
          }
       }
    }
    
### 写文本文件StreamWriter
    using System;
    using System.IO;
    
    namespace FileApplication {
       
       class Program {
          
          static void Main(string[] args) {
             string[] names = new string[] {"Zara Ali", "Nuha Ali"};
             
             using (StreamWriter sw = new StreamWriter("names.txt")) {
    
                foreach (string s in names) {
                   sw.WriteLine(s);
                }
             }
             
             // Read and show each line from the file.
             string line = "";
             using (StreamReader sr = new StreamReader("names.txt")) {
                while ((line = sr.ReadLine()) != null) {
                   Console.WriteLine(line);
                }
             }
             Console.ReadKey();
          }
       }
    }
    
### 读二进制文件BinaryReader 
    using System;
    using System.IO;
    
    namespace BinaryFileApplication {
       
       class Program {
          
          static void Main(string[] args) {
             BinaryWriter bw;
             BinaryReader br;
             int i = 25;
             double d = 3.14157;
             bool b = true;
             string s = "I am happy";
             
             //create the file
             try {
                bw = new BinaryWriter(new FileStream("mydata", FileMode.Create));
             } catch (IOException e) {
                Console.WriteLine(e.Message + "\n Cannot create file.");
                return;
             }
             
             //writing into the file
             try {
                bw.Write(i);
                bw.Write(d);
                bw.Write(b);
                bw.Write(s);
             } catch (IOException e) {
                Console.WriteLine(e.Message + "\n Cannot write to file.");
                return;
             }
             bw.Close();
             
             //reading from the file
             try {
                br = new BinaryReader(new FileStream("mydata", FileMode.Open));
             } catch (IOException e) {
                Console.WriteLine(e.Message + "\n Cannot open file.");
                return;
             }
             
             try {
                i = br.ReadInt32();
                Console.WriteLine("Integer data: {0}", i);
                d = br.ReadDouble();
                Console.WriteLine("Double data: {0}", d);
                b = br.ReadBoolean();
                Console.WriteLine("Boolean data: {0}", b);
                s = br.ReadString();
                Console.WriteLine("String data: {0}", s);
             } catch (IOException e) {
                Console.WriteLine(e.Message + "\n Cannot read from file.");
                return;
             }
             br.Close();
             Console.ReadKey();
          }
       }
    }
    
### 写二进制文件BinaryWriter
    using System;
    using System.IO;
    
    namespace BinaryFileApplication {
       
       class Program {
          
          static void Main(string[] args) {
             BinaryWriter bw;
             BinaryReader br;
             int i = 25;
             double d = 3.14157;
             bool b = true;
             string s = "I am happy";
             
             //create the file
             try {
                bw = new BinaryWriter(new FileStream("mydata", FileMode.Create));
             } catch (IOException e) {
                Console.WriteLine(e.Message + "\n Cannot create file.");
                return;
             }
             
             //writing into the file
             try {
                bw.Write(i);
                bw.Write(d);
                bw.Write(b);
                bw.Write(s);
             } catch (IOException e) {
                Console.WriteLine(e.Message + "\n Cannot write to file.");
                return;
             }
             bw.Close();
             
             //reading from the file
             try {
                br = new BinaryReader(new FileStream("mydata", FileMode.Open));
             } catch (IOException e) {
                Console.WriteLine(e.Message + "\n Cannot open file.");
                return;
             }
             
             try {
                i = br.ReadInt32();
                Console.WriteLine("Integer data: {0}", i);
                d = br.ReadDouble();
                Console.WriteLine("Double data: {0}", d);
                b = br.ReadBoolean();
                Console.WriteLine("Boolean data: {0}", b);
                s = br.ReadString();
                Console.WriteLine("String data: {0}", s);
             } catch (IOException e) {
                Console.WriteLine(e.Message + "\n Cannot read from file.");
                return;
             }
             br.Close();
             Console.ReadKey();
          }
       }
    }
    
### Windows文件系统
    using System;
    using System.IO;
    
    namespace WindowsFileApplication {
       
       class Program {
          
          static void Main(string[] args) {
             //creating a DirectoryInfo object
             DirectoryInfo mydir = new DirectoryInfo(@"c:\Windows");
             
             // getting the files in the directory, their names and size
             FileInfo [] f = mydir.GetFiles();
             foreach (FileInfo file in f) {
                Console.WriteLine("File Name: {0} Size: {1}", file.Name, file.Length);
             }
             
             Console.ReadKey();
          }
       }
    }

