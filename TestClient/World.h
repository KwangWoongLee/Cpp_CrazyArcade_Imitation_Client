#pragma once

class World
{
public:
	void AddActor(ActorRef actorRef);
	void RemoveActor(ActorRef actorRef);
	
	void Update(float deltaTime);

	bool EnterWorld(Protocol::S_ENTER_GAME& pkt);

private:
	std::vector<ActorRef> mActors;
	std::map<uint64, ActorRef> mActorMap;
};


extern shared_ptr<World> GWorld;