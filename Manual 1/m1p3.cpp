#include<iostream>

using namespace std;

int main()
{
	int size;
	cout<<"Enter the size of the array: ";
	cin>>size;
	
	int arr[size];
	cout<<"Enter the array: ";
	
	for(int i=0;i<size;i++)
	{
		cin>>arr[i];
	}
	
	cout<<"Alternate array is: ";
	for(int i=0;i<size;i++)
	{
		cout<<arr[i]<<", ";
		i++;
	}
	return 0;
	
}
