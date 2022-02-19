#pragma once
#include<iostream>
#include<string>
#include<map>
#include<vector>
#include "word.h"
class dictionary
{
private:
	std::map<std::string, word*> dict;
	std::map<std::string, word*>::iterator it;

public:
	dictionary(std::map<std::string, word*> dict);
	dictionary();
	
	std::map<std::string, word*> getDict();
	void addToDict(std::string key, word* addedWord);
	std::string toString();

	void mapText(std::string sourceText);
	std::string generateSentence();

	void printDictionary();
	void clearRam();

};

