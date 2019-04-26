#include<iostream>

using namespace std;

int main()
{
	int lb,ub,size,w;
	cout<<"Enter the Lower bound: ";
	cin>>lb;
	
	cout<<"Enter the upper bound: ";
	cin>>ub;
	
	cout<<"Enter the size of array: ";
	cin>>size;
	
	int arr[size];
	cout<<"Enter the array: ";
	for(int i=0;i<size;i++)
	{
		cin>>w;
		if(w<=ub && w>=lb)
		{
			arr[i]=w;
		}
		
		else
		{
			arr[i]=-1;
		}
	}
	
	cout<<"Resultant array is:";
	for(int j=0;j<size;j++)
	{
		if(arr[j]!=-1)
			cout<<arr[j]<<", ";
	}
	return 0;
}

