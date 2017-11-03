### WebClient Get典型用法
        using System;
        using System.IO;
        using System.Net;

        namespace ConsoleApplication1
        {
            class Program
            {
                static void Main(string[] args)
                {
                    string s;

                    using (var webClient = new WebClient())
                    using (var stream = webClient.OpenRead("http://news.baidu.com"))
                    using (var sr = new StreamReader(stream))
                        s = sr.ReadToEnd();

                    Console.WriteLine(s);
                }
            }
        }

### WebClient Post典型用法
        using System;
        using System.Collections.Specialized;
        using System.Net;
        using System.Text;

        namespace ConsoleApplication1
        {
            class Program
            {
                static void Main(string[] args)
                {
                    string s;

                    using (var webClient = new WebClient())
                    {
                        var nameValueCollection = new NameValueCollection();
                        nameValueCollection.Add("Name", "Mike");
                        s = Encoding.ASCII.GetString(webClient.UploadValues("http://news.baidu.com", nameValueCollection));
                    }

                    Console.WriteLine(s);
                }
            }
        }

### 突破.net最大连接数限制
        <system.net>
            <connectionManagement>
              <add address="*" maxconnection="512"/>
            </connectionManagement>
        </system.net>

