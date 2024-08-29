#include "StateController.h"

StateController::~StateController()
{
	std::cout << "State Deleted" << std::endl;
	delete currentState;
}

void StateController::InitState()
{
	currentState = new MainMenu;
}

void StateController::SwitchState(State* newState)
{ 
		delete currentState;
		currentState = newState;
		std::cout << "New State Created" << std::endl;
}

void StateController::StateUpdate(sf::RenderWindow& window)
{
	currentState->Update(window);
	//std::cout << "State Updating" << std::endl;
}

void StateController::StateDraw(sf::RenderWindow& window)
{
	currentState->Draw(window);
	//std::cout << "State Drawing" << std::endl;
}

int StateController::StateEvent(sf::Event event)
{
	return (currentState->HandleButtonEvent(event));
}
