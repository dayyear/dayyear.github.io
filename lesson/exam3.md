### POST
	public static string Post(string uri, string postString)
    {
        string responseString;
    
        var request = (HttpWebRequest)WebRequest.Create(uri);
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
    
### GET
    public static string Get(string uri)
    {
        string responseString;
    
        var request = (HttpWebRequest)WebRequest.Create(uri);
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