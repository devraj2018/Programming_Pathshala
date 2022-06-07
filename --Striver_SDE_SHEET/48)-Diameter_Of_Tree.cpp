 int height(TreeNode<int> * root,int &d)
    {
        if(root==NULL) return 0;
        
        int lh=height(root->left,d);
        int rh=height(root->right,d);
        
        d=max(d,lh+rh);
        return 1+max(lh,rh);
        
        
        
    }
int diameterOfBinaryTree(TreeNode<int> *root)
{
	int d=0;
    height(root,d);
    return d;
}
