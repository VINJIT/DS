#include<iostream>
using namespace std;

void selectionsort(int arr[],int size)
{
	int min,temp,pos;
	 
	for(int i=0;i<size-1;i++)
	{
		int swap=0;
		min=arr[i];
		pos=i;
		for(int j=i+1;j<size;j++)
		{
			if(arr[j]<min)
			{
				min=arr[j];	
				pos=j;	
				swap=1;
			}
		}
		
		if(swap==1)
		{
			temp=arr[i];
			arr[i]=arr[pos];
			arr[pos]=temp;
		}
	
	}

	cout<<"\nSorted array is: ";
	for(int m=0;m<size-1;m++)
		cout<<arr[m]<<", ";
	cout<<arr[size-1];
}

int main()
{
	int size;
	cout<<"Enter number of elements in array: ";
	cin>>size;
	
	int arr[size];
	cout<<"Enter the array: \n";
	
	for(int i=0;i<size;i++)
	{
		cin>>arr[i];
	}
	
	selectionsort(arr,size);
	
	

}
