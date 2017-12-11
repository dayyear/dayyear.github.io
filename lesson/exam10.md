### 原始线程与线程池测试
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
            ThreadPoolTest();
            OriginThreadTest();
        }//Main

        static void OriginThreadTest()
        {
            var t1 = DateTime.Now;
            var threads = new List<Thread>();
            for (var count = 0; count < 10000; count++)
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
            }
            var t2 = DateTime.Now;
            Console.WriteLine("原始线程测试，耗时[{0}]", t2.Subtract(t1));
        }//OriginThreadTest

        static void ThreadPoolTest()
        {
            var t1 = DateTime.Now;
            var exits = new ManualResetEvent[5];
            for (var count = 0; count < 10000; count++)
            {
                Alpha.done = false;
                for (var i = 0; i < 5; i++)
                {
                    exits[i] = new ManualResetEvent(false);
                    var alpha = new Alpha(exits[i]);
                    ThreadPool.QueueUserWorkItem(alpha.Beta, i);
                }
                WaitHandle.WaitAll(exits);
            }
            var t2 = DateTime.Now;
            Console.WriteLine("线程池测试，耗时[{0}]", t2.Subtract(t1));
        }//ThreadPoolTest

    }// class Program

    class Alpha
    {
        public static bool done;
        private ManualResetEvent exit;

        public Alpha()
        {
            exit = new ManualResetEvent(false);
            exit.Reset();
        }//Alpha

        public Alpha(ManualResetEvent exit)
        {
            this.exit = exit;
            this.exit.Reset();
        }//Alpha

        public void Beta(object parameter)
        {
            while (!done)
            {
                var now = DateTime.Now;
                //Console.WriteLine("[{1}] Alpha.Beta is running with parameter {0}.", parameter, now.ToString("HH:mm:ss"));
                done = true;
            }
            exit.Set();
        }//Beta

    }// class Alpha
}// namespace
```
