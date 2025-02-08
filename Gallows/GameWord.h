#pragma once
#include <iostream>
#include <string>

class GameWord
{
private:
	// 6 = letter
	std::string hidden_word;
	// 6 = l
	std::string external_word;
public:
	GameWord(std::string& word)
		: hidden_word(word),
		external_word(word)
	{}

	bool InputLetter(char letter)
	{
		return false;
		//external_word.find(letter);
	}

	std::string& GetExternalWord()
	{
		return external_word;
	}

	bool IsGuessed() const
	{
		return hidden_word == external_word;
	}
};

