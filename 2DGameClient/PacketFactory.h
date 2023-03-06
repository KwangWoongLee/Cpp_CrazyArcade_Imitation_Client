#pragma once
#include "stdafx.h"

class Packet
{
public:
	PacketHeader									header;
	std::shared_ptr<google::protobuf::MessageLite> packet = nullptr;

};

class PacketFactory : public Singleton<PacketFactory>
{
public:
	PacketRef MakePacket(PacketHeader header, google::protobuf::io::CodedInputStream& payloadInputStream)
	{
		PacketRef packetRef = std::make_shared<Packet>();
		packetRef->header = header;
		packetRef->packet = nullptr;

		switch (header.id)
		{
		case 0:
		{
			packetRef->packet = std::make_shared<Protocol::S_PING>();
			break;
		}

		case 1:
		{
			packetRef->packet = std::make_shared<Protocol::S_ENTER_GAME>();
			break;
		}
		case 2:
		{
			packetRef->packet = std::make_shared<Protocol::S_SPAWN>();
			break;
		}
		case 3:
		{
			packetRef->packet = std::make_shared<Protocol::S_DESPAWN>();
			break;
		}
		case 4:
		{
			packetRef->packet = std::make_shared<Protocol::S_ACTION>();
			break;
		}
		case 5:
		{
			packetRef->packet = std::make_shared<Protocol::S_LEAVE_GAME>();
			break;
		}



		default:
			break;
		}

		if (packetRef->packet == nullptr) 
			return nullptr;

		if (false == packetRef->packet->ParseFromCodedStream(&payloadInputStream))
		{
			packetRef = nullptr;
			packetRef->packet = nullptr;
			return nullptr;
		}

		return packetRef;
	}
};