#include<iostream>
using namespace std;

int main()
{
	int item,x,lb=0,ub,mid,flag=0;
	
	cout<<"Enter the size of array: ";
	cin>>ub;
	
	int arr[ub];
	
	cout<<"Enter the array in sorted fashion: ";
	for(int i=0;i<ub;i++)
		cin>>arr[i];	
	
	cout<<"Enter the element to find: ";
	cin>>item;
	
	while(lb<=ub)
	{
		mid=(lb+ub)/2;
		
		if(arr[mid]==item)
		{
			cout<<"Element "<<item<<" found at position "<<mid+1;
			flag=1;
			break;
		}
		
		else if(mid<item)
			lb=mid+1;
			
		else if(mid>item)
			ub=mid-1;
		
	}
	
	if(flag==0)
		cout<<"Element not found";	
		
	return 0;
}
