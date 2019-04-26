#include<iostream>
using namespace std;

int main()
{
	int var,size;
	cout<<"Enter number of characters in your string: ";
	cin>>size;
	
	char arr[size];
	int asarr[size];
	
	cout<<"Enter the array: ";
	for(int i=0;i<size;i++)
		cin>>arr[i];
	
	for(int i=0;i<size;i++)
	{
		var=arr[i];
		asarr[i]=var;
	}
	
	cout<<"ASCII values of characters in your string are: ";
	for(int i=0;i<size;i++)
		cout<<asarr[i]<<", ";
		
	return 0;
}
