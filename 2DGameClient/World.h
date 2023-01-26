#pragma once

class World
{
public:
	void AddActor(ActorRef actorRef);
	void RemoveActor(ActorRef actorRef);
	
	void Update(float deltaTime);

	bool EnterWorld(Protocol::S_ENTER_GAME& pkt);

private:
	Vector<ActorRef> mActors;
	Map<uint64, ActorRef> mActorMap;
};


extern shared_ptr<World> GWorld;