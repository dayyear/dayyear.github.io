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
            Get("http://sxd.xd.com/");
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

    }//class Web
}//namespace
```
