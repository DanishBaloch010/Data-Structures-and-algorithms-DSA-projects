#include <iostream>
#include <fstream>
#include <conio.h>
#include <string>
#include <bits/stdc++.h> 
using namespace std;
int main()
{
	string forWord ="for"; // for keyword
	string modWord ="%";   // mod keyword
	string fileWord;
	
	int forCounter =0;  // for loop counter
	int modCounter =0;  // mod keyword counter
	
	string fileName ="input.txt";  // opening the file
	fstream File;
	File.open(fileName.c_str());
	
	while(File >> fileWord)  // checking for every possible match
	{
		if(fileWord == forWord)
			forCounter++;
		
		else if(fileWord ==modWord)
			modCounter++;
	}
	File.clear();
	File.close();
		if(forCounter > 0)   // if loops number is greater than zero.
		{
			if(modCounter > 0) // checking mod condition
			cout<<"\nThe algorithm have ARTC of O(log n)";
			
			else              // else linear complexity with loops
			cout<<"\nThe algorithm have ARTC of O(n)^"<<forCounter;
		
		}
		
		else // else there will be a one line statement (intialization , printing etc..)
		{
			cout << "\nThe algorithm have constant complexity of O(1).";
		}
		
	// program exit 
	cout <<"\n\nPress any key to exit.......";
	_getch();
	
	return 0;
}
