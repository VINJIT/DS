#include<iostream>

using namespace std; 

void insertionsort(int arr[],int size)
{
	int j,y;
	for(int i=1;i<size;i++)
	{
		y=arr[i];
		for(j=i-1;j>=0 && y<arr[j];j--)
		{
			arr[j+1]=arr[j];
		}
		arr[j+1]=y;
	}

}

int main()
{
	int size;
	
	cout<<"Enter the size of array: ";
	cin>>size;
	
	int arr[size];
	
	cout<<"\nEnter the array: ";
	
	for(int i=0;i<size;i++)
		cin>>arr[i];
		
	insertionsort(arr,size);
	
	cout<<"Sorted array is: ";
	for(int i=0;i<size;i++)
		cout<<arr[i]<<", ";

}
