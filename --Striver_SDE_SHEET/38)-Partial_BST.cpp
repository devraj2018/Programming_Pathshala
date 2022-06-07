bool helper(BinaryTreeNode<int> *root,int left,int right)
{
     if(root==NULL) return true;
    
     if(root->data<left || root->data>right) return false;
    
    return helper(root->left,left,root->data) &&helper(root->right,root->data,right);
    
    
}
bool validateBST(BinaryTreeNode<int> *root) {
  
    return helper(root,INT_MIN,INT_MAX);
    
}