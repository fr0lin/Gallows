#include <iostream>
#include "ConsoleGameView.h"

int main()
{
	IGameView* view = new ConsoleGameView();

	std::cout << (view->IsGameExit() ? "true" : "false") << std::endl;
	//std::cout << view->GetInputLetter() << std::endl;

	delete view;
	return 0;
}