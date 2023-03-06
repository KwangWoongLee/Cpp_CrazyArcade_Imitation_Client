#pragma once

extern std::vector<function<void(PacketSessionRef, PacketHeader, google::protobuf::io::CodedInputStream&)>> HandleFuncs;

class PacketHandler
{
public:
	static void Init();
	static void S_TEST(PacketSessionRef, PacketHeader, google::protobuf::io::CodedInputStream&);
};
