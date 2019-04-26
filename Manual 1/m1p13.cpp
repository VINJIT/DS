#include<iostream>
using namespace std;

int main()
{
	int size,pos;
	cout<<"Enter the size of array: ";
	cin>>size;
	
	int arr[size];
	cout<<"Enter the array: ";
	for(int i=0;i<size;i++)
		cin>>arr[i];
		
	cout<<"\nEnter the position: ";
	cin>>pos;
	
	cout<<"\nElement at position "<<pos<<" is: "<<arr[pos-1];
}
