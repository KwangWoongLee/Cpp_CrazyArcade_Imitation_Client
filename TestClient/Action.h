#pragma once
#include "Proto/protocol.pb.h"

class Action
{
public:
	Action() = default;
	Action(const Protocol::Action& action, float timestamp, float deltaTime) :
		mAction(action),
		mTimestamp(timestamp),
		mDeltaTime(deltaTime)
	{}

	Protocol::Action GetAction() { return mAction; };
	float				GetTimestamp()	const { return mTimestamp; }
	float				GetDeltaTime()	const { return mDeltaTime; }


private:
	Protocol::Action		mAction;
	float					mTimestamp;
	float					mDeltaTime;

};

class ActionList
{
public:
	ActionList() {};
	~ActionList() {
	}

	void Push(ActionRef action);
	ActionRef Pop();

	void Clear() {
		mActionList.clear();
		mActionCount = 0;
	};

	bool IsEmpty() const { return mActionCount == 0; };
	uint32 GetSize() const { return mActionCount; };

	const ActionRef operator[](size_t i)	const { return mActionList[i]; }

private:
	std::deque<ActionRef>	mActionList;
	uint32					mActionCount = 0;
};