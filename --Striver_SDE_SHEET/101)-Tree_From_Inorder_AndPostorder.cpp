/************************************************************
   
   Following is the TreeNode class structure
   
   class TreeNode<T>
   { 
   public:
        T data; 
        TreeNode<T> *left;
        TreeNode<T> *right;
   
        TreeNode(T data) 
  		{ 
            this -> data = data; 
            left = NULL; 
            right = NULL; 
        }
   };
   
   
 ************************************************************/
/************************************************************

    Following is the TreeNode class structure

    template <typename T>
    class TreeNode {
       public:
        T data;
        TreeNode<T> *left;
        TreeNode<T> *right;

        TreeNode(T data) {
            this->data = data;
            left = NULL;
            right = NULL;
        }
    };

************************************************************/
#include<bits/stdc++.h>
TreeNode<int> *helper(vector<int>&postorder,int &curr_I,unordered_map<int,int>&mp,int start,int end)
{
    if(curr_I<0) return NULL;
    if(start<end) return NULL;
    
   TreeNode<int> *root= new TreeNode<int>(postorder[curr_I]);
   int mid=mp[postorder[curr_I]];
   curr_I--;
    
    
       root->right=helper(postorder,curr_I,mp,start,mid+1);
    root->left=helper(postorder,curr_I,mp,mid-1,end);
    return root;
}


TreeNode<int>* getTreeFromPostorderAndInorder(vector<int>& postOrder, vector<int>& inOrder) 
{
	 unordered_map<int,int>mp;
    for(int i=0;i<inOrder.size();i++)
    {
        mp[inOrder[i]]=i;
        
    }
    int curr_I=postOrder.size()-1;
    return helper(postOrder,curr_I,mp,postOrder.size()-1,0);
}
