#include<iostream>

using namespace std;

int main()
{
	int count=0;
	int arr[20]={1,2,5,6,8,3,2,9};
	
	for(int i=0;i<20;i++)
	{
		if(arr[i]!=NULL)
		{
			count++;
		}
	}
	cout<<"No. of elements are:"<<count;
	return 0;
}
