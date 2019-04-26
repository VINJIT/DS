/*
	Name: Stack
	Copyright: All rights reserved
	Author: Vinjit
	Date: 23/08/16 23:16
	Description: Operations on a stack
*/
#include<iostream>
#include<stdlib.h>
#include<conio.h>
#include<process.h>
using namespace std;

class Stllnode
{
	public:		
	int info;
	Stllnode *next;
	Stllnode(int a=0,Stllnode *n=0)
	{
		info=a;
		next=n;
	}	
};
//-----------------------------------------------------------------------------------------------------------------------
//-----------------------------------------------------------------------------------------------------------------------
class Stllist
{
	Stllnode *top;
	
	public:
	Stllist()
	{
		top=NULL;
	}
	
	void display()
	{
		Stllnode *p=top;
		
		if(top==0)
		{
			cout<<"Empty";
		}
		
		else
		{
			while(p!=NULL)
			{
				cout<<p->info<<" ";
				p=p->next;
			}
    	}
	}
	void push()
	{
		int y;
		Stllnode *p;
		cout<<"Enter the integer to insert : ";
		cin>>y;
		p=new Stllnode(y);
		
		if(top==0)
		{
			top=p;
		}
		else
		{
			p->next=top;
			top=p;		
		}
	}
	
	int pop()
	{
		Stllnode *p;
		int t;
		if(top==0)
		{
			cout<<"ERROR:-Stack is Empty!!";
			return(-1);
		}
		
		else		
		{	t=top->info;
			p=top;
			top=top->next;
			delete(p);
			return(t);
		}
	}
};
int main()
{
	Stllist ob1;
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
				case 1:	ob1.push();
						cout<<"\n-->The Current stack is : ";
						ob1.display();
						break;
				
				case 2: ob1.pop();
						cout<<"\n-->The Current stack is : ";
						ob1.display();
						break;
				
				default: cout<<"\n!! INVALID Choice !!";
						 break;
						
			}
		cout<<endl;
		cout<<endl;
		cout<<"-->Do You Wish to Continue?(Y/N) : ";
		cin>>ch;
		cout<<endl;
		
	 }
	while(ch=='Y'||ch=='y');
	return 0;
}
