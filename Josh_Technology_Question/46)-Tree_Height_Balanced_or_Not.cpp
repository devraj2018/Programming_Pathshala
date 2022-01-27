
int height(BinaryTreeNode<int>* root, bool &ans)
{  
     if(root==NULL) return 0;
     if(!ans) return 0;
     int lh=height(root->left,ans);
     int rh=height(root->right,ans);
    
     if(abs(lh-rh)>1)
        {
        ans=false;
        return 0;
        }
    
    return 1+max(lh,rh);
 }
bool isBalancedBT(BinaryTreeNode<int>* root) {
   bool ans=true;
   height(root,ans);
    return ans;
}