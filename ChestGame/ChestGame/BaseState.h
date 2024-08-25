#pragma once
#include "SFML/System.hpp"

class StateManager;

class BaseState
{
	friend class StateManager;
public:
	BaseState(StateManager* stateManager)
		:mStateMgr(stateManager)
		, mTransparent(false)
		, mTranscendent(false){}
	virtual ~BaseState(){}

	virtual void				OnCreate() = 0;
	virtual void				OnDestroy() = 0;

	virtual void				Activate() = 0;
	virtual void				Deactivate() = 0;

	virtual void				Update(const sf::Time& time) = 0;
	virtual void				Draw() = 0;

	void						SetTransparent(const bool& transparent) { mTransparent = transparent; }
	bool						IsTransparent() const { return mTransparent; }
	void						SetTranscendent(const bool& transcendence) { mTranscendent = transcendence; }
	bool						IsTranscendent() const { return mTranscendent; }
	StateManager*				GetStateManager() { return mStateMgr; }

protected:
	StateManager*				mStateMgr;
	bool						mTransparent;
	bool						mTranscendent;
};

