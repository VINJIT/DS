#include<iostream>

using namespace std;

int main()
{
	int temp;
	int arr[20]={1,0,0,1,1,0,0,0,0,1,0,1,1,0,1,1,1,0,1,0};
	
	for(int i=0;i<20;i++)
	{
		for(int j=0;j<20-i-1;j++)
		{
			if(arr[j]>arr[j+1])
			{
				temp=arr[j];
				arr[j]=arr[j+1];
				arr[j+1]=temp;
			}
		}
	}
	
	for(int i=0;i<20;i++)
	{
		cout<<arr[i]<<", ";
	}
}
