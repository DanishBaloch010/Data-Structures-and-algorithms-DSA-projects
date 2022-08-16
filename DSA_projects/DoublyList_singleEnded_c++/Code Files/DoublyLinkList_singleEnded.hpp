#ifndef DOUBLYLINKLIST_SINGLEENDED_H
#define DOUBLYLINKLIST_SINGLEENDED_H
#include <string>
#include <iostream>
using namespace std;
class DoublyList_singleEnded
{
	private:
		
		typedef struct node
		{
			string StudentName;
			int score1;
			int score2;
			int score3;
			int score4;
			int scoreTotal;
			int averageScore;
			node* next;
			
		}* nodeptr; 
		
		nodeptr head;
		nodeptr tail;
		nodeptr temp;
		nodeptr current;
		
	
	public: // public functions
	
	DoublyList_singleEnded(); // default constructor (used for intializing the global variables)

	void addNodeLast(string addDataLast);
		
	void search(string value);
	
	void deleteNode(string value);
	
	void printList();
	
	void inputScores();
	
	int Count();
			
};
#endif

