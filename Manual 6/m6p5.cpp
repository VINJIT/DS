//rev string
#include<iostream>
#include<string>
#include<stdlib.h>
#define max 20
using namespace std;

int top=-1;	
char st[max];
void push(char x)
{
	if(top==max)
	{
		cout<<"\nERROR :- Stack Overflow !!\n";
	}
			
	else
	{
		top++;
		st[top]=x;
	}
}
		
void pop()
{	
	cout<<st[top--];
}
		
int main()
{
	int len;
	cout<<"Enter the string length: ";	
	cin>>len;
	char str[len];
	cout<<"Enter the string: ";
	for(int i=0;i<len;i++)
	{
		cin>>str[i];
	}
	
	for(int i=0;i<len;i++)
	{
		push(str[i]);
	}
	cout<<"Reverse string is: ";
	for(int i=0;i<len;i++)
	{
		pop();
	}
}
