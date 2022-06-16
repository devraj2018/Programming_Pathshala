/*************************************************************

    Following is the Binary Tree node structure

    class BinaryTreeNode
    {
    public :
        T data;
        BinaryTreeNode < T > *left;
        BinaryTreeNode < T > *right;

        BinaryTreeNode(T data) {
            this -> data = data;
            left = NULL;
            right = NULL;
        }
    };

*************************************************************/
#include<bits/stdc++.h>
void helper(BinaryTreeNode < int > * root,int &maxx)
{
    if(root==NULL) return;
    maxx=max(maxx,root->data);
    
        helper(root->left,maxx);
        helper(root->right,maxx);
}
void helper2(BinaryTreeNode < int > * root,int &maxx)
{
    if(root==NULL) return;
    
        helper2(root->left,maxx);
        helper2(root->right,maxx);
    
    if(root->left==NULL && root->right==NULL)
    {
        root->data=maxx;
        return;
    }
    
    if(root->left!=NULL && root->right!=NULL)
    {
        root->data=root->left->data+root->right->data;
    }
    else if(root->left!=NULL)
    {
        root->data=root->left->data;
    }
    else
        root->data=root->right->data;
    
    
}
void changeTree(BinaryTreeNode < int > * root) {
    int maxx=INT_MIN;
    helper(root,maxx);
    helper2(root,maxx);
    
}  