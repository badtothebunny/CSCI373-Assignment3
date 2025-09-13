//Implementation section of the GameEntry Class
//Programmer: Maria Psomas :)

#include "GameEntry.h"

//Constructor
GameEntry::GameEntry()
{
	name = " ";
	score = 0;
}
//Parameterized constructor
GameEntry::GameEntry(const std::string&n,int s): name(n),score(s)
{
	//Here we can keep the body empty.
}

//Getters for the data members
std::string GameEntry::getName() const
{
	return name;
}

int GameEntry::getScore() const
{
	return score;
}

//Setters for data members
void GameEntry::setName(std::string nName)
{
	name = nName;
}

void GameEntry::setScore(int nScore)
{
	score = nScore;
}
