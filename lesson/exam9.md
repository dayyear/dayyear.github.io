### 多线程
```
using System;
using System.Threading;

namespace ConsoleApplication1
{
    class Program
    {
        static void Main(string[] args)
        {
            for (var i = 0; i < 5; i++)
            {
                var alpha = new Alpha();
                var thread = new Thread(alpha.Beta);
                thread.Start(i);
            }
        }//Main
    }// class Program

    class Alpha
    {
        private static bool done = false;
        public void Beta(object parameter)
        {
            while (!done)
            {
                var now = DateTime.Now;
                if (now.Second >= 30)
                    done = true;
                Console.WriteLine("[{1}] Alpha.Beta is running with parameter {0}.", parameter, now.ToString("HH:mm:ss"));
                Thread.Sleep(1000);
            }
        }//Beta
    }// class Alpha
}// namespace
```

### 多线程加互斥体
```
using System;
using System.Collections.Generic;
using System.Threading;

namespace ConsoleApplication1
{
    class Program
    {
        static void Main(string[] args)
        {
            var threads = new List<Thread>();
            while (true)
            {
                threads.Clear();
                Alpha.done = false;
                for (var i = 0; i < 5; i++)
                {
                    var alpha = new Alpha();
                    var thread = new Thread(alpha.Beta);
                    threads.Add(thread);
                    thread.Start(i);
                }
                threads.ForEach(thread => thread.Join());
                Thread.Sleep(10000);
            }
        }//Main
    }// class Program

    class Alpha
    {
        public static bool done;
        public void Beta(object parameter)
        {
            while (!done)
            {
                var now = DateTime.Now;
                Console.WriteLine("[{1}] Alpha.Beta is running with parameter {0}.", parameter, now.ToString("HH:mm:ss"));
                if (now.Second >= 0 && now.Second <= 5 && 1.Equals(parameter))
                {
                    using (var mtx = new Mutex(false, "Buy"))
                    {
                        if (mtx.WaitOne(0, false))
                        {
                            Console.WriteLine("[{1}] Buy with parameter {0}", parameter, now.ToString("HH:mm:ss"));
                            done = true;
                            mtx.ReleaseMutex();
                        }
                    }//mtx
                }
                Thread.Sleep(1000);
            }
        }//Beta
    }// class Alpha
}// namespace
```

### bug修复
```
using System;
using System.Collections.Generic;
using System.Threading;

namespace ConsoleApplication1
{
    class Program
    {
        static void Main(string[] args)
        {
            var threads = new List<Thread>();
            while (true)
            {
                threads.Clear();
                Alpha.done = false;
                for (var i = 0; i < 5; i++)
                {
                    var alpha = new Alpha();
                    var thread = new Thread(alpha.Beta);
                    threads.Add(thread);
                    thread.Start(i);
                }
                threads.ForEach(thread => thread.Join());
                Thread.Sleep(10000);
            }
        }//Main
    }// class Program

    class Alpha
    {
        public static bool done;
        public void Beta(object parameter)
        {
            while (!done)
            {
                var now = DateTime.Now;
                Console.WriteLine("[{1}] Alpha.Beta is running with parameter {0}.", parameter, now.ToString("HH:mm:ss"));
                if (now.Second >= 0 && now.Second <= 5)
                {
                    using (var mtx = new Mutex(false, "Buy"))
                    {
                        if (mtx.WaitOne(0, false) && !done)
                        {
                            Console.WriteLine("[{1}] Buy with parameter {0}", parameter, now.ToString("HH:mm:ss"));
                            done = true;
                            mtx.ReleaseMutex();
                        }
                    }//mtx
                }
                Thread.Sleep(1000);
            }
        }//Beta
    }// class Alpha
}// namespace
```
