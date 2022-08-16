// cs182019.cpp : Defines the entry point for the console application.
//
#include "stdafx.h"
#include <iostream>
#include <stack>
#include <conio.h>
#include <string>
using namespace std;
int priorityCheck(char c)
{
	if( c == '^')
	{
		return 3;
	}	
	else if( c =='*' || c == '/' )
	{
			return 2;
	}
	else if(c == '+' || c == '-' )
	{
		return 1;
	}
	else 
	{
		return -1;
	}
}
//using namespace std;

int main()
{
	stack<char> stack;
	string infix = "A-B/C*D^E";
	int expressionLength = infix.length();
	
	// step-1 
	for(int i=0 ; i<expressionLength; i++)
	{
		// step-2
		if((infix[i] >= 65 && infix[i] <= 90) )
		{
			cout << infix[i];
		}
		// step-3
		else if(infix[i]=='(')
		{
			stack.push(infix[i]);
		}
		// step-4
		else if((infix[i] == '+' )|| (infix[i]== '-' )||(infix[i]== '*' )||(infix[i]== '/' )||( infix[i]=='^'))
		{
			// step-4 (i)
			if(stack.empty())
			{
				stack.push(infix[i]);
			}
			// step-4 (ii)
			else if(stack.top()=='(')
			{
				stack.push(infix[i]);
			}
			// step-4 (iii)
			int operator1 = priorityCheck(infix[i]);
			int operator2 = priorityCheck(stack.top());

			if(operator1 >= operator2)
			{
				stack.push(infix[i]);
			}
			// step-4 (iv)
			else
			{
				cout<<stack.top();
				stack.pop();
			}
			
		}
			  
		// step-5
		else if(infix[i]==')')
		{
			while(stack.top()!='(')
			{
				if((stack.top()=='+' )||(stack.top()=='-' )||(stack.top()=='*' )||(stack.top()=='/' )||(stack.top()=='^'))
				{
					cout<<stack.top();
					stack.pop();
				}
			}
			stack.pop();
		}
		// step-6 .. looping again
	}

	// step-7
	while(!stack.empty())
	{
		if((stack.top()=='+' )||(stack.top()=='-' )||(stack.top()=='*' )||(stack.top()=='/' )||(stack.top()=='^'))
		{
			cout<<stack.top();
			stack.pop();
		}
		else
		{
			stack.pop();
		}
	}

	cout <<"\nPress any key to exit ..........";
	_getch();
	return 0;
}

