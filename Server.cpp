#define _WINSOCK_DEPRECATED_NO_WARNINGS
#include "Server.h"

using namespace std;


void main() {
	long SUCCESSFUL;
	WSADATA WinsockData;
	WORD DLLVERSION;

	DLLVERSION = MAKEWORD(2, 1);
	SUCCESSFUL = WSAStartup(DLLVERSION,&WinsockData);
	SOCKADDR_IN Address;
	int addressSize = sizeof(Address);
	SOCKET SOCK_LISTEN;
	SOCKET SOCK_CONNECTION;

	SOCK_CONNECTION = socket(AF_INET, SOCK_STREAM, NULL);
	Address.sin_family = AF_INET;
	Address.sin_addr.s_addr = inet_addr("127.0.0.1");
	Address.sin_port = htons(444);


	SOCK_LISTEN = socket(AF_INET, SOCK_STREAM, NULL);
	bind(SOCK_LISTEN, (SOCKADDR*)&Address, sizeof(Address));
	listen(SOCK_LISTEN, SOMAXCONN);


	for (;;) {
		cout << "Server Waiting For Incoming Connection.......\n";
		if (SOCK_CONNECTION = accept(SOCK_LISTEN, (SOCKADDR*)&Address, &addressSize)) {
			cout << "\n\t A connection was found!\n";
			SUCCESSFUL = send(SOCK_CONNECTION, "Welcome You Have Connected to Local Host", 50, NULL);
		}
	}


}