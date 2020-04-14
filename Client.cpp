#define _WINSOCK_DEPRECATED_NO_WARNINGS
#include "Client.h"

using namespace std;

void main() {
	long SUCCESSFUL;
	WSADATA WinsockData;
	WORD DLLVERSION;

	DLLVERSION = MAKEWORD(2, 1);
	SUCCESSFUL = WSAStartup(DLLVERSION, &WinsockData);

	string RESPONSE, CONVERTER;
	char Message[200];
	SOCKADDR_IN Address;
	SOCKET SOCK;
	SOCK = socket(AF_INET, SOCK_STREAM, NULL);
	Address.sin_family = AF_INET;
	Address.sin_port = htons(444);
	Address.sin_addr.s_addr = inet_addr("127.0.0.1");

	cout << "CLIENT: Do you want to connect to the server? : Y/N";
	cin >> RESPONSE;
	RESPONSE[0] = tolower(RESPONSE[0]);
	if (RESPONSE[0] == 'n') {
		cout << "Exit.....\n";
	}

	else if (RESPONSE[0] == 'y') {
		connect(SOCK, (SOCKADDR*)&Address, sizeof(Address));
		SUCCESSFUL = recv(SOCK, Message, sizeof(Message), NULL);
		CONVERTER = Message;
		cout << "Message From Server: " << CONVERTER << endl;
	}

	else {
		cout << "Inappropriate Response\n";
	}

	cout << "\n\n";
	system("PAUSE");
	exit(1);
}