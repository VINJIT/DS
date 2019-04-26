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
	int size,p=0,q=0;
	cout<<"Enter the size of main array: ";
	cin>>size;
	int arr[size];
	int arr2[size];
	cout<<"\nEnter the array: ";
	for(int i=0;i<size;i++)
		cin>>arr[i];		
	
	for(int i=0;i<size;i++)
		arr2[i]=arr[i];
		
	insertionsort(arr2,size);
		
	for(int i=0;i<size;i++)
	{
		if(arr[i]==arr2[i])
		{
			p++;
		}
		else
			break;
	}
	
	for(int i=size-1;i>=0;i--)
	{
		if(arr[i]==arr2[i])
		{
			q++;
		}
		else
			break;
	}
	
	int n=size-(q+p);
	
	cout<<"Length of subarray to be sorted is: "<<n;
	
	return 0;
}
