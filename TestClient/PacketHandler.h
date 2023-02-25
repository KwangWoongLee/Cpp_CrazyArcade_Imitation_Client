#pragma once

extern std::vector<function<void(ServerSessionRef,PacketRef)>> HandleFuncs;

class PacketHandler
{
public:
	static void Init();
	static void S_PING(ServerSessionRef session, PacketRef packet);
	static void S_ENTER_GAME(ServerSessionRef session, PacketRef packet);
	static void S_SPAWN(ServerSessionRef session, PacketRef packet);
	static void S_DESPAWN(ServerSessionRef session, PacketRef packet);
	static void S_ACTION(ServerSessionRef session, PacketRef packet);
};
