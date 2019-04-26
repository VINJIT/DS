#include<iostream>
using namespace std;

int main()
{
	int size,ceil,floor,flag=0;
	float X;
	cout<<"Enter the size of array: ";
	cin>>size;
	
	int arr[size];
	cout<<"Enter the array: ";
	for(int i=0;i<size;i++)
		cin>>arr[i];
	
	cout<<"Enter the value of X: ";
	cin>>X;
	
	for(int i=0;i<size;i++)
	{
		if(arr[i]<=X)
		{
			floor=arr[i];
			flag=1;
		}
	}
	
	if(flag==1)
	{
		cout<<"\n\nThe floor of "<<X<<" is: "<<floor;
	}
	
	else
		cout<<"** No floor found **";
		
	//---------------------------------------------------------------------------------------------
	cout<<endl<<endl;
	flag=0;
	for(int i=size;i>0;i--)
	{
		if(arr[i]>=X)
		{
			ceil=arr[i];
			flag=1;
		}
	}
	
	if(flag==1)
	{
		cout<<"The ceil of "<<X<<" is: "<<ceil<<endl;
	}
	
	
	else
		cout<<"**No ceil found**";
	
}
