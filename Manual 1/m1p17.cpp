#include <iostream>
using namespace std;

void perm (int A[], int n, int b) 
{
    if (b==n-1) 
    {
		for (int j=0; j<n; j++) 
        	cout <<A[j];
		cout<<"\n";
	} 
	
    else
	{
		for (int i=0; i<n; i++)        

		{	
            swap(A[b],A[i]);
			perm (A,n,b+1);       
            swap(A[b],A[i]);
		}
    } 
}
		
int main() 
{     
    static int n;
    int A[n];
    int b=0;

    cout<<"Enter the number of elements : ";
    cin>>n;
    cout<<endl;
    cout<<"Enter the Elements : ";
    for(int i=0;i<n;++i)
    {
    	cin>>A[i];               
    }
    
	perm (A,n,b);
    
	return 0;
}
