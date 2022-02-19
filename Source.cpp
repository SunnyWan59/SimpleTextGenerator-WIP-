#include <iostream>
#include <string>
#include <map>
#include <vector>
#include "word.h"
#include "dictionary.h"



int main() {
	std::string testline = "Hello world! I am Sunny Wan. Hello everyone!";
	std::map<std::string, word*> wordMap;
	dictionary dict = dictionary();

	dict.mapText(testline);
	dict.printDictionary();
	dict.clearRam();
}
