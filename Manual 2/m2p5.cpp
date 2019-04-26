#include<iostream>
using namespace std;

int main()
{
	int size1,size2,temp,j=0,tsize;
	double median=0.0;
	
	cout<<"Enter the size of 1st array: ";
	cin>>size1;
	
	int arr1[size1];	
	cout<<"\nEnter 1st sorted array: ";
	for(int i=0;i<size1;i++)
		cin>>arr1[i];
		
	cout<<"\n\n\nEnter the size of 2nd array: ";
	cin>>size2;
	
	tsize=size1+size2;
	
	int arr2[size2],mergedarr[tsize];	
	
	cout<<"\nEnter 2nd sorted array: ";
	for(int i=0;i<size2;i++)
		cin>>arr2[i];
		
	for(int i=0;i<tsize;i++)
	{
		if(i<size1)
			mergedarr[i]=arr1[i];
		
		else if(i>=size1)
		{
			mergedarr[i]=arr2[j];
			j++;
		}
	}
	
	for(int i=0;i<tsize;i++)
	{
		for(int j=0;j<tsize-i-1;j++)
		{
			if(mergedarr[j]>mergedarr[j+1])
			{
				temp=mergedarr[j];
				mergedarr[j]=mergedarr[j+1];
				mergedarr[j+1]=temp;
			}
			
		}
	}
	
	cout<<"\n\n\nMerged array is: ";
	for(int i=0;i<tsize;i++)
		cout<<mergedarr[i]<<", ";
		
	if(tsize%2==0)
	{
		median=(float)(mergedarr[(tsize/2)-1]+mergedarr[tsize/2])/2;
		cout<<"\nMEDIAN is: "<<median;
	}
	else
	{
		median=mergedarr[tsize/2];
		cout<<"\nMEDIAN is: "<<median;
	}
}
	
	
