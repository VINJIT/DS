/*
	Name: Linked List
	Copyright: All rights reserved
	Author: Vinjit
	Date: 01/08/16 22:33
	Description: Operations in a Circular linked list 
*/
#include<iostream>
#include<conio.h>
#include<process.h>
#include<stdlib.h>
using namespace std;

template<class X>
class cllnode
{
	public:		
	int info;
	cllnode *next;
	cllnode(X a=0,cllnode *n=0)
	{
		info=a;
		next=n;
	}	
};

//-----------------------------------------------------------------------------------------------------------------------
//-----------------------------------------------------------------------------------------------------------------------

template<class X>
class cllist
{
	cllnode <X>*tail;
	
	public:
	cllist()
	{		
		tail=NULL;
	}
	
	void display()
	{
		cllnode <X> *p;
		if(tail==NULL)
			cout<<"\n\nCircular Linked List is empty ";
		else
		{
			p = tail->next;
			cout<<"\n\nCircular Linked List : ";
			cout<<p->info<<"  ";
			p = p->next;
			while(p!=tail->next)
			{
				cout<<p->info<<"  ";
				p = p->next;
			}
		}		
	}
//------------------------------------------------------------------------------------------------------------------------	
	void insert_at_end(X x)
	{
		
		cllnode <X> *p = new cllnode<X>(x);
		if(tail==NULL)
		{
			tail = p;
			tail->next = tail;
		}
		else
		{
			p->next = tail->next;
			tail->next = p;
			tail = p;
		}		
	}
//------------------------------------------------------------------------------------------------------------------------	
	void insert_at_beg(X x)
	{
		cllnode <X> *p = new cllnode<X>(x);
		if(tail==NULL)
		{
			tail = p;
			tail->next = tail;
		}
		else
		{
			p->next = tail->next;
			tail->next = p;
		}
	}
//------------------------------------------------------------------------------------------------------------------------	
	
	void insert_after_part_node(X x, X y)
	{
	    cllnode <X> *p = new cllnode<X>(x);
		cllnode <X> *q;
		if(tail==NULL) ;
    
	    else if(tail->info!=y)
        {
           	q = tail->next;
            while( q!=tail && q->info!=y )
                q = q->next;
    
	        if(q==tail)
                cout<<"\n\nElement "<<y<<" doesn't exist ";
    
	        else
            {
        	    p->next = q->next;
                q->next = p;
            }
        }
        
		else
        {
          	p->next = tail->next;
            tail->next = p;
            tail = p;
        }
	}
//------------------------------------------------------------------------------------------------------------------------	
	void insert_before_part_node(X x, X y)
	{
		cllnode <X> *p = new cllnode<X>(x);
		cllnode <X> *q;
        if(tail==NULL) ;
		
		else if((tail->next)->info!=y)
        {
           	q = tail->next;
           	while( (q->next)!=tail->next && (q->next)->info!=y )
           		q = q->next;
        
		    if(q==tail)
                cout<<"\n\nElement "<<y<<" doesn't exist ";
         
		    else
            {
                p->next = q->next;
                q->next = p;
            }
        }
        
		else
        {  
			p->next = tail->next;
			tail->next = p;
		}
	}	
//------------------------------------------------------------------------------------------------------------------------	

	void del_beg()
	{
		cllnode <X> *p;
		if(tail==NULL) ;
		else if(tail->next==tail)
		{
			p = tail;
			tail = NULL;
			delete(p);
		}
		else
		{
			p = tail->next;
			tail->next = p->next;
			delete(p);
		}
	}
//------------------------------------------------------------------------------------------------------------------------		
	void del_end()
	{
		cllnode <X> *p, *q;
		if(tail==NULL) ;
		else if(tail->next==tail)
		{
			p = tail;
			tail = NULL;
			delete(p);
		}
		
		else
		{
			p = tail->next;
			while(p!=tail)
			{
				q = p;
				p = p->next;
			}
			tail = q;
			tail->next = tail->next->next;
			delete(p);
		}
	}
//------------------------------------------------------------------------------------------------------------------------
	void del_node(X x)
	{
		cllnode <X> *p, *q;
		if(tail==NULL) ;
		else if( (tail->next)->info==x)
		{
			if (tail->next==tail)
			{
				p = tail;
				tail = NULL;
			}
			else
			{
				p = tail->next;
				tail->next = p->next;
			}
			delete(p);
		}
		else if(tail->info==x)
		{
			p = tail->next;
            while(p!=tail)
            {
                q = p;
                p = p->next;
            }
            tail = q;
			tail->next = tail->next->next;
			delete(p);
        }
		else
		{
			p = tail->next;
			while(p->info!=x && p!=tail)
			{
				q = p;
				p = p->next;
			}
			if(p==tail)
				cout<<"\n\nElement not found ";
			else
			{
				q->next = p->next;
				delete(p);
			}
        }
	}
//------------------------------------------------------------------------------------------------------------------------
	void searching(X x)
    {
        cllnode <X> *p;
		int counter = 1;
		if(tail==NULL)
			cout<<"\n\nCircular Linked list is empty ";
		else if(tail->info==x)
		    cout<<"\n\nElement found at last position";
		else 
		{
			p = tail->next;
			while(p!=tail)
			{
				if (p->info==x)
                {
                    cout<<"\n\nElement found at position : "<<counter;                    
                    return ;
                }
                p = p->next;
				counter++;
			}
			cout<<"\n\nElement not found";						
		}		
    }
//------------------------------------------------------------------------------------------------------------------------	

	void reverse()
	{
		cllnode <X>*p,*q,*r, *beg;
				
		if(tail==0) ;			
			
		else if(tail->next==tail)
		{
			cout<<"\n!!Linked list is already reversed!!";
			return;
		}
		
		else
		{
			p=tail->next;
			q=p->next;
			beg=tail->next;
			
			while(q!=beg)
			{
				
				r=q->next;
				q->next=p;
				p=q;
				q=r;				
			}
			
			beg->next=tail;
			tail=beg;
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
	cllist <int>ob1,ob2,ob3;
	
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
	  do{		system("cls");
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
      				case 1 :cout<<"Enter the integer to Enter at end : ";
							cin>>x;							
					  		ob1.insert_at_end(x);      						
							ob1.display();
							cout<<endl;
							break;
							 
      				case 2 :cout<<"Enter the integer to Enter at beginning : ";
							cin>>x;							
							ob1.insert_at_beg(x);
							ob1.display();
							cout<<endl;
							break;
							
      				case 3 :
      					    cout<<"Enter number after which you want to insert new node : ";
					        cin>>y;
					        cout<<"Enter number to be inserted : ";
					        cin>>x;
							ob1.insert_after_part_node(x,y);				
							ob1.display();
							cout<<endl;
							break;
							
      				case 4 :cout<<"Enter number before which you want to insert new node : ";
					        cin>>y;
					        cout<<"Enter number to be inserted : ";
					        cin>>x;
							ob1.insert_before_part_node(x,y);			
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
							ob1.display();
							cout<<endl;
							break;
							 
      				case 2 :ob1.del_beg();      					
							ob1.display();
							cout<<endl;
							break;
							
      				case 3 :cout<<"Enter the node which you wish to delete : ";
      						cin>>x;      						
      						ob1.del_node(x);      					
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
              
      case 3: do{ system("cls");
      			  cout<<"Enter the number you wish to search : ";
      			  cin>>x;      			  
	  		      ob1.searching(x);	  		  
			      cout<<endl;
				  cout<<"\n->Press 'Y' to search again & Press 'N' to exit this operation."<<endl;
     			  cout<<"#Enter Your Choice : ";
     			  cin>>c;                  
                }
                while(c=='y'||c=='Y');
                break;
      
      case 4: do{	system("cls");
      				cout<<"===>ORIGINAL:-";
      				ob1.display();      				
		  			ob1.reverse();
	      		    cout<<"\n\n===>REVERSED:-";
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
