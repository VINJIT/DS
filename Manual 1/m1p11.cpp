#include<iostream>

using namespace std;

int main()
{
	int size,countodd=0,counteven=0;
	cout<<"Enter the size of the array: ";
	cin>>size;
	
	int arr[size];
	cout<<"Enter the array: ";
	
	for(int i=0;i<size;i++)
	{
		cin>>arr[i];
	}
	
	for(int i=0;i<size;i++)
	{
		if(arr[i]%2!=0)
			countodd++;
		else
			counteven++;
	}
	
	cout<<"Number of odd elements are: "<<countodd<<" and even elements are: "<<counteven;
	return 0;
	
}
