bool isLeaf(Node* root)
{
     if((root->left && root->left->right==root) )
      return true;
      if(root->right && root->right->left==root)
      return true;    
      return false;
    
}
int findTreeHeight(Node* root)
{
      if(root==NULL) return 0;
       
       if(isLeaf(root))
        return 1;
        
        return 1+max(findTreeHeight(root->left),findTreeHeight(root->right));    
   
   
}