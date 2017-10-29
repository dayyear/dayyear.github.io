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

### 使用构造器
        using System;

        namespace LineApplication {

           class Line {
              private double length;   // Length of a line
              
              public Line(double len) {  //Parameterized constructor
                 Console.WriteLine("Object is being created, length = {0}", len);
                 length = len;
              }

              public void setLength( double len ) {
                 length = len;
              }
              
              public double getLength() {
                 return length;
              }

              static void Main(string[] args) {
                 Line line = new Line(10.0);
                 Console.WriteLine("Length of line : {0}", line.getLength()); 
                 
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

### 使用静态成员
        using System;

        namespace StaticVarApplication {

           class StaticVar {
              public static int num;
              
              public void count() {
                 num++;
              }
              
              public static int getNum() {
                 return num;
              }
           }
           
           class StaticTester {
           
              static void Main(string[] args) {
                 StaticVar s = new StaticVar();
                 s.count();
                 s.count();
                 s.count();
                 Console.WriteLine("Variable num: {0}", StaticVar.getNum());
                 Console.ReadKey();
              }
           }
        }