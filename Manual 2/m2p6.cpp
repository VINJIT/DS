#include<iostream>

using namespace std;

void unionset(int arr1[],int arr2[],int size1,int size2)
{
	int j=0,tsize=size1+size2;
	int uni[tsize];
	
	for(int i=0;i<tsize;i++)
	{
		if(i<size1)
			uni[i]=arr1[i];
		else 
		{
			uni[i]=arr2[j];
			j++;
		}
	}
	
	for(int i=0;i<tsize;i++)
	{
		for(int j=i+1;j<tsize;j++)
		{
			if(uni[i]==uni[j])
			{
				for(int k=j;k<tsize;k++)
				{
					uni[k]=uni[k+1];
				}
				tsize--;
				j--;
			}
		}		
	}
	
	
	cout<<"Union of these two sets is: ";
	for(int i=0;i<tsize;i++)
		cout<<uni[i]<<", ";
}

void intersection(int arr1[],int arr2[],int size1,int size2)
{
	int s=0;
	int inter[size1+size2];
	for(int i=0;i<size1;i++)
	{
		for(int j=0;j<size2;j++)
		{
			if(arr1[i]==arr2[j])
			{	
				inter[s]=arr1[i];
				s++;
			}
		}
	}
	
	cout<<"\nIntersection of these two sets is: ";
	for(int i=0;i<s;i++)
		cout<<inter[i]<<", ";
	
}

int main()
{
	int size1,size2;
	cout<<"Enter the size of 1st array: ";
	cin>>size1;
	
	int arr1[size1];
	cout<<"Enter 1st array: ";
	for(int i=0;i<size1;i++)
		cin>>arr1[i];
		
	cout<<"Enter the size of 2nd array: ";
	cin>>size2;
	
	int arr2[size2];
	cout<<"Enter 1st array: ";
	for(int i=0;i<size2;i++)
		cin>>arr2[i];
		
	unionset(arr1,arr2,size1,size2);
	intersection(arr1,arr2,size1,size2);
	return 0;
}
