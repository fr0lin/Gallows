#pragma once
#include "GameWord.h"
#include "GameWordsBuilder.h"
#include <memory>

using std::unique_ptr;

class Game
{
private:
	GameWordsBuilder wordsBuilder;
	unique_ptr<GameWord> current_word;
	int mistakes;
public:
	Game(unique_ptr<WordsManager>& manager)
		: wordsBuilder(std::move(manager))
	{
		mistakes = 6;
	}

	void Start()
	{
		while (!current_word->IsGuessed() && mistakes < 6)
		{
			current_word = std::make_unique<GameWord>(wordsBuilder.GetRandomWord());
			char letter;
			std::cout << "Enter letter: ";
			std::cin >> letter;
			if (current_word->InputLetter(letter))
			{
				std::cout << "Guessed!\n";
			}
			else
			{
				std::cout << "No Guessed!\n";
				mistakes++;
			}
		}
	}

	void End()
	{

	}
};

