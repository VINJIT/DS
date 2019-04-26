//balanced parenthesis. 
#include<iostream>
#include<bits/stdc++.h> 
#include<string>
using namespace std; 

bool areParanthesisBalanced(string expr) 
{ 
	stack<char> s; 
	char x; 

	for (int i=0; i<expr.length(); i++) 
	{ 
		if (expr[i]=='('||expr[i]=='['||expr[i]=='{') 
		{ 
			s.push(expr[i]); 
			continue; 
		} 

		if (s.empty()) 
			return false; 

		switch (expr[i]) 
		{ 
		case ')': 
			x = s.top(); 
			s.pop(); 
			if (x=='{' || x=='[') 
				return false; 
			break; 

		case '}': 
			x = s.top(); 
			s.pop(); 
			if (x=='(' || x=='[') 
				return false; 
			break; 

		case ']': 			
			x = s.top(); 
			s.pop(); 
			if (x =='(' || x == '{') 
				return false; 
			break; 
		} 
	} 

	// Check Empty Stack 
	return (s.empty()); 
} 
int main() 
{ 
	string expr;
	cout<<"Enter parenthesis expression: ";
	getline(cin,expr); 

	if (areParanthesisBalanced(expr)) 
		cout << "Balanced"; 
	else
		cout << "Not Balanced"; 
	return 0; 
} 

