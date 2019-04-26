#include<iostream>

using namespace std;

int fact(int num)
{
	if(num==1 || num==0)
		return 1;
	else
		return (num*fact(num-1));
}

int main()
{
	int rows,x;
	cout<<"Enter number of rows: ";
	cin>>rows;
	
	for(int n=0;n<rows;n++)
	{
		for(int r=0;r<=(rows-n-2);r++)
		{
			cout<<" ";
		}
		
		for(int r=0;r<=n;r++)
		{
			x=fact(n)/(fact(r)*fact(n-r));
			cout<<x<<" ";
		}
		cout<<endl;
	}
	return 0;
}	
