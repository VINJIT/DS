#include<iostream>
using namespace std;

int main()
{
	int item,flag=0,size;
	cout<<"Enter the size of array: ";
	cin>>size;
	
	int arr[size];
	
	cout<<"Enter the array: ";
	for(int i=0;i<size;i++)
		cin>>arr[i];
	
	cout<<"Enter the element to find: ";
	cin>>item;
	
	for(int j=0;j<size;j++)
	{
		if(arr[j]==item)
		{
			cout<<"\n\nElement "<<item<<" found at position "<<j+1;
			flag=1;
			break;
		}		
	}	
	
	if(flag==0)
		cout<<"Element not found";
	
	return 0;
}
