#include<iostream>
using namespace std;


void deletion(int arr[],int size,int item)
{
	int newsize=size;
	for(int i=0;i<size;i++)
	{
		if(arr[i]==item)
		{
			for(int j=i+1;j<size;j++)
			{
				arr[j-1]=arr[j];
			}
			newsize--;
		}
	}
	
	cout<<"Updated array is: ";
	for(int i=0;i<newsize;i++)
		cout<<arr[i]<<", ";
	
}

int main()
{
	int size,pos,item;
	cout<<"Enter the size: ";
	cin>>size;
	
	int arr[size];
	cout<<"Enter the array: ";
	
	for(int i=0;i<size;i++)
		cin>>arr[i];
		
	cout<<"Enter the element to delete: ";
	cin>>item;
			
	deletion(arr,size,item);
}

