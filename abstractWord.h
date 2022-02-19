#pragma once
#include<string>
class abstractWord
{
private:

protected:
	std::string content;
public:
	abstractWord();

	virtual std::string getWord();
	virtual void setWord(std::string newContent);
};

