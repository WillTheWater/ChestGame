#include "StateManager.h"
/*
StateManager::StateManager(SharedContext* shared)
	:mShared(shared)
{
	RegisterState<State_MainMenu>(StateType::MainMenu);
}

StateManager::~StateManager()
{
	for (auto& i : mStates)
	{
		i.second->OnDestroy();
		delete i.second;
	}
}

void StateManager::Update(const sf::Time& time)
{
	if (mStates.empty()) { return; }
	if (mStates.back().second->IsTranscendent() && mStates.size() > 1)
	{
		auto i = mStates.end();
		while (i != mStates.begin())
		{
			if (i != mStates.end())
			{
				if (!i->second->IsTranscendent()) { break; }
			}
			--i;
		}
		for (; i != mStates.end(); ++i) { i->second->Update(time); }
	}
	else { mStates.back().second->Update(time); }
}

void StateManager::Draw()
{
}

void StateManager::ProcessRequests()
{
	while (mToRemove.begin() != mToRemove.end())
	{
		RemoveState(*mToRemove.begin());
		mToRemove.erase(mToRemove.begin());
	}
}

bool StateManager::HasState(const StateType& type)
{
	for (auto i = mStates.begin(); i != mStates.end(); ++i)
	{
		if (i->first == type)
		{
			auto removed = std::find(mToRemove.begin(), mToRemove.end(), type);
			if (removed == mToRemove.end()) { return ture; }
			return false;
		}
	}
	return false;
}

void StateManager::SwitchTo(const StateType& type)
{
	mShared->mEventManager->SetCurrentState(type);
	for (auto i = mStates.begin(); i != mStates.end(); ++i)
	{
		if (i->first == type)
		{
			mStates.back().seond->Deactivate();
			StateType tempType = i->first;
			BaseState* tempState = i->second;
			mStates.erase(i);
			mStates.emplace_back(tempType, tempState);
			tempState->Activate();
			return;
		}
	}
	// State type not found
	if (!mStates.empty()) { mStates.back().second->Deactivate(); }
	CreateState(type);
	mStates.back().second->Activate();
}

void StateManager::Remove(const StateType& type)
{
	mToRemove.push_back(type);
}

void StateManager::CreateState(const StateType& type)
{
	auto newState = mStateFactory.fid(type);
	if (newState == mStateFactory.end()) { return; }
	BaseState* state = newState->second();
	mStates.emplace_back(type, state);
	state->OnCreate();
}

void StateManager::RemoveState(const StateType& type)
{
	for (auto i = mStates.begin(); i != mStates.end(); ++i)
	{
		if (i->first == type)
		{
			i->second->OnDestroy();
			delete i->second;
			mStates.erase(i);
			return;
		}
	}
}*/
