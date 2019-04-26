#include<iostream>
#include<stdio.h>
#include<string>

using namespace std;

int main()
{
	int size;
	cout<<"Enter number of names you wish to sort: ";
	cin>>size;
	
	string temp,arr[size];
	cout<<"Enter names you wish to sort: ";
	
	getline(cin,arr[0]);
	for(int i=0;i<size;i++)
		getline(cin,arr[i]);
		
	for(int i=0;i<size;i++)
	{
		for(int j=0;j<size-i-1;j++)
		{		
			if(arr[j]>arr[j+1])
			{
				temp=arr[j];
				arr[j]=arr[j+1];
				arr[j+1]=temp;
			}
		}
	}
	cout<<"\n\nNames sorted: ";
	
	for(int i=0;i<size;i++)
		cout<<arr[i]<<", ";
		
}
