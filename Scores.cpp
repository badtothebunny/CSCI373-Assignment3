//Implementation section of the Scores Class
//Programmer: Badtothebunny

#include "Scores.h"

//Constructor
Scores::Scores(int maxEnt)
{
	maxEntries = maxEnt;
	numEntries = 0;
}

//Destructor 
Scores::~Scores()
{
//removing all elements from maxEntry to the first element.
	for (int i = maxEntries; i > 0; i--)
		remove(i);
}

//Adding an element
void Scores::add(const GameEntry& e)
{
	if (numEntries == maxEntries)
	{
		return; 
	}
//First we create a new node.
	GENode *n = new GENode;
//Store GameEntry element in n.
	n->elem.setName(e.getName());
	n->elem.setScore(e.getScore());
//Then check if the list is empty.
	if (numEntries == 0)
	{
//If it is empty, then this element is the head.
		head = new GENode;
		head->elem = n->elem;
		head->next = n->next = NULL;
	}
	else 
	{
//First the new element will point to second element.
		n->next = head->next;
//Then head will point to the new element.
		head->next = n;
	}
//Lastly we add 1 to the number of entries.
	numEntries++;
}

//Removing the i-th element, inspiration from example 1 - week 2
GameEntry Scores::remove(int i)throw(IndexOutOfBounds)
{
//First we check if i is invalid.
	if (i < 0 || i >= numEntries)
		throw IndexOutOfBounds("Invalid Index");
//Otherwise we can continue with the removal of the element.
//First check if we're removing the head.
	if (i == 0)
	{
		GENode *temp = head;
//The next element becomes the head.
		head->elem = temp->next->elem;
		head->next = temp->next->next;
//Returning GameEntry type.
		return temp->elem;
	}
//Other we can continue to the i-th element.
	GENode *previous = head;
	GENode *current = head;
//Using a For-Loop to go to the i-th element.
	for (int j = 0; j < i; j++)
	{
		previous = current;
		current = previous->next;
		j++;
	}
//Once the loop ends, previous will contain the element before the i-th element
//and current will contain the i-th element.
	GameEntry e = current->elem; //Saving the removed element.
	previous->next = current->next; //Previous now points to the (i+1)-th element.
	delete current;
	return e; //Returning removed element.
}

//Print function
void Scores::printAll()
{
	GENode *p = head;
	while (p != NULL)
	{
		cout<<"Name: "<<p->elem.getName()<<" Score: "<<p->elem.getScore()<<endl;
		p = p->next;
	}
	cout<<"NULL"<<endl;
}

