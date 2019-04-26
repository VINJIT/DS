//stack bubble sort 
#include<iostream>
#include<string>
#include<stdlib.h>
#define max 20
using namespace std;

template<class X>			//to make generic class
class MyStack
{
	public:
	X st[max];
	int top;
	
	
		MyStack()
		{top=-1;}
		
		bool isfull()
		{
			if(top==max)
				return true;
			else
				return false;
		}
		
		bool isempty()
		{
			if(top==-1)
				return true;
			else
				return false;			
		}
		
		void push(X x)
		{
			if(!isfull())
			{
				top++;
				st[top]=x;
			}
		}
		
		int pop()
		{
			if(!isempty())
			{	int t=st[top];
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

void bubblesort(int a[],int len)
{
	MyStack <int>s1,s2;
	int x,temp1,temp2;	
	for(int i=0;i<len;i++)
		s1.push(a[i]);
	
	for(int i=0;i<len;i++)
	{
		for(int j=0;j<len-i-1;j++)
		{	
			
			if(s2.isempty())
			{
				x = s1.pop();
				s2.push(x);
			}
			
			else
			{ 
				temp1=s1.pop();
				s1.push(temp1);
				temp2=s2.pop();
				s2.push(temp2);
			
				if(temp2<=temp1)
				{			
					x=s1.pop();	
						s2.push(x);
				}
			
				else
				{
					temp2=s2.pop();
					temp1=s1.pop();
					s2.push(temp1);
					s1.push(temp2);
					int temp = s1.pop();
					s2.push(temp);
				}
			}
			s1.display();
			s2.display();	
		}
		
		while(!s2.isempty())
		{
			x=s2.pop();
			s1.push(x);
		}
	}
	cout<<"Sorted array is: ";
	for(int i=0;i<len;i++)
	{
		cout<<s1.pop();
	}
}

int main()
{
	int len;
	cout<<"Enter number of elements: ";
	cin>>len;
	int a[len];
	cout<<"\nEnter the elements: ";
	for(int j=0;j<len;j++)
		cin>>a[j];
				
	bubblesort(a,len);
	return 0;
}
