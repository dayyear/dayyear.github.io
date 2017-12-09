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