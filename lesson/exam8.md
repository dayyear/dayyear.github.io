### Http获取Cookies
```
using System;
using System.IO;
using System.Net;
using System.Text;

namespace ConsoleApplication1
{
    class Program
    {
        static void Main(string[] args)
        {
            var web = new Web();
            web.GetCookie();
        }
    }

    class Web
    {
        private readonly CookieContainer cookieContainer = new CookieContainer();

        public void GetCookie()
        {
            //Get("http://sxd.xd.com/");
            Post("http://sxd.xd.com/", string.Empty);
            var cookies = cookieContainer.GetCookies(new Uri("http://sxd.xd.com/"));
            foreach (Cookie cookie in cookies)
                Console.WriteLine(cookie);
        }//GetCookie

        private string Get(string uri)
        {
            string responseString;

            var request = (HttpWebRequest)WebRequest.Create(uri);
            request.CookieContainer = cookieContainer;
            request.Timeout = 600000;

            using (var response = (HttpWebResponse)request.GetResponse())
            using (var stream = response.GetResponseStream())
            {
                if (stream == null)
                    throw new Exception("stream = null");
                if (response.CharacterSet == null)
                    throw new Exception("response.CharacterSet = null");
                using (var sr = new StreamReader(stream, Encoding.GetEncoding(response.CharacterSet)))
                    responseString = sr.ReadToEnd();
            }

            return responseString;
        }//Get 

        private string Post(string uri, string postString)
        {
            string responseString;

            var request = (HttpWebRequest)WebRequest.Create(uri);
            request.CookieContainer = cookieContainer;
            request.Timeout = 600000;

            // 设置POST数据
            var postByte = Encoding.UTF8.GetBytes(postString);
            request.Method = "POST";
            request.ContentType = "application/x-www-form-urlencoded";
            request.ContentLength = postByte.Length;
            using (var stream = request.GetRequestStream())
                stream.Write(postByte, 0, postByte.Length);

            // 发送POST
            using (var response = (HttpWebResponse)request.GetResponse())
            using (var stream = response.GetResponseStream())
            {
                if (stream == null)
                    throw new Exception("stream = null");
                if (response.CharacterSet == null)
                    throw new Exception("response.CharacterSet = null");
                using (var sr = new StreamReader(stream, Encoding.GetEncoding(response.CharacterSet)))
                    responseString = sr.ReadToEnd();
            }

            return responseString;
        }//Post

    }//class Web
}//namespace
```

### Http设置Cookie
```
using System;
using System.IO;
using System.Net;
using System.Text;

namespace ConsoleApplication1
{
    class Program
    {
        static void Main(string[] args)
        {
            var web = new Web();
            web.GetCookie();
        }
    }

    class Web
    {
        private readonly CookieContainer cookieContainer = new CookieContainer();

        public void GetCookie()
        {
            cookieContainer.Add(new Uri("http://sxd.xd.com/"), new Cookie("name", "Mike"));
            cookieContainer.Add(new Uri("http://sxd.xd.com/"), new Cookie("date", "20170203"));

            //Get("http://sxd.xd.com/");
            Post("http://sxd.xd.com/", string.Empty);

        }//GetCookie

        private string Get(string uri)
        {
            string responseString;

            var request = (HttpWebRequest)WebRequest.Create(uri);
            request.CookieContainer = cookieContainer;
            request.Timeout = 600000;

            using (var response = (HttpWebResponse)request.GetResponse())
            using (var stream = response.GetResponseStream())
            {
                if (stream == null)
                    throw new Exception("stream = null");
                if (response.CharacterSet == null)
                    throw new Exception("response.CharacterSet = null");
                using (var sr = new StreamReader(stream, Encoding.GetEncoding(response.CharacterSet)))
                    responseString = sr.ReadToEnd();
            }

            return responseString;
        }//Get 

        private string Post(string uri, string postString)
        {
            string responseString;

            var request = (HttpWebRequest)WebRequest.Create(uri);
            request.CookieContainer = cookieContainer;
            request.Timeout = 600000;

            // 设置POST数据
            var postByte = Encoding.UTF8.GetBytes(postString);
            request.Method = "POST";
            request.ContentType = "application/x-www-form-urlencoded";
            request.ContentLength = postByte.Length;
            using (var stream = request.GetRequestStream())
                stream.Write(postByte, 0, postByte.Length);

            // 发送POST
            using (var response = (HttpWebResponse)request.GetResponse())
            using (var stream = response.GetResponseStream())
            {
                if (stream == null)
                    throw new Exception("stream = null");
                if (response.CharacterSet == null)
                    throw new Exception("response.CharacterSet = null");
                using (var sr = new StreamReader(stream, Encoding.GetEncoding(response.CharacterSet)))
                    responseString = sr.ReadToEnd();
            }

            return responseString;
        }//Post

    }//class Web
}//namespace
```

### 获取另一个窗口信息
```
using System;
using System.Runtime.InteropServices;
using System.Text;

namespace ConsoleApplication1
{

    class Program
    {

        [DllImport("user32.dll", SetLastError = true)]
        static extern IntPtr FindWindowEx(IntPtr hwndParent, IntPtr hwndChildAfter, string lpszClass, string lpszWindow);

        [DllImport("user32.dll", CharSet = CharSet.Auto)]
        static extern IntPtr SendMessage(IntPtr hWnd, UInt32 Msg, IntPtr wParam, [Out] StringBuilder lParam);

        static void Main(string[] args)
        {
            var a = FindWindowEx(IntPtr.Zero, IntPtr.Zero, null, "Form1");
            var b = FindWindowEx(a, IntPtr.Zero, "WindowsForms10.EDIT.app.0.2bf8098_r16_ad1", null);
            var sb = new StringBuilder(100);
            SendMessage(b, 0xD, (IntPtr)sb.Capacity, sb);
            Console.WriteLine(b);
            Console.WriteLine(sb);
        }
    }

}//namespace
```