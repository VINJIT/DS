#include<iostream>
using namespace std;

int binary(int lb,int ub,int arr[],int item)
{
	int mid;
	mid=(lb+ub)/2;
	
	while(lb<=ub)
	{
		if(arr[mid]==item)
			return mid;
	
		else if(arr[mid]<item)
			return binary(mid+1,ub,arr,item);
	
		else if(arr[mid]>item)
			return binary(lb,mid-1,arr,item);
	}
			
	return -1;
}
int main()
{
	int item,x,ub;
	cout<<"Enter the size of array: ";
	cin>>ub;
	
	int arr[ub];
	
	cout<<"Enter the array in sorted fashion: ";
	for(int i=0;i<ub;i++)
		cin>>arr[i];
	
	cout<<"Enter the element to find: ";
	cin>>item;
	
	x=binary(0,ub,arr,item);
	
	if(x==-1)
		cout<<"Element not found";	
	else
		cout<<"Element "<<item<<" found at: "<<x+1;
	
	return 0;
}
