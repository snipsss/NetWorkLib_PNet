// server code	
#include <PNet\includeME.h>
#include <iostream>

using namespace PNet;

bool ProcessPacket(Packet& packet)
{
	switch (packet.getType())
	{
	case PacketType::PT_ChatMessage:
	{
		std::string chatMessage;
		packet >> chatMessage;
		std::cout << "Chat Message: " << chatMessage << std::endl;
		break;
	}
	case PacketType::PT_integerArray:
	{
		uint32_t arraySize = 0;
		packet >> arraySize;
		std::cout << "Array Size: " << arraySize << std::endl;
		for (uint32_t i = 0; i < arraySize; i++)
		{
			uint32_t element = 0;
			packet >> element;
			std::cout << "Element [" << i << "] - " << element << std::endl;
		}
		break;
	}
	default:
		return false;
	}

	return true;

}

int main()
{
	if (PNet::NetWork::initiaise())
	{
		std::cout << "Winsock APi Sucksefully created!" << std::endl;
		Socket socket;
		//142.93.5.18
		if (socket.Create() == Result::P_sucksess)
		{
			std::cout << "Socket succsessfully created!" << std::endl;

			if (PNet::Validator::isValidIp(PNet::ipArrdServer)) {
				std::cout << "Ip Server is valid!" << std::endl;
				if (socket.Listen(IpEndPoint(PNet::ipArrdServer, PNet::port)) == Result::P_sucksess)
				{
					std::cout << "Socket successfully listening on:"<< PNet::port << std::endl;
					Socket newConnection;
					if (socket.Accpet(newConnection) == Result::P_sucksess)
					{
						std::cout << "New connection Accepted!" << std::endl;

						Packet packet;
						while (true)
						{
							Result res = newConnection.Recvive(packet);
							/*if (res != Result::P_sucksess)
							{
								break;
							}
							*/
							if (!ProcessPacket(packet)) { break; }
						}
						newConnection.CloseSocket();
					}
					else
					{
						std::cerr << "failed! to accept new connection! " << std::endl;
					}
				}
				else
				{
					std::cerr << "Failed listening on port 4023!" << std::endl;
				}
			}
			else
			{
				std::cerr << "Ip is not Valid!" << std::endl;	
			}
		}
	}
}
