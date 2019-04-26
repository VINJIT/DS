/*
	Name: Linked List
	Copyright: All rights reserved
	Author: Vinjit
	Date: 01/08/16 22:33
	Description: Operations in a linked list 
*/
#include<iostream>
#include<stdlib.h>
#include<conio.h>
#include<process.h>
using namespace std;

template<class X>
class llnode
{
	public:		
	int info;
	llnode *next;
	llnode(int a=0,llnode *n=0)
	{
		info=a;
		next=n;
	}	
};
//-----------------------------------------------------------------------------------------------------------------------
//-----------------------------------------------------------------------------------------------------------------------
template<class X>
class llist
{
	llnode <X> *head, *tail;
	
	public:
	llist()
	{
		head=0;
		tail=0;
	}
	
	void display()
	{
		llnode <X> *p=head;
		
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
	void insert_at_end(X x)
	{
		llnode <X> *p;		
		p=new llnode <X> (x);
		
		if(head==0)
		{
			head=p;
			tail=p;
		}
		else
		{
			tail->next=p;
			tail=p;
		}
	}
//------------------------------------------------------------------------------------------------------------------------	
	void insert_at_beg()
	{
		int y;
		llnode <X> *p;
		cout<<"Enter the integer to insert at beginning : ";
		cin>>y;
		p=new llnode<X>(y);
		
		if(head==0)
		{
			head=p;
			tail=p;
		}
		else
		{
			p->next=head;
			head=p;		
		}
	}
//------------------------------------------------------------------------------------------------------------------------	
	
	void insert_after_part_node(X x, X y)
	{
	    llnode <X> *p = new llnode <X> (y);
        llnode <X> *q = head;
        
        while(q!=NULL&&q->info!=x)
            q = q->next;
        
        if(q==0)
            {
			   	cout<<"\nSorry.....Item not found! Try Again.\n"<<endl;
	            return;
	        }
        
        else
        {
            p->next =  q->next;
            q->next = p;
            cout<<"\nItem added successfully!\n"<<endl;
        }
	}
//------------------------------------------------------------------------------------------------------------------------	
	void insert_before_part_node(X x, X y)
	{
		llnode <X> *p = new llnode <X> (y);
        llnode <X> *q = head;        
        llnode <X> *r =  NULL;
        
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
	            r = q;
	            q = q->next;
	        }
	        
	        
	        if(q==0)
	           {
			   		cout<<x<<" not found"<<endl;
			   		return;
			   }
	        
	        else
			{
	            p->next = q;
	            r->next = p;
	            cout<<"\n\nItem Added successfully!\n";	
				cout<<endl;
	        }
		}
    }
		
//------------------------------------------------------------------------------------------------------------------------	
	void insert_ordered(X y)
	{
		llnode <X> *q=head;
		llnode <X> *r;
		llnode <X> *p = new llnode<X>(y);
		if(head==0)
		{
			head=p;
			tail=p;
		}
		
		else if(tail->info<=y)
		{
			tail->next=p;
			tail=p;
		}
		
		else if(head->info>=y)
		{
			p->next=head;
			head=p;
		}
		
		else
		{
			while(p->info>q->info)
			{
				r=q;
				q=q->next;
			}			
			r->next=p;
			p->next=q;
		}
}
//------------------------------------------------------------------------------------------------------------------------
	void del_beg()
	{
		llnode <X>*p;		
		p=head;
		head=head->next;
		delete(p);
	}
//------------------------------------------------------------------------------------------------------------------------		
	void del_end()
	{
		llnode <X>*p,*q;
		p=head;
		
		while(p!=tail)
		{
			q=p;
			p=p->next;
		}
			q->next=NULL;
			delete(p);
			tail=q;		
	}
//------------------------------------------------------------------------------------------------------------------------
	void del_node()
	{
		llnode <X> *q=head;
		llnode <X>*p;
		X x;
		cout<<"Enter the node to be deleted : ";
		cin>>x;
		cout<<endl;
		
		if(head->info==x)
		{
			del_beg();		
		}
		
		else
		{
			while (q->info!=x && q!=0)
			{
				p=q;
				q=q->next;
			}
		
		p->next=q->next;
		delete(q);
		}	
	}
//------------------------------------------------------------------------------------------------------------------------
	void searching()
	{
		llnode <X>*p;
		X x;
		cout<<"\nEnter the number you wish to search : ";
		cin>>x;
		p=head;
		llnode <X> *r;
		
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
		 cout<<"\n!!Integer found in linked list!!"; 
		else
		 cout<<"\n!!Integer doesn't exist in linked list! Try Again.";	
   
	}
//------------------------------------------------------------------------------------------------------------------------	
	void reverse()
	{
		llnode <X> *p,*q,*r;
				
		if(head==0)
			cout<<"\n\nERROR: Linked list is Empty!!\n\n";
			
		else if(head->next==NULL)
			cout<<"Linked list is already reversed";
			
		else
		{
			p=head;
			q=p->next;
			r=q->next;
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
		
	}
//------------------------------------------------------------------------------------------------------------------------
	void sorting()
	{
		llnode <X> *p, *q;
			int temp;
			p = head;
	        q = NULL;
			
			if(p==NULL)
			{
				cout<<"\nERROR: EMPTY LINKED LIST\n";
			}
			
			else
			{        
		        while(p->next!=NULL)
		        {
		            q = p->next;
		            while(q!=NULL)
		            {
		                if(p->info>q->info)
		                {
		                    temp = p->info;
		                    p->info = q->info;
		                    q->info = temp;
		                }
		                q = q->next;
		            }
		            p = p->next;
		        }
		    }
		}
			
		/*llnode <X>*p ,*q;
		{
			if(head==0)
				cout<<"\nLinked list is empty. Please insert some elements.";
			
			else if(head->next==0)
				cout<<"The linked list is already sorted";
				
			else
			{
				p=head;
				while(p->next->next!=0)
				{
					q=p->next;
					while(q->next!=0)
					{
						if(q->info<p->info)
						{
							int temp = p->info;
				    		p->info = q->info;
				    		q->info = temp;
				    		
				    		q=q->next;
						}
						p=p->next;
					}
				}
			}
		}		
		
	}*/
//------------------------------------------------------------------------------------------------------------------------
	void concatinate(llist x,llist y)
	{
		llnode <X> *p,*q,*r;
		p=x.head;
		q=y.head;
		
		if((p==0)&&(q==0))
			cout<<"Linked list is empty!!";
			
		else if(p==NULL && q!=NULL)
		{
			head=y.head;
			tail=y.tail;
		}
		
		else if(q==NULL && p!=NULL)
		{
			head=x.head;
			tail=x.tail;
		}
		
		else
		{			
			while(p!=0)
			{
				insert_at_end(p->info);
				p=p->next;
			}
			
			while(q!=0)
			{
				insert_at_end(q->info);
				q=q->next;				
			}
		}				
	}
//------------------------------------------------------------------------------------------------------------------------
    void merge_two_linked_list(llist x, llist y)
		{
			llnode <X> *p=x.head, *q=y.head, *r;
			
			if (p==NULL && q==NULL) 
			{
				cout<<"\nBoth linked lists are Empty\n"<<endl;
				exit(0);				
			}
			else if (p==NULL && q!=NULL)
			{
				head=q;
				tail=y.tail;
			}
			else if (p!=NULL && q==NULL)
			{
				head=p;
				tail=x.tail;
			}
			else
			{
				while (p!=NULL && q!=NULL)
				{
					r=new llnode<X>();
					if (p->info < q->info)
					{
						r->info=p->info;
						p=p->next;
					}
					else
					{
						r->info=q->info;
						q=q->next;
					}
					insert_at_end(r->info);
				}
				
				while (p!=NULL)
				{
					r=new llnode<X>(p->info);
					tail->next=r;
					tail=r;
					p=p->next;
				}
				
				while (q!=NULL)
				{
					r=new llnode<X>(q->info);
					tail->next=r;
					tail=r;
					q=q->next;
				}
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
	llist <int> ob1,ob2,ob4,ob3;
	
do{
	system("cls");
	cout<<"\n......................................................MAIN MENU.....................................................\n"<<endl;
	cout<<"------>Press 1 for INSERTION"<<endl;
	cout<<"------>Press 2 for DELETION"<<endl;
	cout<<"------>Press 3 for SEARCHING"<<endl;
	cout<<"------>Press 4 for REVERSING"<<endl;
	cout<<"------>Press 5 for SORTING"<<endl;
	cout<<"------>Press 6 for CONCATINATION "<<endl;
	cout<<"------>Press 7 for MERGING TWO LINKED LIST "<<endl;
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
			cout<<"------>Press 5 for INSERT ORDERED"<<endl;
			cout<<"\n#Enter your choice : ";
			cin>>ch;
			cout<<endl;
				
			switch(ch)
    		   	{ 
      				case 1 :cout<<"Enter the integer to Enter at end : ";
							cin>>x;
					  		ob1.insert_at_end(x);
      						cout<<"The Linked list is : ";
							ob1.display();
							cout<<endl;
							break;
							 
      				case 2 :ob1.insert_at_beg();
      						cout<<"The Linked list is : ";
							ob1.display();
							cout<<endl;
							break;
							
      				case 3 :
      					    cout<<"Enter number after which you want to insert new node : ";
					        cin>>x;
					        cout<<"Enter number to be inserted : ";
					        cin>>y;
							ob1.insert_after_part_node(x,y);
							cout<<"The Linked list is : ";
							ob1.display();
							cout<<endl;
							break;
							
      				case 4 :cout<<"Enter number before which you want to insert new node : ";
					        cin>>x;
					        cout<<"Enter number to be inserted : ";
					        cin>>y;
							ob1.insert_before_part_node(x,y);
					        cout<<"The Linked list is : ";
							ob1.display();
							cout<<endl;
							break;
	
      				case 5 :cout<<"Please enter number of elements you wish to insert in the linked list : ";
      						cin>>size;
      						cout<<endl;
      						
      						for(int i=0;i<size;i++)
      						{
      							cout<<"Please insert your element "<<i+1<<" : ";
      							cin>>y;
      							ob1.insert_ordered(y);
							}
					  		cout<<"\nThe linked list is: ";
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
	  		do{ 
	  			system("cls");
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
      						cout<<"The Linked list is : ";
							ob1.display();
							cout<<endl;
							break;
							 
      				case 2 :ob1.del_beg();
      						cout<<"The Linked list is : ";
							ob1.display();
							cout<<endl;
							break;
							
      				case 3 :ob1.del_node();
      						cout<<"The Linked list is : ";
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
	      		    cout<<"The Reversed Linked list is : ";
				    ob1.display();
	                cout<<endl;
	                cout<<"\n->Press 'Y' to reverse again & Press 'N' to exit this operation."<<endl;
	     			cout<<"#Enter Your Choice : ";
	     			cin>>c;  					  
				}
				while(c=='y'||c=='Y');
				cout<<endl;
            	break;
              
      case 5: system("cls");
	  		  ob1.sorting(); 
	  		  cout<<"The Sorted Linked list is : ";
			  ob1.display(); 
              cout<<endl;
			  break;
              
      case 6: do{
			  		system("cls");
					cout<<"\n......SELECT THE MODE OF INSERTION FOR FIRST LINKED LIST......"<<endl<<endl;
					cout<<"------>Press 1 for INSERTION AT END"<<endl;
					cout<<"------>Press 2 for INSERTION AT BEGINNING"<<endl;
					cout<<"------>Press 3 for INSERTION AFTER A NODE"<<endl;
					cout<<"------>Press 4 for INSERTION BEFORE A NODE "<<endl;
					cout<<"------>Press 5 for INSERT ORDERED"<<endl;
					cout<<"\n#Enter your choice : ";
					cin>>ch;
					cout<<endl;
						
					switch(ch)
		    		{ 
		      			case 1 :cout<<"Enter the integer to Enter at end : ";
								cin>>x;
							  	ob2.insert_at_end(x);
		      					cout<<"The First Linked list is : ";
								ob2.display();
								cout<<endl;
								break;
									 
		      			case 2 :ob2.insert_at_beg();
		      					cout<<"The First Linked list is : ";
								ob2.display();
								cout<<endl;
								break;
									
		      			case 3 :
		      				    cout<<"Enter number after which you want to insert new node : ";
						        cin>>x;
						        cout<<"Enter number to be inserted : ";
						        cin>>y;
								ob2.insert_after_part_node(x,y);
								cout<<"The First Linked list is : ";
								ob2.display();
								cout<<endl;
								break;
									
		      			case 4 :cout<<"Enter number before which you want to insert new node : ";
						        cin>>x;
						        cout<<"Enter number to be inserted : ";
						        cin>>y;
								ob2.insert_before_part_node(x,y);
						        cout<<"The First Linked list is : ";
								ob2.display();
								cout<<endl;
								break;
			
		      			case 5 :cout<<"Please enter number of elements you wish to insert in the linked list : ";
		      					cin>>size;
		      					cout<<endl;
		      					
		      					for(int i=0;i<size;i++)
		      					{
		      						cout<<"Please insert your element "<<i+1<<" : ";
		      						cin>>y;
		      						ob2.insert_ordered(y);
								}
						
						  		cout<<"The First Linked list is : ";
		      					ob2.display();
		      					cout<<endl;
		      					break;
		      						
		      			default : cout<<"Invalid input! Try Again."<<endl;
		      					break;
		      		}				 
		     			cout<<"\n->Press 'Y' to insert again & Press 'N' to insert second list."<<endl;
		     			cout<<"#Enter Your Choice : ";
		     			cin>>c;  					  
				}
				while(c=='y'||c=='Y');
      			  
      			do{
      				system("cls");
			  		cout<<"\n......SELECT THE MODE OF INSERTION FOR SECOND LINKED LIST......"<<endl<<endl;
					cout<<"------>Press 1 for INSERTION AT END"<<endl;
					cout<<"------>Press 2 for INSERTION AT BEGINNING"<<endl;
					cout<<"------>Press 3 for INSERTION AFTER A NODE"<<endl;
					cout<<"------>Press 4 for INSERTION BEFORE A NODE "<<endl;
					cout<<"------>Press 5 for INSERT ORDERED"<<endl;
					cout<<"\n#Enter your choice : ";
					cin>>ch;
					cout<<endl;
					
				switch(ch)
		    	   	{ 
		      			case 1 :cout<<"Enter the integer to Enter at end : ";
								cin>>x;
						  		ob3.insert_at_end(x);
		      					cout<<"The Second Linked list is : ";
								ob3.display();
								cout<<endl;
								break;
								 
		      			case 2 :ob3.insert_at_beg();
		      					cout<<"The Second Linked list is : ";
								ob3.display();
								cout<<endl;
								break;
								
		      			case 3 :
		      				    cout<<"Enter number after which you want to insert new node : ";
						        cin>>x;
						        cout<<"Enter number to be inserted : ";
						        cin>>y;
								ob3.insert_after_part_node(x,y);
								cout<<"The Second Linked list is : ";
								ob3.display();
								cout<<endl;
								break;
									
		      			case 4 :cout<<"Enter number before which you want to insert new node : ";
						        cin>>x;
						        cout<<"Enter number to be inserted : ";
						        cin>>y;
								ob3.insert_before_part_node(x,y);
						        cout<<"The Second Linked list is : ";
								ob3.display();
								cout<<endl;
								break;
			
		      			case 5 :cout<<"Please enter number of elements you wish to insert in the linked list : ";
		      					cin>>size;
		      					cout<<endl;
		      					
		      					for(int i=0;i<size;i++)
		      					{
		      						cout<<"Please insert your element "<<i+1<<" : ";
		      						cin>>y;
		      						ob3.insert_ordered(y);
								}
				
						  		cout<<"The Second Linked list is : ";
		      					ob3.display();
		      					cout<<endl;
		      					break;
		      						
		      			default : cout<<"Invalid input! Try Again."<<endl;
		      					break;
		      		}				 
		     		cout<<"\n->Press 'Y' to insert again & Press 'N' to see the output."<<endl;
		     		cout<<"#Enter Your Choice : ";
		     		cin>>c;  					  
				}
				while(c=='y'||c=='Y');
				cout<<"The two inserted linked lists are :\n";
				
				cout<<"\nThe First Linked list is : ";
				ob2.display();
				cout<<endl;
				cout<<"The Second Linked list is : ";
				ob3.display(); 
	  		      			  
		  		ob4.concatinate(ob2,ob3);
	      		cout<<"\nThe concatinated Linked list is : ";
				ob4.display();
	            cout<<endl;	            		
			    break;   
              
      case 7: do{
      				system("cls");
			  		cout<<"\n......SELECT THE MODE OF INSERTION FOR FIRST LINKED LIST......"<<endl<<endl;
					cout<<"------>Press 1 for INSERTION AT END"<<endl;
					cout<<"------>Press 2 for INSERTION AT BEGINNING"<<endl;
					cout<<"------>Press 3 for INSERTION AFTER A NODE"<<endl;
					cout<<"------>Press 4 for INSERTION BEFORE A NODE "<<endl;
					cout<<"------>Press 5 for INSERT ORDERED"<<endl;
					cout<<"\n#Enter your choice : ";
					cin>>ch;
					cout<<endl;
						
					switch(ch)
		    		{ 
		      			case 1 :cout<<"Enter the integer to Enter at end : ";
								cin>>x;
							  	ob2.insert_at_end(x);
		      					cout<<"The First Linked list is : ";
								ob2.display();
								cout<<endl;
								break;
									 
		      			case 2 :ob2.insert_at_beg();
		      					cout<<"The First Linked list is : ";
								ob2.display();
								cout<<endl;
								break;
									
		      			case 3 :
		      				    cout<<"Enter number after which you want to insert new node : ";
						        cin>>x;
						        cout<<"Enter number to be inserted : ";
						        cin>>y;
								ob2.insert_after_part_node(x,y);
								cout<<"The First Linked list is : ";
								ob2.display();
								cout<<endl;
								break;
									
		      			case 4 :cout<<"Enter number before which you want to insert new node : ";
						        cin>>x;
						        cout<<"Enter number to be inserted : ";
						        cin>>y;
								ob2.insert_before_part_node(x,y);
						        cout<<"The First Linked list is : ";
								ob2.display();
								cout<<endl;
								break;
			
		      			case 5 :cout<<"Please enter number of elements you wish to insert in the linked list : ";
		      					cin>>size;
		      					cout<<endl;
		      					
		      					for(int i=0;i<size;i++)
		      					{
		      						cout<<"Please insert your element "<<i+1<<" : ";
		      						cin>>y;
		      						ob2.insert_ordered(y);
								}
						
						  		cout<<"The First Linked list is  : ";
		      					ob2.display();
		      					cout<<endl;
		      					break;
		      						
		      			default : cout<<"Invalid input! Try Again."<<endl;
		      					break;
		      		}				 
		     			cout<<"\n->Press 'Y' to insert again & Press 'N' to insert second list."<<endl;
		     			cout<<"#Enter Your Choice : ";
		     			cin>>c;  					  
				}
				while(c=='y'||c=='Y');
      			  
      			do{
      				system("cls");
			  		cout<<"\n......SELECT THE MODE OF INSERTION FOR SECOND LINKED LIST......"<<endl<<endl;
					cout<<"------>Press 1 for INSERTION AT END"<<endl;
					cout<<"------>Press 2 for INSERTION AT BEGINNING"<<endl;
					cout<<"------>Press 3 for INSERTION AFTER A NODE"<<endl;
					cout<<"------>Press 4 for INSERTION BEFORE A NODE "<<endl;
					cout<<"------>Press 5 for INSERT ORDERED"<<endl;
					cout<<"\n#Enter your choice : ";
					cin>>ch;
					cout<<endl;
					
				switch(ch)
		    	   	{ 
		      			case 1 :cout<<"Enter the integer to Enter at end : ";
								cin>>x;
						  		ob3.insert_at_end(x);
		      					cout<<"The Second Linked list is : ";
								ob3.display();
								cout<<endl;
								break;
								 
		      			case 2 :ob3.insert_at_beg();
		      					cout<<"The Second Linked list is : ";
								ob3.display();
								cout<<endl;
								break;
								
		      			case 3 :
		      				    cout<<"Enter number after which you want to insert new node : ";
						        cin>>x;
						        cout<<"Enter number to be inserted : ";
						        cin>>y;
								ob3.insert_after_part_node(x,y);
								cout<<"The Second Linked list is : ";
								ob3.display();
								cout<<endl;
								break;
									
		      			case 4 :cout<<"Enter number before which you want to insert new node : ";
						        cin>>x;
						        cout<<"Enter number to be inserted : ";
						        cin>>y;
								ob3.insert_before_part_node(x,y);
						        cout<<"The Second Linked list is : ";
								ob3.display();
								cout<<endl;
								break;
			
		      			case 5 :cout<<"Please enter number of elements you wish to insert in the linked list : ";
		      					cin>>size;
		      					cout<<endl;
		      					
		      					for(int i=0;i<size;i++)
		      					{
		      						cout<<"Please insert your element "<<i+1<<" : ";
		      						cin>>y;
		      						ob3.insert_ordered(y);
								}
				
						  		cout<<"The Second Linked list is : ";
		      					ob3.display();
		      					cout<<endl;
		      					break;
		      						
		      			default : cout<<"Invalid input! Try Again."<<endl;
		      					break;
		      		}				 
		     		cout<<"\n->Press 'Y' to insert again & Press 'N' to see the output."<<endl;
		     		cout<<"#Enter Your Choice : ";
		     		cin>>c;  					  
				}
				while(c=='y'||c=='Y');
				cout<<"\nThe two inserted linked lists are :\n";
				
				cout<<"\nThe First Linked list is : ";
				ob2.display();				
				ob2.sorting();				
				cout<<endl;
				
				cout<<"The Second Linked list is : ";
				ob3.display();					
				ob3.sorting();								
      			
				cout<<"\nThe merged Linked list is : ";				
		  		ob4.merge_two_linked_list(ob2,ob3); 		  		
		  		ob4.display();    
	            cout<<endl;
	            
				cout<<"\n->Press 'Y' to merge another linked list & Press 'N' to exit this operation."<<endl;
		     	cout<<"#Enter Your Choice : ";
		     	cin>>c;			 
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
