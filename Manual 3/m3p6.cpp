#include<iostream>

using namespace std;

int main()
{
	int size,size2,flag=0;
	cout<<"Enter the size of main array: ";
	cin>>size;
	int arr[size];
	cout<<"\nEnter the array: ";
	for(int i=0;i<size;i++)
		cin>>arr[i];
	
	cout<<"\nEnter the size of subset array: ";
	cin>>size2;
	int arr2[size2];
	cout<<"\nEnter the subset array: ";
	for(int i=0;i<size2;i++)
		cin>>arr2[i];
	
	for(int j=0;j<size2;j++)
	{
		flag=0;
		
		for(int k=0;k<size;k++)
		{
			if(arr2[j]==arr[k])
			{
				arr[k]=-1;
				flag=1;
				break;
			}
		}
		if(flag==0)
		{
			cout<<"Its Not a subset";
			flag=-1;
			break;
		}
	}
	if(flag!=-1)
		cout<<"Yes it is a subset";
		
	return 0;
}
