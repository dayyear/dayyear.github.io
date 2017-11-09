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