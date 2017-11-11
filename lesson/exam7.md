### 异常处理
	using System;

	namespace ErrorHandlingApplication {

	   class DivNumbers {
		  int result;
		  
		  DivNumbers() {
			 result = 0;
		  }
		  
		  public void division(int num1, int num2) {
			 try {
				result = num1 / num2;
			 } catch (DivideByZeroException e) {
				Console.WriteLine("Exception caught: {0}", e);
			 } finally {
				Console.WriteLine("Result: {0}", result);
			 }
		  }
		  
		  static void Main(string[] args) {
			 DivNumbers d = new DivNumbers();
			 d.division(25, 0);
			 Console.ReadKey();
		  }
	   }
	}
	
#### throw 语句用于发出在程序执行期间出现反常情况（异常）的信号。
    public class ThrowTest2
    {

        static int GetNumber(int index)
        {
            int[] nums = { 300, 600, 900 };
            if (index > nums.Length)
            {
                throw new IndexOutOfRangeException();
            }
            return nums[index];

        }
        static void Main() 
        {
            int result = GetNumber(3);

        }
    }
    /*
        Output:
        The System.IndexOutOfRangeException exception occurs.
    */

#### try-catch
- 在此例中， try 块包含对可能导致异常的 ProcessString 方法的调用。 catch 子句包含仅在屏幕上显示消息的异常处理程序。 当从 MyMethod 内部调用 throw 语句时，系统查找 catch 语句并显示 Exception caught 消息。  
    class TryFinallyTest
	{
		static void ProcessString(string s)
		{
			if (s == null)
			{
				throw new ArgumentNullException();
			}
		}

		static void Main()
		{
			string s = null; // For demonstration purposes.

			try
			{            
				ProcessString(s);
			}

			catch (Exception e)
			{
				Console.WriteLine("{0} Exception caught.", e);
			}
		}
	}
    /*
    Output:
    System.ArgumentNullException: Value cannot be null.
       at TryFinallyTest.Main() Exception caught.
     * */
	 
- 此例使用了两个 catch 语句。最先出现的最特定的异常被捕获。
	class ThrowTest3
	{
		static void ProcessString(string s)
		{
			if (s == null)
			{
				throw new ArgumentNullException();
			}
		}

		static void Main()
		{
			try
			{
				string s = null;
				ProcessString(s);
			}
			// Most specific:
			catch (ArgumentNullException e)
			{
				Console.WriteLine("{0} First exception caught.", e);
			}
			// Least specific:
			catch (Exception e)
			{
				Console.WriteLine("{0} Second exception caught.", e);
			}
		}
	}
	/*
	 Output:
	System.ArgumentNullException: Value cannot be null.
	   at TryFinallyTest.Main() First exception caught.
	*/

#### try-finally
- 在此例中，有一个导致异常的无效转换语句。当运行程序时，您收到一条运行时错误信息，但 finally 子句仍继续执行并显示输出。
    public class ThrowTest
    {
        static void Main()
        {
            int i = 123;
            string s = "Some string";
            object o = s;

            try
            {
                // Invalid conversion; o contains a string not an int
                i = (int)o;
            }
            finally
            {
                Console.Write("i = {0}", i);
            }
        }
    }

#### try-catch-finally
	public class EHClass
	{
		void ReadFile(int index)
		{
			// To run this code, substitute a valid path from your local machine
			string path = @"c:\users\public\test.txt";
			System.IO.StreamReader file = new System.IO.StreamReader(path);
			char[] buffer = new char[10];
			try
			{
				file.ReadBlock(buffer, index, buffer.Length);
			}
			catch (System.IO.IOException e)
			{
				Console.WriteLine("Error reading from {0}. Message = {1}", path, e.Message);
			}

			finally
			{
				if (file != null)
				{
					file.Close();
				}
			}
			// Do something with buffer...
		}
	}
	
### using 指令
	using System.Text;

### using static 指令
	using System;
	using static System.Console;
	using static System.Math;
	using static System.String;

	class Program
	{
	   static void Main()
	   {
		  Write("Enter a circle's radius: ");
		  var input = ReadLine();
		  if (!IsNullOrEmpty(input) && double.TryParse(input, out var radius)) {
			 var c = new Circle(radius);
			 
			 string s = "\nInformation about the circle:\n";
			 s = s + Format("   Radius: {0:N2}\n", c.Radius);
			 s = s + Format("   Diameter: {0:N2}\n", c.Diameter);
			 s = s + Format("   Circumference: {0:N2}\n", c.Circumference);
			 s = s + Format("   Area: {0:N2}\n", c.Area);
			 WriteLine(s);
		  }
		  else {
			 WriteLine("Invalid input...");
		  }
	   }
		}

	public class Circle
	{
	   public Circle(double radius)
	   {
		  Radius = radius;
	   }

	   public double Radius { get; set; }

	   public double Diameter
	   {
		  get { return 2 * Radius; }
	   }

	   public double Circumference
	   {
		  get { return 2 * Radius * PI; }      
	   }

	   public double Area
	   {
		  get { return PI * Pow(Radius, 2); }
	   }
	}
	// The example displays the following output:
	//       Enter a circle's radius: 12.45
	//       
	//       Information about the circle:
	//          Radius: 12.45
	//          Diameter: 24.90
	//          Circumference: 78.23
	//          Area: 486.95

### using 语句
	using (Font font1 = new Font("Arial", 10.0f)) 
	{
		byte charset = font1.GdiCharSet;
	}
	
	using (Font font3 = new Font("Arial", 10.0f),
				font4 = new Font("Arial", 10.0f))
	{
		// Use font3 and font4.
	}
	
	Font font2 = new Font("Arial", 10.0f);
	using (font2) // not recommended
	{
		// use font2
	}
	// font2 is still in scope
	// but the method call throws an exception
	float f = font2.GetHeight(); 