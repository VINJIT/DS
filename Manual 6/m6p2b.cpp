//postfix to prefix 
#include <iostream> 
#include<string>
#include <stack> 
using namespace std; 

bool isOperator(char x) 
{ 
	switch (x) 
	{ 
		case '+': 
		case '-': 
		case '/': 
		case '*': 
			return true; 
	} 
	return false; 
} 

string postToPre(string post_exp) 
{ 
	stack<string> s; 

	int length = post_exp.size(); 

	for (int i = 0; i < length; i++)
	{ 
		if (isOperator(post_exp[i]))
		{ 
			string op1 = s.top(); 
			s.pop(); 
			string op2 = s.top(); 
			s.pop(); 
			
			string temp = post_exp[i] + op2 + op1; 
			s.push(temp); 
		} 

		else
		{ 
			s.push(string(1, post_exp[i])); 
		} 
	} 
	return s.top(); 
} 

int main() 
{ 
	string str;
	cout<<"Enter the postfix expression: ";
	getline(cin,str);
	cout << "Prefix : " << postToPre(str); 
	return 0; 
} 
