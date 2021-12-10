#include <iostream>
using namespace std;

void inorder(Node* root,int k1,int k2)
{
	 if(root==NULL) return;
	 
	 if(root->data>k2) inorder(root->left,k1,k2);
     else  if(root->data<k1) inorder(root->right,k1,k2);
	 else
	    {  	inorder(root->left,k1,k2);
	 	     cout<<root->data<<" ";
	 		inorder(root->right,k1,k2);
	    }
}
