#include <iostream>
#include <stack>
#include <conio.h>
#include <string>
#include<bits/stdc++.h>
using namespace std;
int priorityCheck(char c)
{
	if( c == '^')
	{
		return 0;
	}	
	else if( c =='*' || c == '\')
	{
			return 5;
	}
	else if(c == '+' || c == '-' )
	{
		return 10;
	}
	else 
	return -1;
}
int main()
{
	stack<char> stack;
	string infix = "A-B/C*D^E";
	int expressionLength = infix.length();
	
	for(int i=0 ; i<expressionLength; i++)
	{
		if(infix[i] >='A' && infix[i]<='Z')
		{
			cout<<infix[i];
		}
		
		else if(infix[i]=='(')
		{
			stack.push(infix[i]);
		}
		else if(infix[i] == '+' || infix[i]== '-' ||infix[i]== '*' ||infix[i]== '/' )
		{
			if(stack.empty()==true)
			{
				stack.push(infix[i]);
			}
			if(stack.top()=='(')
			{
				stack.push(infix[i]);
			}
			
			int operator1 = priorityCheck(infix[i]);
			int operator2 = priorityCheck(stack.top());
			
		}
	}
	
	
	
//	stack.push(0);
//	stack.push(1);
//	stack.push(3);
	
	
	
	
	
	
	
	
	
	cout <<"\nPress any key to exit ..........";
	_getch();
	return 0;
}
