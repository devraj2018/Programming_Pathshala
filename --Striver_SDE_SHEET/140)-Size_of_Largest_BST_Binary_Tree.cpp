/************************************************************

    Following is the Binary Tree node structure
    
    template <typename T>
    class TreeNode {
        public :
        T data;
        TreeNode<T> *left;
        TreeNode<T> *right;

        TreeNode(T data) {
            this -> data = data;
            left = NULL;
            right = NULL;
        }

        ~TreeNode() {
            if(left)
                delete left;
            if(right)
                delete right;
        }
    };

************************************************************/
#include<bits/stdc++.h>
struct node{
	int size;
	int maxx,minn;
	bool bst;
	
};

node helper(TreeNode<int>* root,int &size)
{
	 if(root==NULL) return {0,INT_MIN,INT_MAX,true};
	 
	 if(root->left==NULL && root->right==NULL) 
     {   size=max(size,1);
         return {1,root->data,root->data,true};
     }
	
	 node lft= helper(root->left,size);
		 node rgt= helper(root->right,size);
	
	  if( lft.bst && rgt.bst && lft.maxx<root->data && rgt.minn>root->data)
	  {
		  size=max(size,1+lft.size+rgt.size);
		  return {1+lft.size+rgt.size,max({root->data,rgt.maxx,lft.maxx}),min({root->data,rgt.minn,lft.minn}),true};
	 }
	  return {0,INT_MIN,INT_MAX,false};
 
	
}
int largestBST(TreeNode<int>* root) 
{
	int size=INT_MIN;
    node res=helper(root,size);
    
    if(size==INT_MIN) return res.size;
	return size;
}
