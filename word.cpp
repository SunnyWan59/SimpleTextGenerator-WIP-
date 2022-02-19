#include "word.h"
#include<string>
#include<vector>

word::word(std::string content)
{
	this->content = content;
	frequency = 1;
	possibleNextWords = {};
}

word::word(std::string content, std::string previousWord)
{
	this->content = content;
	frequency = 1;
	possibleNextWords.push_back(previousWord);
}

std::string word::getWord()
{
	return content;
}

void word::setWord(std::string newContent)
{
	content = newContent;
}

int word::getFrequency()
{
	return frequency;
}

void word::increaseFrequency()
{
	frequency++;
}

std::vector<std::string> word::getNextWords()
{
	return possibleNextWords;
}

std::string word::nextWordsToString()
{
	std::string possibleNextWordsString = "";
	for (auto i : possibleNextWords) {
		possibleNextWordsString += i + " ";
	}
	return possibleNextWordsString;
}

void word::addPossibleword(std::string word)
{
	possibleNextWords.push_back(word);
}
