#pragma once
#include "SocketHandle.h"
#include "Presult.h"
#include "IpVersion.h"
#include "SocketOption.h"
#include "IpEndPointr.h"
#include "Сonstant.h"
#include "Package.h"

namespace PNet
{
	class Socket
	{
	public:
			Socket(IpVersion ipversion = IpVersion::IP_v4, SocketHandle handle = INVALID_SOCKET);
			Result Create();
			Result CloseSocket();
			SocketHandle GetHandle();
			Result Bind(IpEndPoint endpoint);
			IpVersion GetIpVersion();
			Result Listen(IpEndPoint endpoint, int backlog = 5);
			Result Accpet(Socket& outSock);
			Result Connect(IpEndPoint endpoint);
			Result SendPackage(const void *data ,int numberofbytes,int& bytesSent);
			Result SentAllPackage(const void* destination, int numberOfBytes);
			Result Recv(void* destination, int numberofBytes, int& bytesRecives);
			Result RecvAll(void* data, int numberOfBytes);
			Result Recvive(Packet& packet);
			Result SendIt(Packet& packet);
	private:
		Result SetSocketOption(SocketOption option, BOOL value);
		IpVersion ipVersion = PNet::IP_v4;
		SocketHandle handle = INVALID_SOCKET;
	};
}






