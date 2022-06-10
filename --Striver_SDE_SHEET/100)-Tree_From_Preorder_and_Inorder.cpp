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
TreeNode<int> *helper(vector<int>&preorder,int &curr_I,unordered_map<int,int>&mp,int start,int end)
{
    if(curr_I==preorder.size()) return NULL;
    if(start>end) return NULL;
    
   TreeNode<int> *root= new TreeNode<int>(preorder[curr_I]);
   int mid=mp[preorder[curr_I]];
   curr_I++;
    
   root->left=helper(preorder,curr_I,mp,start,mid-1); 
       root->right=helper(preorder,curr_I,mp,mid+1,end);
    return root;
}
TreeNode<int> *buildBinaryTree(vector<int> &inorder, vector<int> &preorder)
{
	unordered_map<int,int>mp;
    for(int i=0;i<inorder.size();i++)
    {
        mp[inorder[i]]=i;
        
    }
    int curr_I=0;
    return helper(preorder,curr_I,mp,0,preorder.size()-1);
}