#include<iostream>

using namespace std;

int main()
{
	int size, size2;
	cout<<"Enter the size of default array: ";
	cin>>size;
	
	int arr[size];
	cout<<"Enter the array: ";
	
	for(int i=0;i<size;i++)
	{
		cin>>arr[i];
	}	
	
	cout<<"Enter the size of checking array: ";
	cin>>size2;
	
	int arr2[size2];
	cout<<"Enter the checking array: ";
	
	for(int i=0;i<size2;i++)
	{
		cin>>arr2[i];
	}
	
	cout<<"Missing numbers are: ";
	for(int i=0;i<size;i++)
	{
		for(int j=0;j<size2;j++)
		{
			if(arr[i]==arr2[j])
			{
				goto yes;
				//continue;
			}			
		}
		cout<<arr[i]<<", ";
		yes:;
	}
	return 0;
	
}
