### 读取配置文件
        <?xml version="1.0" encoding="utf-8" ?>
        <configuration>
          <appSettings>
            <add key="Name" value="Mike"/>
            <add key="Age" value="29"/>
          </appSettings>
        </configuration>

        using System;
        using System.Configuration;

        namespace ConsoleApplication1
        {
            class Program
            {
                static void Main(string[] args)
                {
                    Console.WriteLine(ConfigurationManager.AppSettings["Name"]);
                    Console.WriteLine(ConfigurationManager.AppSettings["Age"]);
                }
            }
        }

### 显示当前时间
        using System;

        namespace ConsoleApplication1
        {
            class Program
            {
                static void Main(string[] args)
                {
                    Console.WriteLine(DateTime.Now.ToString("yyyy-MM-dd HH:mm:ss.fff"));
                }
            }
        }

### 定时器
        using System;
        using System.Timers;

        namespace ConsoleApplication1
        {
            class Program
            {
                static void Main(string[] args)
                {
                    var a = new TimerTest();
                    a.Test();
                }
            }//class Program

            class TimerTest
            {
                public void Test()
                {
                    Run();
                    using (var t = new Timer(1000))
                    {
                        t.Elapsed += TimeOut;
                        t.AutoReset = true; //设置是执行一次（false）还是一直执行(true)；   
                        t.Enabled = true;   //是否执行System.Timers.Timer.Elapsed事件； 
                        Console.ReadLine();
                    }
                }//Test

                private void TimeOut(object source, ElapsedEventArgs e)
                {
                    Run();
                }//TimeOut

                private void Run()
                {
                    Console.WriteLine("OK!");
                }//Run
            }//class TimerTest
        }//namespace


