 #pragma once
#define WIN32_LEAN_AND_MEAN
#include <vector>
#include <winsock.h>
#include <iostream>
#include "PacketExc.h"
#include "PacketType.h"
namespace PNet
{
	struct Packet
	{
	public:
		
		Packet(PacketType packetType = PacketType::PT_invalid);
		std::vector<char> m_buffer;
		uint32_t absOffSet = 0;

		void AssignPacketType(PacketType packetType);
		PacketType getType();

		void clearPacket();
		void append(const void* data, uint32_t size);
		Packet& operator <<(uint32_t data);
		Packet& operator >>(uint32_t& data);
		Packet& operator <<(const std::string& data);
		Packet& operator >>(std::string & data);
	};


}