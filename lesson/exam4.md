### 类的定义
        using System;

        namespace BoxApplication {

            class Box {
               public double length;   // Length of a box
               public double breadth;  // Breadth of a box
               public double height;   // Height of a box
            }
            
            class Boxtester {

                static void Main(string[] args) {
                    Box Box1 = new Box();   // Declare Box1 of type Box
                    Box Box2 = new Box();   // Declare Box2 of type Box
                    double volume = 0.0;    // Store the volume of a box here

                    // box 1 specification
                    Box1.height = 5.0;
                    Box1.length = 6.0;
                    Box1.breadth = 7.0;

                    // box 2 specification
                    Box2.height = 10.0;
                    Box2.length = 12.0;
                    Box2.breadth = 13.0;
                   
                    // volume of box 1
                    volume = Box1.height * Box1.length * Box1.breadth;
                    Console.WriteLine("Volume of Box1 : {0}",  volume);

                    // volume of box 2
                    volume = Box2.height * Box2.length * Box2.breadth;
                    Console.WriteLine("Volume of Box2 : {0}", volume);
                    Console.ReadKey();
                }
            }
        }

### 封装
        using System;

        namespace BoxApplication {

           class Box {
              private double length;   // Length of a box
              private double breadth;  // Breadth of a box
              private double height;   // Height of a box
              
              public void setLength( double len ) {
                 length = len;
              }
              
              public void setBreadth( double bre ) {
                 breadth = bre;
              }
              
              public void setHeight( double hei ) {
                 height = hei;
              }
              public double getVolume() {
                 return length * breadth * height;
              }
           }
           
           class Boxtester {
           
              static void Main(string[] args) {
                 Box Box1 = new Box();   // Declare Box1 of type Box
                 Box Box2 = new Box();
                 double volume;
                 
                 // Declare Box2 of type Box
                 // box 1 specification
                 Box1.setLength(6.0);
                 Box1.setBreadth(7.0);
                 Box1.setHeight(5.0);
                 
                 // box 2 specification
                 Box2.setLength(12.0);
                 Box2.setBreadth(13.0);
                 Box2.setHeight(10.0);
                 
                 // volume of box 1
                 volume = Box1.getVolume();
                 Console.WriteLine("Volume of Box1 : {0}" ,volume);
                 
                 // volume of box 2
                 volume = Box2.getVolume();
                 Console.WriteLine("Volume of Box2 : {0}", volume);
                 
                 Console.ReadKey();
              }
           }
        }

### 构造器
        using System;

        namespace LineApplication {

           class Line {
              private double length;   // Length of a line
              
              public Line() {
                 Console.WriteLine("Object is being created");
              }

              public void setLength( double len ) {
                 length = len;
              }
              
              public double getLength() {
                 return length;
              }

              static void Main(string[] args) {
                 Line line = new Line();    
                 
                 // set line length
                 line.setLength(6.0);
                 Console.WriteLine("Length of line : {0}", line.getLength());
                 Console.ReadKey();
              }
           }
        }

### 静态成员
        using System;

        namespace StaticVarApplication {

           class StaticVar {
              public static int num;
              
              public void count() {
                 num++;
              }
              
              public int getNum() {
                 return num;
              }
           }
           
           class StaticTester {
           
              static void Main(string[] args) {
                 StaticVar s1 = new StaticVar();
                 StaticVar s2 = new StaticVar();
                 s1.count();
                 s1.count();
                 s1.count();
                 s2.count();
                 s2.count();
                 s2.count();
                 Console.WriteLine("Variable num for s1: {0}", s1.getNum());
                 Console.WriteLine("Variable num for s2: {0}", s2.getNum());
                 Console.ReadKey();
              }
           }
        }

### 类的继承
        using System;

        namespace InheritanceApplication {
           
           class Shape {
              
              public void setWidth(int w) {
                 width = w;
              }
              
              public void setHeight(int h) {
                 height = h;
              }
              protected int width;
              protected int height;
           }

           // Derived class
           class Rectangle: Shape {
              
              public int getArea() { 
                 return (width * height); 
              }
           }
           
           class RectangleTester {
           
              static void Main(string[] args) {
                 Rectangle Rect = new Rectangle();

                 Rect.setWidth(5);
                 Rect.setHeight(7);

                 // Print the area of the object.
                 Console.WriteLine("Total area: {0}",  Rect.getArea());
                 Console.ReadKey();
              }
           }
        }
        
### 类的继承-父类的初始化
        using System;

        namespace RectangleApplication {

           class Rectangle {
              //member variables
              protected double length;
              protected double width;
              
              public Rectangle(double l, double w) {
                 length = l;
                 width = w;
              }
              
              public double GetArea() {
                 return length * width;
              }
              
              public void Display() {
                 Console.WriteLine("Length: {0}", length);
                 Console.WriteLine("Width: {0}", width);
                 Console.WriteLine("Area: {0}", GetArea());
              }
           }//end class Rectangle  
           
           class Tabletop : Rectangle {
              private double cost;
              public Tabletop(double l, double w) : base(l, w) { }
              
              public double GetCost() {
                 double cost;
                 cost = GetArea() * 70;
                 return cost;
              }
              
              public void Display() {
                 base.Display();
                 Console.WriteLine("Cost: {0}", GetCost());
              }
           }
           
           class ExecuteRectangle {
              
              static void Main(string[] args) {
                 Tabletop t = new Tabletop(4.5, 7.5);
                 t.Display();
                 Console.ReadLine();
              }
           }
        }
        /*
        Length: 4.5
        Width: 7.5
        Area: 33.75
        Cost: 2362.5
        */
        
### 类的继承-多继承
        using System;

        namespace InheritanceApplication {
           
           class Shape {
              
              public void setWidth(int w) {
                 width = w;
              }
              
              public void setHeight(int h) {
                 height = h;
              }
              protected int width;
              protected int height;
           }

           // Base class PaintCost
           public interface PaintCost {
              int getCost(int area);
           }
           
           // Derived class
           class Rectangle : Shape, PaintCost {
              
              public int getArea() {
                 return (width * height);
              }
              
              public int getCost(int area) {
                 return area * 70;
              }
           }
           
           class RectangleTester {
              
              static void Main(string[] args) {
                 Rectangle Rect = new Rectangle();
                 int area;
                 Rect.setWidth(5);
                 Rect.setHeight(7);
                 area = Rect.getArea();
                 
                 // Print the area of the object.
                 Console.WriteLine("Total area: {0}",  Rect.getArea());
                 Console.WriteLine("Total paint cost: ${0}" , Rect.getCost(area));
                 Console.ReadKey();
              }
           }
        }

### 类的多态-方法重载
        using System;

        namespace PolymorphismApplication {

           class Printdata {
           
              void print(int i) {
                 Console.WriteLine("Printing int: {0}", i );
              }

              void print(double f) {
                 Console.WriteLine("Printing float: {0}" , f);
              }

              void print(string s) {
                 Console.WriteLine("Printing string: {0}", s);
              }
              
              static void Main(string[] args) {
                 Printdata p = new Printdata();
                 
                 // Call print to print integer
                 p.print(5);
                 
                 // Call print to print float
                 p.print(500.263);
                 
                 // Call print to print string
                 p.print("Hello C++");
                 Console.ReadKey();
              }
           }
        }
        
### 类的多态-动态多态
        using System;

        namespace PolymorphismApplication {

           abstract class Shape {
              public abstract int area();
           }
           
           class Rectangle:  Shape {
              private int length;
              private int width;
              
              public Rectangle( int a = 0, int b = 0) {
                 length = a;
                 width = b;
              }
              
              public override int area () { 
                 Console.WriteLine("Rectangle class area :");
                 return (width * length); 
              }
           }

           class RectangleTester {
              
              static void Main(string[] args) {
                 Rectangle r = new Rectangle(10, 7);
                 double a = r.area();
                 Console.WriteLine("Area: {0}",a);
                 Console.ReadKey();
              }
           }
        }

### 类的多态-抽象类和虚方法
        using System;

        namespace PolymorphismApplication {

           class Shape {
              protected int width, height;
              
              public Shape( int a = 0, int b = 0) {
                 width = a;
                 height = b;
              }
              
              public virtual int area() {
                 Console.WriteLine("Parent class area :");
                 return 0;
              }
           }
           
           class Rectangle: Shape {
              public Rectangle( int a = 0, int b = 0): base(a, b) {

              }
              
              public override int area () {
                 Console.WriteLine("Rectangle class area :");
                 return (width * height); 
              }
           }
           
           class Triangle: Shape {
              public Triangle(int a = 0, int b = 0): base(a, b) {
              
              }
              
              public override int area() {
                 Console.WriteLine("Triangle class area :");
                 return (width * height / 2); 
              }
           }
           
           class Caller {
              public void CallArea(Shape sh) {
                 int a;
                 a = sh.area();
                 Console.WriteLine("Area: {0}", a);
              }
           }  
           
           class Tester {

              static void Main(string[] args) {
                 Caller c = new Caller();
                 Rectangle r = new Rectangle(10, 7);
                 Triangle t = new Triangle(10, 5);
                 c.CallArea(r);
                 c.CallArea(t);
                 Console.ReadKey();
              }
           }
        }