TreeNode<int> *flattenBinaryTree(TreeNode<int> *root)
{
     if(root==NULL) return NULL;
    
     TreeNode<int>* temp=root->right;
    root->right=root->left;
    root->left=NULL;
    
    TreeNode<int>* pred=root;
    while(pred->right)
    {
        pred=pred->right;
    }    
     pred->right=temp;
    root->right=flattenBinaryTree(root->right);
    return root;
    
}