
#include<bits/stdc++.h>
vector<int> getInOrderTraversal(BinaryTreeNode<int> *root)
{
    vector<int>res;
    if(root==NULL) return res;
    
    while(root)
    {
         if(root->left==NULL)
         {
             res.push_back(root->data);
             root=root->right;
         }
         else{
             
             BinaryTreeNode<int>* pred=root->left;
             while(pred->right!=NULL && pred->right!=root)
             {
                 pred=pred->right;
             }
             if(pred->right==NULL)
             {
                 pred->right=root;
                 root=root->left;
             }
             else
             {
                 pred->right=NULL;
                 res.push_back(root->data);
                 root=root->right;
             }
             
         }
      }
      return res;
}
vector<int> getPreOrderTraversal(BinaryTreeNode<int> *root)
{
     vector<int>res;
    if(root==NULL) return res;
    
    while(root)
    {
         if(root->left==NULL)
         {
             res.push_back(root->data);
             root=root->right;
         }
         else{
             
             BinaryTreeNode<int>* pred=root->left;
             while(pred->right!=NULL && pred->right!=root)
             {
                 pred=pred->right;
             }
             if(pred->right==NULL)
             {  res.push_back(root->data);
                 pred->right=root;
                 root=root->left;
             }
             else
             {
                 pred->right=NULL;
                  root=root->right;
             }
             
         }
      }
      return res;
}
vector<int> getPostOrderTraversal(BinaryTreeNode<int> *root)
{
       vector<int>res;
    if(root==NULL) return res;
    
    while(root)
    {
         if(root->right==NULL)
         {
             res.push_back(root->data);
             root=root->left;
         }
         else{
             
             BinaryTreeNode<int>* succ=root->right;
             while(succ->left!=NULL && succ->left!=root)
             {
                 succ=succ->left;
             }
             if(succ->left==NULL)
             {  res.push_back(root->data);
                 succ->left=root;
                 root=root->right;
             }
             else
             {
                 succ->left=NULL;
                  root=root->left;
             }
             
         }
      }
    reverse(res.begin(),res.end());
      return res;
}
vector<vector<int>> getTreeTraversal(BinaryTreeNode<int> *root){
    vector<vector<int>>res;
    vector<int>inorder=getInOrderTraversal(root);
        vector<int>preorder=getPreOrderTraversal(root);
        vector<int>postorder=getPostOrderTraversal(root);
        res.push_back(inorder);
        res.push_back(preorder);
        res.push_back(postorder);
       return res;
}