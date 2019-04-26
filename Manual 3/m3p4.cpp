#include<iostream>
using namespace std;

int main()
{
	int size,temp;
	cout<<"Enter the size of array: ";
	cin>>size;
	
	int arr[size];
	
	cout<<"Enter the array of 0s, 1s and 2s: ";
	for(int i=0;i<size;i++)
		cin>>arr[i];
	
	for(int j=0;j<size;j++)
	{
		for(int i=0;i<size-j-1;i++)
		{
			if(arr[i]>arr[i+1])
			{
				temp=arr[i];
				arr[i]=arr[i+1];
				arr[i+1]=temp;
			}
		}
	}
		
	cout<<endl<<"The sorted array of 0s, 1s and 2s is: ";
	for(int k=0;k<size;k++)
		cout<<arr[k]<<", ";
	
	return 0;
}
