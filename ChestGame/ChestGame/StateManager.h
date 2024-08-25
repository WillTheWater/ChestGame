#pragma once
/*
class StateManager
{
public:
	StateManager(SharedContext* shared);
	~StateManager();

	void					Update(const sf::Time& time);
	void					Draw();

	void					ProcessRequests();
	bool					HasState(const StateType& type);

	SharedContext*			GetContext() { return mShared; }

	void					SwitchTo(const StateType& type);
	void					Remove(const StateType& type);

private:
	void					CreateState(const StateType& type);
	void					RemoveState(const StateType& type);

	template<class T>
	void RegisterState(const StateType& type){...}

	SharedContext*			mShared;
	StateContainer			mStates;
	TypeContainer			mToRemove;
	StateFactory			mStateFactory;
};*/

