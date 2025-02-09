#pragma once
#include "GameWord.h"
#include "GameWordsBuilder.h"
#include "IGameView.h"
#include <memory>

using std::unique_ptr;

class Game
{
private:
	GameWordsBuilder wordsBuilder;
	unique_ptr<GameWord> current_word;
	int mistakes;
	unique_ptr<IGameView> view;
public:
	Game(const shared_ptr<WordsManager>& manager,
		unique_ptr<IGameView>& view)
		: wordsBuilder(manager),
		  view(std::move(view))
	{
		mistakes = 6;
	}

	void Start()
	{
		current_word = std::make_unique<GameWord>(wordsBuilder.GetRandomWord());
		view->DisplayWord(current_word->GetExternalWord());
		view->InitialMistakes(mistakes);

		do
		{
			while (!current_word->IsGuessed() && mistakes < 6)
			{
				char letter = view->GetInputLetter();
				if (current_word->InputLetter(letter))
					view->DisplayWord(current_word->GetExternalWord());
				else
					view->DisplayMistakes(--mistakes);
			}
			if (mistakes < 6)
				view->WordGuessed();
			else {
				view->GameOver();
				// TODO: збререгти статистику до таблиці лідерів
			}
			current_word = std::make_unique<GameWord>(wordsBuilder.GetRandomWord());
		} while (!view->IsGameExit());
	}
};

