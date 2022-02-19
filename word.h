/*
Header for the word class

*/
#include<string>
#include <vector>
#include "abstractWord.h"
#pragma once

class word : public abstractWord
{
// Methods users should be able to access
public:
	word(std::string content);
	word(std::string content, std::string previousWord);

	std::string getWord();

	void setWord(std::string newContent);

	int getFrequency();

	void increaseFrequency();

	std::vector<std::string> getNextWords();
	std::string nextWordsToString();

	void addPossibleword(std::string word);

private:
	using abstractWord::content;
	int frequency;
	std::vector<std::string> possibleNextWords;

};

