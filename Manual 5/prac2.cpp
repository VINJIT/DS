#include<iostream>
using namespace std;

class bstnode
{
	public:
	int data;
	bstnode *left;
	bstnode *right;
	bstnode(int n=0,bstnode *a=0, bstnode *b=0)
	{
		data=n;
		left=a;
		right=b;
	}
};

class bst
{
	public:
	bstnode *root;
	bst()
	{
		root=0;
	}
	
	void insertion(int x)
	{
		bstnode *p, *q, *prev;
		p=new bstnode(x);
		if(root==0)
		{
			root=p;
		}
		else
		{
			q=root;
			while(q!=0)
			{
				prev=q;
				if(q->data>x)
					q=q->left;
				else
					q=q->right;
			}
			if(x>prev->data)
				prev->right=p;
			else
				prev->left=p;
		}
	}
		void postorder(bstnode *p)
		{
			if(p==0)
				return;
			else
			{
				postorder(p->left);
				postorder(p->right);
				cout<<" "<<p->data;
			}
		}
		
		void preorder(bstnode *p)
		{
			if(p==0)
				return;
			else
			{
				cout<<" "<<p->data;
				preorder(p->left);
				preorder(p->right);				
			}
		}

		void inorder(bstnode *p)
		{
			if(p==0)
				return;
			else
			{
				inorder(p->left);
				cout<<" "<<p->data;
				inorder(p->right);				
			}
		}

	
};

int main()
{
	bst ob;
	
	int x, choice, y;
	char ch;
	cout<<".......................................INSERT A BINARY SEARCH TREE........................................\n";
	cout<<"\n\n-->NOTE :- Enter -1 to STOP insertion!\n"<<endl;
	do{
	  cout<<"Enter the element you wish to insert : ";
	  cin>>x;
	  cout<<endl;
	  if(x!=-1)
		ob.insertion(x);						
	}while(x!=-1);
	
	cout<<"The preorder traversal (recursive) of the given tree is: ";
	ob.preorder(ob.root);
					
	cout<<"The inorder traversal (recursive) of the given tree is: ";
	ob.inorder(ob.root);
	
	cout<<"The post traversal (recursive) of the given tree is: ";
	ob.postorder(ob.root);
}
