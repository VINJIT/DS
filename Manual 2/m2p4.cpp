#include<iostream>

using namespace std;

int main()
{
	int count=1,size,val;
	
	cout<<"Enter the size of array: ";
	cin>>size;
	
	val=size/2;
	int arr[size];
	
	
	cout<<"Enter the array: ";
	for(int i=0;i<size;i++)
	{	
		cin>>arr[i];
	}
	
	cout<<"\nElements which appear more than N/2 times is: ";
	
	for(int i=0;i<size;i++)
	{
		count=1;
		for(int j=i+1;j<size;j++)
		{
			if(arr[i]==arr[j])
			{
				count++;
			}
		}
		
		if(count>val)
		{
			cout<<arr[i];
		}
		
	}
	
}
