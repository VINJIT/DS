#include<iostream>

using namespace std;

int main()
{
	int size;
	
	cout<<"Enter the size of array: ";
	cin>>size;
	
	int arr[size];
	int frequency[size];
	
	cout<<"Enter the array: ";
	for(int i=0;i<size;i++)
		cin>>arr[i];
			
	for(int i=0;i<size;i++)
		frequency[i]=0;
	
	int j;
	
	for(int i=0;i<size;i++)
	{
		j=arr[i];
		frequency[j]++;
	}
	
	cout<<"\nElement -----------> Occurances"<<endl<<endl;
	for(int j=0;j<size;j++)
	{
		if(frequency[j]!=0)
			cout<<"   "<<j<<"    ----------->    "<<frequency[j]<<endl;
	}
	
	
}
