/*
	Name: Stack
	Copyright: All rights reserved
	Author: Vinjit
	Date: 23/08/16 23:16
	Description: Operations on a stack
*/
#include<iostream>
#include<stdlib.h>
#define max 20
using namespace std;

template<class X>			//to make generic class
class MyStack
{
	X st[max];
	int top;
	
	public:
		MyStack()
		{top=-1;}
		
		void push(X x)
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
		
		int pop()
		{
			if(top==-1)
			{
				cout<<"ERROR :- Stack is Empty!\n";
			}
			
			else
			{
				int t=st[top];
				top--;
				return(t);
			}
		}
		
		void display()
		{			
		    int i;
		    if (top == -1)
		    {
		    	cout<<"\nCurrent Stack is : ";
		        cout<<"Empty\n";		        
		    }
		    else
		    {
		        cout<<"\nCurrent Stack is : ";
		        
		        for (i = top; i >= 0; i--)
		        {
		            cout<<st[i];
		            cout<<" ";
		        }
		    }
		    cout<<endl<<endl;
		}
		
};

int main()
{
	MyStack <int>ob1;
	char ch;
	int n,x;
	
	do{
		system("cls");
		cout<<"\n\n.....................................................MENU...................................................\n\n"<<endl;
		cout<<"Press 1 to Insert an element into the Stack."<<endl;
		cout<<"Press 2 to Delete an element from the Stack."<<endl;
		cout<<"\n-->Please Enter your Choice : ";
		cin>>n;
		cout<<endl;
		
		switch(n)		
			{
				case 1: cout<<"Enter The Element you wish to insert : ";
						cin>>x;
						ob1.push(x);
						ob1.display();
						break;
				
				case 2: ob1.pop();
						ob1.display();
						break;
				
				default: cout<<"\n!! INVALID Choice !!";
							break;
						
			}
		cout<<endl;
		cout<<"-->Do You Wish to Continue?(Y/N) : ";
		cin>>ch;
		cout<<endl;
	 }
	while(ch=='Y'||ch=='y');
	return 0;
	
}
