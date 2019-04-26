#include<iostream>
using namespace std;

void addresscompute(int base, int j, int k, int m, int n)
{
	int rowmajor=base+((sizeof(int))*(n*j+k));
	int colmajor=base+((sizeof(int))*(j+m*k));
	
	cout<<"Address in Row Major is: "<<rowmajor;
	cout<<"\n\nAddress in Column Major is: "<<colmajor;
}



int main()
{

	int base=200, m, j, k, n;

	cout<<"Enter the Number of rows in array: ";
	cin>>m;

	cout<<"Enter the Number of cols in array: ";
	cin>>n;
	
	cout<<"\n\nEnter the Array index: \n\n";
	cout<<"Row no.- ";
	cin>>j;
	
	cout<<"Col no.- ";
	cin>>k;
	
	addresscompute(base,j,k,m,n);

	return 0;
}
