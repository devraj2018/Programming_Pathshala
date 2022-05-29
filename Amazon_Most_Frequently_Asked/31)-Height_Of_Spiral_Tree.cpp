bool isLeaf(Node* root)
{
    if(root->left && root->left->right==root ) return true;
    if(root->right && root->right->left==root ) return true;
    return false;
   
}

int findTreeHeight(Node* root)
{
      if(root==NULL) return 0;
	if(isLeaf(root)) return 1;
	
	int lh= findTreeHeight(root->left);
	int rh= findTreeHeight(root->right);
	
	return 1+max(lh,rh);
	
}