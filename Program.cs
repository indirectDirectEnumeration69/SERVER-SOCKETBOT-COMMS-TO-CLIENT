using System;
using System.IO;
using System.Net;
using System.Net.Sockets;
using System.Text;

namespace ProjectWorm
{
    public static class ProgramStart
    {
        public static void Main(string[] args)
        {
            IPAddress ipAddress = IPAddress.Parse("127.0.0.1");
            TcpListener listener = new TcpListener(ipAddress, 5555);
            listener.Start();

            HttpClient httpClient = new HttpClient();
            var url = new Uri("https://www.google.com/");
            var response = httpClient.GetAsync(url).Result;
            var p= new Dictionary<string, string>();
            Console.WriteLine("\n" + p.ToString());
            Console.WriteLine(response.ToString());//change to recursive
            Console.WriteLine("RESPONSE ON PORTS:" + httpClient.DefaultRequestHeaders.AcceptEncoding.ToString());
            Console.WriteLine("GOT PORT SCAN");
            Console.WriteLine(url.AbsolutePath.ToString());
            Console.WriteLine("Raw Url:" + url.AbsoluteUri.ToString());
            
            
        }//UNFINISHED MORE OF A LEARNING THING  
    }
}




