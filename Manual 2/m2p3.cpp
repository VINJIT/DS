#include<iostream>
using namespace std;

int main()
{
	int temp,size;
	cout<<"Enter the size of array: ";
	cin>>size;
	
	int arr[size];
	
	cout<<"Enter the array: ";
	for(int i=0;i<size;i++)
		cin>>arr[i];
		
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
	
	int minsum=arr[0]+arr[1];
	cout<<"The numbers whose sum is closest to zero is: "<<arr[0]<<" and "<<arr[1]<<endl<<endl<<"Their sum is: "<<minsum;
}
