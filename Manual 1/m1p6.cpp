#include<iostream>

using namespace std;

int main()
{
	int size,count=0;
	cout<<"Enter the size of the array: ";
	cin>>size;
	
	int arr[size];
	cout<<"Enter the array: ";
	
	for(int i=0;i<size;i++)
	{
		cin>>arr[i];
	}

/*	for(int i=0;i<size;i++)
	{
		for(int j=i+1;j<size;j++)	
		{
			if(arr[i]==arr[j])
			{
				arr[j]=-1;
			}
		}
	}
	
	cout<<"Number of non repeated elements in array are: ";
	
	for(int i=0;i<size;i++)
	{
		if(arr[i]!=-1)
		{
			cout<<arr[i]<<", ";
			count++;
		}
	}
	cout<<" = "<<count<<" elements";
	}*/
	
	int flag;
	
	cout<<"Non-repeated elements in array are: ";
	for(int i=0;i<size;i++)
	{
		flag=0;
		for(int j=0;j<size;j++)	
		{
			if(i==j)
				j++;
			
			else if(arr[i]==arr[j])
				flag=1;			
		}
		
		if(flag==0)
		{
			cout<<arr[i]<<", ";
			count++;
		}
	}
	
	cout<<" = "<<count<<" elements";

	return 0;
	
}
