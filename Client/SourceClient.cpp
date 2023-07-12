 // client code 
#include <PNet\includeMe.h>
#include <iostream>
using namespace PNet;

int main() 
{
	if (PNet::NetWork::initiaise())
	{

		//192.168.21.139",
		std::cout << "Winsock APi Sucksefully created!" << std::endl;
		Socket socket(IpVersion::IP_v4);
		if (socket.Create() == Result::P_sucksess)
		{
			std::cout << "Socket Succsessfully created!" << std::endl;

			if (PNet::Validator::isValidIp(PNet::ipClient)) {
				std::cout << "Ip client is Valid!" << std::endl; 
				if (socket.Connect(IpEndPoint(PNet::ipClient, PNet::port)) == Result::P_sucksess)
				{
					std::cout << "Client Successfully connected on server!" << std::endl;


					Packet StringPacket(PacketType::PT_ChatMessage);
					StringPacket << std::string("https://stackoverflow.com/questions/5136295/switch-transfer-of-control-bypasses-initialization-of-when-calling-a-function");

					Packet IntPacket(PacketType::PT_integerArray);
					uint32_t arraySize = 6;
					uint32_t intArry[6] = { 2,41,22,23,12,1 };
					IntPacket << arraySize;
					for (auto integer : intArry)
					{
						IntPacket << integer;
					}
					while (true)
					{
						Result res;
						if (rand() % 2 == 0)
						{
							res = socket.SendIt(StringPacket);
						}
						else
						{
							res = socket.SendIt(IntPacket);
						}
						if (res != Result::P_sucksess)
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
				std::cerr << "ip Client is not Valid!" << std::endl;
			}
		}
		else
		{
			std::cerr << "We cant create a socket!: " << WSAGetLastError() << std::endl;
		}

	}

	PNet::NetWork::shoutDown();
	system("pause");

}