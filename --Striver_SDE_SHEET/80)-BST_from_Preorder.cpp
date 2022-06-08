/*************************************************************

    Following is the Binary Tree node structure

    template <typename T>

    class TreeNode{
    public:
        T data;
        TreeNode<T> *left;
        TreeNode<T> *right;

        TreeNode(T data) {
            this->data = data;
            left = NULL;
            right = NULL;
        }
        ~TreeNode() {
            if (left){
                delete left;
            }
            if (right){
                delete right;
            }
        }
    };

*************************************************************/
#include<bits/stdc++.h>
TreeNode<int>* helper(vector<int> &preOrder,int left,int right,int &curr_I)
{
    if(curr_I==preOrder.size()) return NULL;
    
    TreeNode<int>* root= NULL;
    
    if(preOrder[curr_I]>left && preOrder[curr_I]<right)
    {
        root= new TreeNode<int>(preOrder[curr_I]);
      curr_I++;
    root->left=helper(preOrder,left,root->data,curr_I);
     
    root->right=helper(preOrder,root->data,right,curr_I);
    }
    
   
    return root;
}
TreeNode<int>* preOrderTree(vector<int> &preOrder){
   
    int minn=INT_MIN;
    int maxx=INT_MAX;
    int curr_I=0;
    return helper(preOrder,minn,maxx,curr_I);
    
}