/*
	Name: Postfix
	Copyright: All rights reserved
	Author: Vinjit
	Date: 25/08/16 14:09
	Description: Computing a postfix notation via stacks. 
*/
#include<iostream>
#include<stdlib.h>
#include<process.h>
#define MAX 20
using namespace std;

class postStack
{
	long double st[MAX];
	int top;
		
	public:
		postStack()
		{
			top = -1;
		}
		
		void push(long double x)
		{
			if(top==MAX-1)
				cout<<"\nStack Full";
			else
				st[++top] = x;
		}
		
		long double pop()
		{
			if(top==-1)
			{
				cout<<"\nStack Empty";
				return NULL;
			}
			else
				return st[top--];
		}
		
		int check_top()
		{return top;}
};

long double operations(long double a, long double b, char ch)
{
	long double ans;
	if(ch=='+') ans = a+b;
	
	else if(ch=='-') ans = a-b;
	
	else if (ch=='/')
	{
		if (b<=0)
		{
			cout<<"ERROR : Division with zero denominator is not defined!!";
			exit(1);
		}
		else
			ans = a/b;
	}
	
	else ans = a*b;
	
	return ans;
}

int main()
{
	int flag=1, len;
	postStack ob1;
	long double x, operand_x, operand_y, n;
	string exp;
	cout<<"NOTE:-(Input format: ab-bc*+)\n-->Enter a Postfix Expression: ";
	getline(cin,exp);
	cout<<endl;						//to take expression as string input
	len = exp.length();				//to store length of expression
	
	for(int i=0;i<len;i++)
	{	
		/* FROM a TO z OR A TO Z */
		if ((exp[i]>=97 && exp[i]<=122)|| (exp[i]>=65 && exp[i]<=90))
		{
			cout<<"-->Enter value of "<<exp[i]<<" : ";				//to take value of characters
			cin>>x;
			ob1.push(x);
		}
		
		else if (exp[i]=='+' || exp[i]=='-' || exp[i]=='*' || exp[i]=='/')
		{
			operand_x = ob1.pop();
			if (operand_x==NULL && operand_x!=0)						//conditions in case of missing operands
			{
				flag=0;
				break;
			}
			
            operand_y = ob1.pop();
            if (operand_y==NULL && operand_y!=0)
			{
				flag=0;
				break;
			}
			else
			{	
				n=operations(operand_y, operand_x, exp[i]);				//compute operation if notation is valid
            	ob1.push(n);
        	}
		}
		
		else
		{
			flag=0;
			break;
		}
	}
	if (flag && ob1.check_top()==0) cout<<"\n-->Answer of Postfix Expression is : "<<ob1.pop();
	else cout<<"\nSORRY!!Invalid Postfix Expression!";
	return 0;
}
