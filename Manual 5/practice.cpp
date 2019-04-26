#include<iostream>
using namespace std;

class llnode
{
	public:
	int info;
	llnode * next;
	llnode *prev;
	
	llnode(int a=0,llnode *p=0,llnode * n=0)
	{
		info=a;
		next=n;
		prev=p;
	}
};

class Dlist
{
	llnode *head,*tail;
	llnode info;
	
	public:
	Dlist()
	{
		head=0;
		tail=0;
	}
	
	void display()
	{
		llnode *p=head;
		
		if(head==0)
		{
			cout<<"No ll";
		}
		else
		{
			while(p!=NULL)
			{
				cout<<p->info<<" ,";
				p=p->next;
			}
		}
	}
	
	void insert_beg(int x)
	{
		llnode *p=new llnode(x);
		if(head==0)
		{
			head=p;
			tail=p;
		}
		else
		{
			p->next=head;
			head->prev=p;
			head=p;
		}
	}
	
	void rev()
	{
		llnode *p=head;
		llnode *q=p->next;
		llnode *r=q->next;
		
		while(q!=NULL)
		{
			q->next=p;
			p=q;
			q=r;
			if(r!=NULL)
				r=r->next;
		}
		
		head->next=NULL;
		tail=head;
		head=p;
	}
};

int main()
{
	int n;
	char ch;
	Dlist ob1;
	do{cout<<"Enter choice 1 or 2 or 3: ";
	cin>>n;
	switch(n)
	{
		case 1: ob1.display();
			break;
			
		case 2: ob1.insert_beg(5);
				ob1.insert_beg(6);
				ob1.insert_beg(8);
				ob1.insert_beg(12);
				ob1.insert_beg(58);
				break;
			
		case 3:ob1.rev(); 
		ob1.display();
			break;
	}
	cout<<"Enter y to cont";
	cin>>ch;
	}while(ch=='y');
}
