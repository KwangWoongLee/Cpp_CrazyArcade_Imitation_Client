#include "stdafx.h"
#include "Action.h"
#include "Proto/protocol.pb.h"

void ActionList::Push(ActionRef action)
{
	if (mActionList.size() > 0)
	{
		if (mActionList[mActionList.size()-1] == action)
			return;
	}

	mActionList.push_back(action);
	++mActionCount;
}

void ActionList::PushFront(ActionRef action)
{
	if (mActionList.size() > 0)
	{
		if (mActionList[0] == action)
			return;
	}

	mActionList.push_front(action);
	++mActionCount;
}

ActionRef ActionList::Pop()
{
	if (mActionCount == 0) return nullptr;

	auto action = mActionList.front();
	mActionList.pop_front();
	--mActionCount;

	return action;
}
