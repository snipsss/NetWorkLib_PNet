// client code 

#include <PNet/includeME.h>
#include <iostream>
#include <unistd.h>
#define Sleep(duration) usleep(duration *1000)

using namespace PNet;

int main() 
{
	if (PNet::NetWork::initiaise())
	{
		std::cout << "Winsock APi Sucksefully created!" << std::endl;
		Socket socket;
		if (socket.Create() == Result::P_sucksess)
		{
			std::cout << "Socket Succsessfully created!" << std::endl;	
			if(socket.Connect(IpEndPoint("192.168.21.139",5000)) == Result::P_sucksess)
			{
				std::cout << "Client Successfully connected on server!" << std::endl;
				
				
				Packet StringPacket(PacketType::PT_ChatMessage);
				StringPacket << std::string("https://stackoverflow.com/questions/5136295/switch-transfer-of-control-bypasses-initialization-of-when-calling-a-function");

				Packet IntPacket(PacketType::PT_integerArray);
				uint32_t arraySize = 6;
				uint32_t intArry[6] = { 2,41,22,23,12,1 };
				IntPacket << arraySize;
				for(auto integer: intArry)
				{
					IntPacket << integer;
				}
				while(true)
				{
					Result res; 
					if(rand() % 2 == 0)
					{
						res = socket.SendIt(StringPacket);
					}
					else
					{
						res = socket.SendIt(IntPacket);
					}
					if(res != Result::P_sucksess)
						break;
					
					std::cout << "Attempint to send chunk of data!..." << std::endl;
					Sleep(500);
				}
			}
			else
			{
				std::cerr << "Cliend connetion failed!" << std::endl;
			}
			socket.CloseSocket();
		}
		else
		{
			std::cerr << "We cant create a socket!: " << WSAGetLastError() << std::endl;	
		}
	}
	PNet::NetWork::shoutDown();
	system("pause");

}