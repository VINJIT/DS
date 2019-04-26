/*
	Name: Linked List
	Copyright: All rights reserved
	Author: Vinjit
	Date: 16/08/16 22:33
	Description: Operations in a doubly linked list 
*/
#include<iostream>
#include<conio.h>
#include<stdlib.h>
#include<process.h>
using namespace std;

template<class X>
class dllnode
{
	public:		
	X info;
	dllnode *next;
	dllnode *prev;
	dllnode(X a=0, dllnode *n=0, dllnode *prv=0)
	{
		info=a;
		next=n;
		prev=prv;
	}	
};
//-----------------------------------------------------------------------------------------------------------------------
//-----------------------------------------------------------------------------------------------------------------------
template<class X>
class dllist
{
	dllnode <X> *head, *tail;
	
	public:
	dllist()
	{
		head=0;
		tail=0;
	}
	
	void display()
	{
		dllnode <X>*p=head;
		
		if(head==0)
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
//------------------------------------------------------------------------------------------------------------------------	
	void insert_at_end()
	{
		int x;
		dllnode <X>*p;
		cout<<"Enter the integer to Enter at end : ";
		cin>>x;
		p=new dllnode<X>(x);
		
		if(head==0)
		{
			head=p;
			tail=p;
		}
		else
		{
			tail->next=p;
			p->prev=tail;
			tail=p;
		}
	}
//------------------------------------------------------------------------------------------------------------------------	
	void insert_at_beg()
	{
		int y;
		dllnode <X> *p;
		cout<<"Enter the integer to insert at beginning : ";
		cin>>y;
		p=new dllnode <X> (y);
		
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
//------------------------------------------------------------------------------------------------------------------------	
	
	void insert_after_part_node(X x, X y)
	{
	    dllnode <X>*p = new dllnode<X>(y);
        dllnode <X>*q = head;
        
        while(q!=NULL&&q->info!=x)
            q = q->next;
        
        if(q==0)
        {
			cout<<" \nSorry...Item "<<x<<" not found! Try again."<<endl;
           	return;
        }
        
        else if(q==tail)
        {
        	tail->next=p;
			p->prev=tail;
			p->next=NULL;        	
			tail=p;
		}
        
        else
        {
            p->next =  q->next;
            q->next->prev= p;
            p->prev=q;
            q->next=p;
            cout<<"\nItem added successfully!\n"<<endl;
        }
	}
//------------------------------------------------------------------------------------------------------------------------	
	void insert_before_part_node(X x, X y)
	{
		dllnode <X>*p = new dllnode<X>(y);
        dllnode <X>*q = head;
		
		if(head->info==x)
		{		
			p->next=head;
			head=p;			
			cout<<"\n\nItem Added successfully!\n";	
			cout<<endl;
		}
		
		else
		{
			while(q!=NULL&&q->info!=x)
	        {
	            q = q->next;
	        }
	        
	        if(q==NULL)
		    {
				cout<<"\nSorry.....Item not found! Try Again.\n"<<endl;
		        return;
		    }
		    
		    else
        	{		  
		        q->prev->next = p;
		        p->next =q;
		        p->prev=q->prev;
		        q->prev=p;
		        cout<<"\n\nItem Added successfully!\n\n";        
	    	}			
		}
	}
//------------------------------------------------------------------------------------------------------------------------	
	void del_beg()
	{
		dllnode <X>*p;		
		p=head;
		if(head==0)
		{
			cout<<"Linked list is empty\n";
		}
		else
		{
			p->next->prev=NULL;
			head=p->next;
			delete(p);
		}
	}
//------------------------------------------------------------------------------------------------------------------------		
	void del_end()
	{
		dllnode <X> *p,*q;
		p=head;
		
		if(head==0)
		{
			cout<<"Linked list is empty!\n";
		}
		
		else
		{
			while(p!=tail)
			{
				q=p;
				p=p->next;
			}
			
			q->next=NULL;
			delete(p);
			tail=q;	
		}
	}
//------------------------------------------------------------------------------------------------------------------------
	void del_node()
	{
		dllnode <X>*q=head;
		dllnode <X>*p;
		int x;
		
		if(head==0)
		{
			cout<<"Linked list is empty!\n";
			return;
		}
		
		cout<<"Enter the node to be deleted : ";
		cin>>x;
		cout<<endl;			
		
		if(head->info==x)
		{
			del_beg();		
			cout<<"\nItem deleted successfully\n";
		}
		
		else
		{
			while (q!=NULL && q->info!=x)			
			{
				q=q->next;
			}			
			
			if(q==0)			
			{
				cout<<"\n!!Element "<<x<<" not found in the linked list!!\n\n";
				return;
			}
		
			else	
			{
				if(q==tail)
				{
					q->prev->next=NULL;					
					delete(q);
					cout<<"\nItem deleted Successfully\n\n";
				}
				else
				{	q->prev->next=q->next;
					q->next->prev=q->prev;
					delete(q);
					cout<<"\nItem deleted Successfully!\n\n";
				}
			}
		}	
	}
//------------------------------------------------------------------------------------------------------------------------
	void searching()
	{
		dllnode <X>*p;
		int x;
		cout<<"\nEnter the number you wish to search : ";
		cin>>x;
		p=head;
		dllnode <X> *r;
		
		bool flag = false;
		
		while(p!=NULL)
		{
            if(p->info==x)
            {
               flag = true;
               break;
            }
            p = p->next;
        }
		
		if(flag)
		 cout<<"\n!!Integer found in doubly linked list!!"; 
		else
		 cout<<"\n!!Integer doesn't exist in doubly linked list! Try Again.";  
	}
//------------------------------------------------------------------------------------------------------------------------	
	void reverse()		
	{
		dllnode <X>*p;
		dllnode <X>*temp;
		
		if(head==0)
			cout<<"\n\nDoubly Linked list is Empty\n\n";
			
		else if(head->next==NULL)
			cout<<"\nDoubly Linked list is already reversed!!\n";
			
		else
		{
			p=head;
			while(p!=NULL)
			{
				temp=p->prev;
				p->prev=p->next;
				p->next=temp;
				
				p=p->prev;				
			}
			
			temp = head;
			head = tail;
			tail = temp;			
		}	
	}

};
//------------------------------------------------------------------------------------------------------------------------
//------------------------------------------------------------------------------------------------------------------------
int main()
{
	int x,y,size;
	int choice,ch;
	char c,c1;
	dllist <int> ob1;
	
do{
	system("cls");	
	cout<<"\n............................................MAIN MENU.................................................\n"<<endl;
	cout<<"1. INSERTION"<<endl;
	cout<<"2. DELETION"<<endl;
	cout<<"3. SEARCHING"<<endl;
	cout<<"4. REVERSING"<<endl;
	cout<<"\n#Enter your choice : ";
	cin>>choice;
	switch(choice)
    { 
      case 1 : 
	  do{
	  			system("cls");
				cout<<"\n......................................OPTIONS........................................."<<endl<<endl;
				cout<<"------>Press 1 for INSERTION AT END"<<endl;
				cout<<"------>Press 2 for INSERTION AT BEGINNING"<<endl;
				cout<<"------>Press 3 for INSERTION AFTER A NODE"<<endl;
				cout<<"------>Press 4 for INSERTION BEFORE A NODE "<<endl;			
				cout<<"\n#Enter your choice : ";
				cin>>ch;
				cout<<endl;
				
			switch(ch)
    		   	{ 
      				case 1 :ob1.insert_at_end();
      						cout<<"The doubly Linked list is : ";
							ob1.display();
							cout<<endl;
							break;
							 
      				case 2 :ob1.insert_at_beg();
      						cout<<"The doubly Linked list is : ";
							ob1.display();
							cout<<endl;
							break;
							
      				case 3 :
      					    cout<<"Enter number after which you want to insert new node : ";
					        cin>>x;
					        cout<<"Enter number to be inserted : ";
					        cin>>y;
							ob1.insert_after_part_node(x,y);
							cout<<"The doubly Linked list is : ";
							ob1.display();
							cout<<endl;
							break;
							
      				case 4 :cout<<"Enter number before which you want to insert new node : ";
					        cin>>x;
					        cout<<"Enter number to be inserted : ";
					        cin>>y;
							ob1.insert_before_part_node(x,y);
					        cout<<"The doubly Linked list is : ";
							ob1.display();
							cout<<endl;
							break;	
      				
      				default : cout<<"Invalid input! Try Again."<<endl;
      						   break;
      			}				 
     				cout<<"\n->Press 'Y' for current menu & Press 'N' to exit this menu."<<endl;
     				cout<<"#Enter Your Choice : ";
     				cin>>c;  					  
			}
			while(c=='y'||c=='Y');
			break;
          
      case 2 : 	
	  		do{ system("cls");
			  	cout<<"\n..........................................OPTIONS.........................................."<<endl;
	  			cout<<"------>Press 1 for DELETION FROM END"<<endl;
				cout<<"------>Press 2 for DELETION FROM BEGINNING"<<endl;
				cout<<"------>Press 3 for DELETION OF A PARTICULAR NODE"<<endl;
				cout<<"\n#Enter your choice : ";
				cin>>ch;
				cout<<endl;
				
				switch(ch)
    		   	{ 
      				case 1 :ob1.del_end();
      						cout<<"The doubly Linked list is : ";
							ob1.display();
							cout<<endl;
							break;
							 
      				case 2 :ob1.del_beg();
      						cout<<"The doubly Linked list is : ";
							ob1.display();
							cout<<endl;
							break;
							
      				case 3 :ob1.del_node();
      						cout<<"The doubly Linked list is : ";
							ob1.display();
							cout<<endl;
							break;
							
					default : cout<<"Invalid input! Try again."<<endl;					
      				
      			}   
     				cout<<"\n->Press 'Y' for current menu & Press 'N' to exit this menu."<<endl;
     				cout<<"#Enter Your Choice : ";
     				cin>>c;  
					  
			}
			while(c=='y'||c=='Y');
            break;
              
      case 3: do{
      			  system("cls");
	  		      ob1.searching();	  		  
			      cout<<endl;
				  cout<<"\n->Press 'Y' to search again & Press 'N' to exit this operation."<<endl;
     			  cout<<"#Enter Your Choice : ";
     			  cin>>c;                  
                }
                while(c=='y'||c=='Y');
                break;
      
      case 4: do{
		  			system("cls");
		  			cout<<"The original linked list is :";
      				ob1.display();
      				cout<<endl;
					ob1.reverse();
	      		    cout<<"The Reversed doubly Linked list is : ";
				    ob1.display();
	                cout<<endl;
	                cout<<"\n->Press 'Y' to reverse again & Press 'N' to exit this operation."<<endl;
	     			cout<<"#Enter Your Choice : ";
	     			cin>>c;  					  
				}
				while(c=='y'||c=='Y');
				cout<<endl;
            	break;
              
       default : cout<<"Invalid input! Try again."<<endl;
      
    }	   
       cout<<"\n->Press 'Y' for MAIN MENU & Press 'N' to exit program."<<endl;
       cout<<"#Enter Your Choice : ";
       cin>>c1;  
	   cout<<endl;   
	}
	while(c1=='y'||c1=='Y');   
	return 0;
}                                                                                                 
