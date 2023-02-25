#include "stdafx.h"
#include "Action.h"
#include "Proto/protocol.pb.h"

void ActionList::Push(ActionRef action)
{
	mActionList.push_back(action);
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
