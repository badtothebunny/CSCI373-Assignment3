//This program utilizies a Singly Linked List for Game Entries and Scores.
//Programmer: Maria Psomas :)

#include <iostream>
#include "GameEntry.h"
#include "GENode.h"
#include "Scores.h"

using namespace std;

int main(int argc, char** argv) 
{
	cout<<"Welcome. This main program is to test my Singly Linked List implementation of the Scores class."<<endl;
	Scores test(5); //Max entries is going to be 5.
//Next is 4 GameEntry objects.
	GameEntry ge1("Liberty",40);
	GameEntry ge2("Freedom",10);
	GameEntry ge3("Justice",15);
	GameEntry ge4("America",25);
//Next is adding it to Scores.
	test.add(ge1);
	test.add(ge2);
	test.add(ge3);
	test.add(ge4);
	cout<<"Printing 4 Scores objects:"<<endl;
	test.printAll();
//Next the instructions say to add 3 more GameEntry objects
	GameEntry ge5("Honesty",30);
	GameEntry ge6("Honor",35);
	GameEntry ge7("Integrity",40);
	test.add(ge5);
	test.add(ge6); //By this point, max number of Entries will have been reached.
	test.add(ge7);
	test.printAll();
	cout<<"Removing first element."<<endl;
	test.remove(0);
	test.printAll(); 
	cout<<"That concludes my testing. Thank you for using my program. :)"<<endl;
	return 0;
}
