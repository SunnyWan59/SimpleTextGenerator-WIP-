#include "dictionary.h"
#include<iostream>
#include<string>
#include<map>
#include<vector>
#include "word.h"


bool isPunctuation(char c)
{
	std::map<char, bool> punctuation = { {'!', true}, {'.', true}, {'?', true}};
	
	return punctuation.count(c) || false;
}

word* createPunctuation(std::string c)
{
	return new word(c);
}

dictionary::dictionary(std::map<std::string, word*> dict)
{
	this->dict = dict;
}

dictionary::dictionary()
{
	word* spaceHolder = new word(" ");
	std::map<std::string, word*> dict = { {" ", spaceHolder}};
	this->dict = dict;
}


std::map<std::string, word*> dictionary::getDict()
{
	return dict;
}

void dictionary::addToDict(std::string key, word* addedWord)
{
	dict.insert(std::make_pair(key, addedWord));
}


std::string dictionary::toString()
{
	std::string dictionaryString;
	for (it = dict.begin(); it != dict.end(); ++it) {
		dictionaryString = dictionaryString + it->first + " : " + it->second->nextWordsToString() + "\n";
	}
	return dictionaryString;
}

/*
Receives source text and maps every word to its proceding word
Parameter(s): string
Return:map
*/
void dictionary::mapText(std::string sourceText) {
	std::string currentWord = "";
	std::string previousWord = " ";
	sourceText += ' ';
	for (int i = 0; i < sourceText.length(); i++) {
		if (sourceText[i] == ' ') {// space usually indicates new word
			word* newWord = new word(currentWord); // creates a word object from the current word
			if (dict.find(currentWord) == dict.end()) { // if the word has not been seen before
				this->addToDict(currentWord, newWord);
			}
			dict[previousWord]->addPossibleword(currentWord);
			previousWord = currentWord;
			currentWord = "";

		}
		else {
			currentWord.push_back(sourceText[i]);
		}
	}
}

std::string dictionary::generateSentence()
{
	return std::string();
}



void dictionary::printDictionary() {
	std::cout << this->toString();
}


/*
* Use to delete all the objects in dictionary.
*/
void dictionary::clearRam() {
	for (it = dict.begin(); it != dict.end(); ++it) {
		delete it->second;
	}
}
