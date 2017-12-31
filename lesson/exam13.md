### (1)
#### c++读取本地记事本web.txt
```
#include <iostream>
#include <string>
#include <fstream>

int main()
{
	std::ifstream ifstream("web.txt");
	std::string string((std::istreambuf_iterator<char>(ifstream)), std::istreambuf_iterator<char>());
	ifstream.close();
	std::cout << string;

	return 0;
}
```

#### 用json方法，获得第一个股票华虹电子和最后一个股票深发展A的几处信息（confer_no，prod_code，entrust_amount）
```
#include <iostream>
#include <fstream>
#include <rapidjson/document.h>

int main()
{
	std::ifstream ifstream("web.txt");
	std::string string((std::istreambuf_iterator<char>(ifstream)), std::istreambuf_iterator<char>());
	ifstream.close();

	rapidjson::Document document;
	document.Parse(string.c_str());
	const rapidjson::Value& data = document["data"];

	rapidjson::Value::ConstValueIterator it = data.Begin();
	std::cout << "prod_name      :" << (*it)["prod_name"].GetString() << std::endl;
	std::cout << "confer_no      :" << (*it)["confer_no"].GetString() << std::endl;
	std::cout << "prod_code      :" << (*it)["prod_code"].GetString() << std::endl;
	std::cout << "entrust_amount :" << (*it)["entrust_amount"].GetString() << std::endl;

	it = data.End() - 1;
	std::cout << "prod_name      :" << (*it)["prod_name"].GetString() << std::endl;
	std::cout << "confer_no      :" << (*it)["confer_no"].GetString() << std::endl;
	std::cout << "prod_code      :" << (*it)["prod_code"].GetString() << std::endl;
	std::cout << "entrust_amount :" << (*it)["entrust_amount"].GetString() << std::endl;

	return 0;
}
```

#### 除了json，如果还有其他方法可以实现这个功能，也可以择优写一些。 
- [RapidJSON官网](http://rapidjson.org/) 
- [28个C/C++ JSON库测评](https://www.zhihu.com/question/23654513)

### (2) c++一些常用代码整理
#### 保存信息到本地记事本
```
#include <iostream>
#include <string>
#include <fstream>

int main()
{
	std::string string = "hello\r\nworld";
	std::ofstream ofstream("helloworld.txt", std::ios::binary | std::ios::out);
	ofstream << string;
	ofstream.close();

	return 0;
}
```

#### 计时器，每5秒显示helloword
```
#include <iostream>
#include <boost/thread.hpp>
#include <boost/asio/steady_timer.hpp>

using namespace boost;

class TimerTest
{
public:
	void time_out(system::error_code ec, std::shared_ptr<asio::steady_timer> timer)
	{
		std::cout << "Hello world" << std::endl;
		timer->expires_from_now(chrono::seconds(5));
		timer->async_wait(std::bind(&TimerTest::time_out, this, std::placeholders::_1, timer));
	};

	int test()
	{
		asio::io_service ios;
		std::shared_ptr<asio::steady_timer> timer(new asio::steady_timer(ios));
		timer->expires_from_now(chrono::seconds(5));
		timer->async_wait(std::bind(&TimerTest::time_out, this, std::placeholders::_1, timer));
		thread thread([&ios](){ios.run();});
		std::cin.get();
		return 0;
	};
};

int main()
{
	TimerTest timer_test;
	timer_test.test();

	return 0;
}
```

#### 获取系统时间，以及转换为时间戳

- Boost.Chrono vs. Boost.Date_Time  

From Boost.Chrono's documentation:

> Boost.Chrono aims to implement the new time facilities in C++0x, as proposed in N2661 - A Foundation to Sleep On. That document provides background and motivation for key design decisions and is the source of a good deal of information in this documentation.  

1. More specifically, Boost.DateTime is about, well, **dates and times**. It has lots of functions for formatting dates for display according to locales and various other things. But there are also functions for getting dates and times, as well as operating on them.  
2. Boost.Chrono seems focused on dealing with **time intervals**. It has no measurement higher than "hours", and it has no concept of date at all. Indeed, moments in time are only supported as offsets to a particular moment in time (time since process started, time since a fixed "epoch" like Jan 1, 1970, etc).  
3. The two seem complementary, rather than competing, though there is some overlap. There is a lot that DateTime does that Chrono doesn't, and there are some things that Chrono does that DateTime doesn't. Sadly, there doesn't seem to be any interop between the two, so one will have to hand-convert Chrono's durations into DateType's equivalent.  

```
#include <iostream>
#include <boost/chrono.hpp>

using namespace boost;

int main()
{
	chrono::system_clock::time_point now = chrono::system_clock::now();
	long long stamp_second = now.time_since_epoch().count()/1000000;
	long long stamp_millisecond = now.time_since_epoch().count()/1000;
	std::cout << stamp_second << std::endl;
	std::cout << stamp_millisecond << std::endl;

	std::cin.get();
	return 0;
}
```

#### 退出控制台
```
exit(1);
```

#### 调用识别验证码程序 sb.exe案例
```
#include <iostream>
#include <fstream>
#include <string>
#include <boost/thread.hpp>

using namespace boost;

int main()
{
	std::system("dir > test.txt");
	this_thread::sleep_for(chrono::seconds(2));

	std::ifstream ifstream("test.txt");
	std::string string((std::istreambuf_iterator<char>(ifstream)), std::istreambuf_iterator<char>());
	ifstream.close();
    
	std::cout << string << std::endl;

	std::cin.get();
	return 0;
}
```

### (3) 广发证券自动登录  
http://hippo.gf.com.cn/  左上角登录--交易登录，用户名 1502006409988 密码 2986938 ，测试自动登录  
**可在服务器做转发**  
- 服务器代码 WebService.asmx
```
<%@ WebService Language="C#" Class="WebService" %>

using System;
using System.Collections.Generic;
using System.Web.Services;

[WebService(Namespace = "http://tempuri.org/")]
[WebServiceBinding(ConformsTo = WsiProfiles.BasicProfile1_1)]
public class WebService : System.Web.Services.WebService
{

    [WebMethod]
    public string HelloWorld()
    {
        return "Hello World";
    }

    [WebMethod]
    public List<Person> Persons()
    {
        List<Person> persons = new List<Person>();
        persons.Add(new Person { Id = 0, Name = "Mike", Birthday = DateTime.Parse("1988-06-16") });
        persons.Add(new Person { Id = 1, Name = "赵云", Birthday = DateTime.Parse("1888-10-08") });
        return persons;
    }

}

public class Person
{
    public int Id { get; set; }
    public string Name { get; set; }
    public DateTime Birthday { get; set; }
}
```

- 生成客户端类文件WebService.cs
```
wsdl http://127.0.0.1/web/WebService.asmx?WSDL /out:WebService.cs
```

- 客户端代码
```
using System;

namespace ConsoleApplication1
{
    class Program
    {
        static void Main(string[] args)
        {
            WebService web = new WebService();
            Console.WriteLine(web.HelloWorld());

            var persons = web.Persons();
            foreach (var person in persons)
            {
                Console.WriteLine("Id={0}, Name={1}, Birthdat={2}", person.Id, person.Name, person.Birthday.ToString("yyyy-MM-dd"));
            }
        }
    }
}
```
