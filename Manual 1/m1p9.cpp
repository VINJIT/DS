#include<iostream>

using namespace std;

int main()
{
	int temp,size;
	
	cout<<"Enter the size of array: ";
	cin>>size;
	int arr[size];
	cout<<"Enter the array: ";
	for(int k=0;k<size;k++)
	{
		cin>>arr[k];	
	} 
	
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
	
	int diff=arr[size-1]-arr[0];
	cout<<"Max difference between elements is: "<<diff;
	return 0;
}
