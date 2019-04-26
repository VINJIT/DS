#include<iostream>
using namespace std;


void insertion(int arr[],int n,int loc,int item)
{
	for(int i=n;i>=loc;i--)
	{
		arr[i]=arr[i-1];
	}
	arr[loc]=item;
}

int main()
{
	int size,pos,item;
	cout<<"Enter the size: ";
	cin>>size;
	
	int arr[size+1];
	cout<<"Enter the array: ";
	
	for(int i=0;i<size;i++)
		cin>>arr[i];
		
	cout<<"Enter the new element: ";
	cin>>item;
	
	cout<<"Enter the position of new element: ";
	cin>> pos;
	
		
	insertion(arr,size+1,pos-1,item);
	
	for(int i=0;i<size+1;i++)
		cout<<arr[i]<<", ";
	
}

