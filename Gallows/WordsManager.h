#pragma once
#include <vector>
#include <string>

using std::vector;
using std::string;

class WordsManager
{
private:
	vector<string> words;
public:
	const vector<string>& GetWords() const
	{
		return words;
	}

	void Save()
	{}

	void Load()
	{}

	void Append(std::string& word)
	{}
};

