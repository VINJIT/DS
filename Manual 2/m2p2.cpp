#include<iostream>
using namespace std;

int main()
{
	int size;
	cout<<"Enter the size of array: ";
	cin>>size;
	
	int arr[size],sqarray[size];
	
	cout<<"Enter the array: ";
	for(int i=0;i<size;i++)
		cin>>arr[i];
	
	for(int j=0;j<size;j++)
		sqarray[j]=arr[j]*arr[j];
		
	cout<<endl<<"The square array is: ";
	for(int k=0;k<size;k++)
		cout<<sqarray[k]<<", ";
	
	return 0;
}
