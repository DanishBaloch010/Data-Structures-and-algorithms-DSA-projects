#include <iostream>
#include "DoublyLinkList_singleEnded.hpp"
#include <fstream>
#include <conio.h>

/* run this program using the console pauser or add your own getch, system("pause") or input loop */

int main(int argc, char** argv) {
	
	// object of link list
	DoublyList_singleEnded StudentList;
	
	// reading form files and intilizing nodes for link list with student names.
	string StudentName;
	ifstream File;
	File.open("studentNames.txt");
	while(!File.eof())
	{
		getline(File, StudentName , '\n');
		StudentList.addNodeLast(StudentName);	
	}
	File.clear();
	File.close();
		
	// taking input of scores for every student.
	StudentList.inputScores();
	
	// size of link liss(number of nodes)
	int size =StudentList.Count();
	cout <<"\n\nNumber of Students :" <<size<<endl;
	cout <<endl;
	
	// printing the final output.
	StudentList.printList();
	
	// exit code waiting for any character entry.
	cout <<endl<<"\nPress any key to exit.....";
	_getch();
	
	return 0;
}
