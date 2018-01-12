### c++处理cookies

```
#include <iostream>
#include <boost/asio.hpp>
#include <boost/algorithm/string.hpp>
#include <boost/regex.hpp>
#include <boost/lexical_cast.hpp>
#include <boost/locale.hpp>

class web
{
public:
	web();
	~web(void);

	void connect(const std::string& host, const std::string& port);
	void get(const std::string& request_uri, const std::string& request_http_version, const std::string& request_header,
	         std::string& response_http_version, unsigned int& status_code, std::string& status_message, std::string& response_header, std::string& response_body);

private:
	boost::asio::io_service ios;
	boost::asio::ip::tcp::resolver resolver;
	boost::asio::ip::tcp::socket sock;
	std::string host;
	std::string port;
};

int main()
{
	std::string response_http_version;
	unsigned int status_code;
	std::string status_message;
	std::string response_header;
	std::string response_body;
	try
	{
		// -------------------------------------------------------------------------------------------
		// Get 1
		// -------------------------------------------------------------------------------------------
		web web1;
		web1.connect("www.xd.com", "80");
		std::cout << "--------[ http://www.xd.com/games/play/play?app=sxd&server=s1 ]--------" << std::endl;
		web1.get("/games/play?app=sxd&server=s1", "HTTP/1.1", "Cookie: A1=9pv0jkvavd89rq0foheh0ovhc7\r\n", response_http_version, status_code, status_message, response_header, response_body);

		// -------------------------------------------------------------------------------------------
		// Analyze 1
		// -------------------------------------------------------------------------------------------
		boost::regex location_regex("Location: https?://(.*?)/(.*?)\r\n");
		boost::smatch match;
		if (!regex_search(response_header, match, location_regex))
			throw std::runtime_error("[Location]匹配出错");
		std::string host2(match[1]);
		std::string uri2("/" + match[2]);

		// -------------------------------------------------------------------------------------------
		// Get 2
		// -------------------------------------------------------------------------------------------
		web web2;
		web2.connect(host2, "80");
		std::cout << std::endl << "--------[ http://" << host2 << uri2 << " ]--------" << std::endl;
		web2.get(uri2, "HTTP/1.1", "", response_http_version, status_code, status_message, response_header, response_body);

		// -------------------------------------------------------------------------------------------
		// Analyze 2
		// -------------------------------------------------------------------------------------------
		std::list<std::string> cookies;
		boost::regex set_cookie_regex("Set-Cookie: (.*?);");
		for (auto it = boost::sregex_iterator(response_header.begin(), response_header.end(), set_cookie_regex); it != boost::sregex_iterator(); ++it)
			cookies.push_back((*it)[1]);
		if (cookies.size() == 0)
			throw std::runtime_error("[Set-Cookie]匹配出错");

		// -------------------------------------------------------------------------------------------
		// Get 3
		// -------------------------------------------------------------------------------------------
		uri2 = "/";
		std::cout << std::endl << "--------[ http://" << host2 << uri2 << " ]--------" << std::endl;
		web2.get(uri2, "HTTP/1.1", "Cookie: " + boost::algorithm::join(cookies, "; ") + "\r\n", response_http_version, status_code, status_message, response_header, response_body);

		std::cout << boost::locale::conv::between(response_body, "gbk", "utf-8");
	}
	catch (boost::system::system_error& e)
	{
		std::cout << "Error occured! Error code = " << e.code() << ". Message: " << e.what() << std::endl;
		return 1;
	}
	catch (std::exception& e)
	{
		std::cout << "Error occured! Message: " << e.what() << std::endl;
		return 1;
	}

	return 0;
}


web::web() :resolver(ios),sock(ios)
{
}

web::~web(void)
{
}

void web::connect(const std::string& host, const std::string& port)
{
	this->host = host;
	this->port = port;
	boost::asio::ip::tcp::resolver::query query(host, port);
	boost::asio::connect(sock, resolver.resolve(query));
}//web::connect

void web::get(const std::string& request_uri, const std::string& request_http_version, const std::string& request_header,
              std::string& response_http_version, unsigned& status_code, std::string& status_message, std::string& response_header, std::string& response_body)
{
	// stream
	boost::asio::streambuf request;
	std::ostream request_stream(&request);
	boost::asio::streambuf response;
	std::istream response_stream(&response);

	// Transfer-Encoding
	std::string transfer_encoding("");

	// Content-Length
	int content_length(-1);

	// -------------------------------------------------------------------------------------------
	// write
	// -------------------------------------------------------------------------------------------
	request_stream << "GET " << request_uri << " " << request_http_version << "\r\n";
	request_stream << "Host: " << host << "\r\n";
	request_stream << "User-Agent: " << "Mozilla/5.0 (Windows NT 6.1; WOW64) AppleWebKit/537.36 (KHTML, like Gecko) Chrome/55.0.2883.87 Safari/537.36" << "\r\n";
	request_stream << request_header << "\r\n";
	std::cout << "GET " << request_uri << " " << request_http_version << "\r\n";
	std::cout << "Host: " << host << "\r\n";
	std::cout << "User-Agent: " << "Mozilla/5.0 (Windows NT 6.1; WOW64) AppleWebKit/537.36 (KHTML, like Gecko) Chrome/55.0.2883.87 Safari/537.36" << "\r\n";
	std::cout << request_header << "\r\n";
	boost::asio::write(sock, request);

	// -------------------------------------------------------------------------------------------
	// read status line
	// -------------------------------------------------------------------------------------------
	boost::asio::read_until(sock, response, "\r\n");
	response_stream >> response_http_version;
	response_stream >> status_code;
	std::getline(response_stream, status_message);
	boost::algorithm::trim(status_message);

	// -------------------------------------------------------------------------------------------
	// read response header
	// -------------------------------------------------------------------------------------------
	std::ostringstream osstream;
	boost::asio::read_until(sock, response, "\r\n\r\n");
	boost::regex transfer_encoding_regex("Transfer-Encoding: (.*)");
	boost::regex content_length_regex("Content-Length: (.*)");
	std::string header;
	while (std::getline(response_stream, header) && header != "\r")
	{
		boost::algorithm::trim(header);
		boost::smatch match;
		osstream << header << "\r\n";
		if (regex_search(header, match, transfer_encoding_regex))
			transfer_encoding = boost::lexical_cast<std::string>(match[1]);
		if (regex_search(header, match, content_length_regex))
			content_length = boost::lexical_cast<int>(match[1]);
	}
	response_header = osstream.str();

	// -------------------------------------------------------------------------------------------
	// read response body
	// -------------------------------------------------------------------------------------------
	osstream.str("");
	if (transfer_encoding == "chunked")
	{
		content_length = 0;
		size_t chunk_size;
		do
		{
			boost::asio::read_until(sock, response, "\r\n");
			std::string chunk_size_string;
			std::getline(response_stream, chunk_size_string);
			chunk_size = std::stoi(chunk_size_string, nullptr, 16);
			content_length += chunk_size;

			if (chunk_size + 2 > response.size())
				boost::asio::read(sock, response, boost::asio::transfer_exactly(chunk_size + 2 - response.size()));
			std::unique_ptr<char[]> buff(new char[chunk_size + 2]);
			response_stream.read(buff.get(), chunk_size + 2);
			buff[chunk_size] = '\0';
			osstream << buff.get();
		}
		while (chunk_size > 0);
		response_body = osstream.str();
	}
	else if (content_length >= 0)
	{
		if (content_length > response.size())
			boost::asio::read(sock, response, boost::asio::transfer_exactly(content_length - response.size()));
		std::unique_ptr<char[]> buff(new char[content_length + 1]);
		response_stream.read(buff.get(), content_length);
		buff[content_length] = '\0';
		osstream << buff.get();
		response_body = osstream.str();
	}
	else
		throw std::runtime_error("未知的[Content-Length]");

	// -------------------------------------------------------------------------------------------
	// response body verification
	// -------------------------------------------------------------------------------------------
	if (response_body.length() != content_length)
		throw std::runtime_error("[Content-Length]与实际[Response-Body]长度不一致");

	std::cout << response_http_version << " " << status_code << " " << status_message << std::endl;
	std::cout << response_header << std::endl;
	std::cout << "Content-Length: " << response_body.length() << std::endl;
}//web::get
```

