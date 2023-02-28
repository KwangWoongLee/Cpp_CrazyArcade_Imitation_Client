#pragma once

extern std::vector<function<void(ServerSessionRef, PacketRef)>> HandleFuncs;

class PacketHandler
{
public:
	static void Init();
	static void S_ENTER_GAME(ServerSessionRef session, PacketRef packet);
};
