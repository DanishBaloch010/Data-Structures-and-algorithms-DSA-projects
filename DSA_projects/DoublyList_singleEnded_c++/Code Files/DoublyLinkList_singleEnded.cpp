#include <iostream>
#include "DoublyLinkList_singleEnded.hpp"

using namespace std;


int counter=0;
DoublyList_singleEnded::DoublyList_singleEnded()
{
	
		head = NULL;
		tail = NULL;
		temp = NULL;
		current = NULL;
}

// INSERT node at tail
void DoublyList_singleEnded::addNodeLast(string addDataLast)
{
	nodeptr n = new node;
	n->StudentName = addDataLast;
	n->score1 = 0;
	n->score2 = 0;
	n->score3 = 0;
	n->score4 = 0;
	n->scoreTotal=0;
	n->averageScore=0;
	n->next = NULL;	
	temp = n;
	if(head != NULL)
	{
		tail->next = temp;
		tail = temp;
		counter++;	
	}
	else
	{
		head = temp;
		tail = temp;
		counter++;
	}	
//	tail->next  = NULL;
}

// search 
void DoublyList_singleEnded::search(string value)
{
	current = head;
	while(current != NULL && current->StudentName != value)
	{
		current = current->next;
	}
	
	if(current == NULL)
	{
		cout << "\nThe searched value "<<value<<" is not present in the List.";
	}
	
	else
	{
		cout << "\nThe searched value "<<value<<" is present in the List.";
	}
}

void DoublyList_singleEnded::deleteNode(string value)
{
	if (head == NULL)
	{
		cout<<"\nList is empty.";
	}
	
	current = head;
	if(current->StudentName == value )
	{
		if(head == tail)
		{
			head = NULL;
			tail = NULL;
		}
		else
		{
			head = head->next;
		}
		cout <<"\nThe value "<<value<<" is deleted.";
	}
	
	else
	{
		cout << "\nThe value "<<value<<" is not found and cant be deleted.";
	}
	
	while(current->next != NULL && current->next->StudentName != value)
	{
		current = current->next;	
	}
	
	if(current->next != NULL)
	{
		if(current->next == tail)
		{
			tail = current;
			current->next = current->next->next;
		    cout << "\nThe value "<<value<<" is deleted.";
		}
	}
}

// reverse traverse
//void DoublyList_singleEnded::reverseTraverse()
//{
//	nodeptr n = new node;
//	n = head;
//	head = tail;
//	tail = n;
//	nodeptr p = new node;
//	p=head;
//	
//	while(p!= NULL)
//	{
//		n = p->prev;
//		p->next = p->prev;
//		p->prev =n;
//		p = p ->next;
//	}
//	
//}

// counter

int DoublyList_singleEnded::Count()
{
	return counter;
}
// printing
void DoublyList_singleEnded::printList()
{
	temp =head;
	
//	cout<<endl;

	cout <<"STUDENT NAME\tSCORE-1\tSCORE-2\tSCORE-3\tSCORE-4\tTOTAL-SCORE\tAVERAGE-SCORE"<<endl; 
	cout <<"----------------------------------------------------------------------------"<<endl;
	while(temp != NULL)
	{
		cout << temp->StudentName <<"\t   "<<temp->score1<<"\t   "<<temp->score2<<"\t   "<<temp->score3<<"\t   "<<temp->score4<<"\t   "<<temp->scoreTotal<<"\t\t   "<<temp->averageScore<<endl;
		temp = temp->next;	 
	}
//	cout << endl;
}

void DoublyList_singleEnded::inputScores()
{
 	temp=head;
 	
 	while(temp!=NULL)
 	{
 		cout <<"Enter Scores For : "<<temp->StudentName<<endl;
 		cout << "Score-1 :";
 		cin >> temp->score1;
 		cout << "Score-2 :";
 		cin >> temp->score2;
 		cout << "Score-3 :";
 		cin >> temp->score3;
 		cout << "Score-4 :";
 		cin >> temp->score4;
 		cout<<endl;
 		temp->scoreTotal = temp->score1 + temp->score2 + temp->score3 + temp->score4;
 		temp->averageScore  = temp->scoreTotal/4;
 		temp = temp->next;
	}
 	
}



