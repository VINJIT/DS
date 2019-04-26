#include<iostream>

using namespace std;

int main()
{
	int size;
	
	cout<<"Enter the size of array: ";
	cin>>size;
	
	int arr[size];
	int oddarray[size];
	int evenarray[size];
	
	cout<<"Enter the array: ";
	for(int i=0;i<size;i++)
		cin>>arr[i];
	
	int k=0;
	int l=0;
	for(int j=0;j<size;j++)
	{		
		if(arr[j]%2!=0)
		{
			oddarray[k]=arr[j];
			k++;			
		}
		
		else
		{
			evenarray[l]=arr[j];
			l++;
		}
	}
	
	cout<<"\nOdd array is: ";
	for(int i=0;i<size;i++)
	{
		if(oddarray[i]!=0)
			cout<<oddarray[i]<<", ";
		else
			break;
	}
	
	cout<<"\n\nEven array is: ";
	for(int i=0;i<size;i++)
	{
		if(evenarray[i]!=0)
			cout<<evenarray[i]<<", ";
		else
			break;
	}
}

