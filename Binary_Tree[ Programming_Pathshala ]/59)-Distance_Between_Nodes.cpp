int h1,h2,lh;
TreeNode<int> * LCA(TreeNode<int> *root, int node1, int node2)
{
     if(root==NULL) return NULL;
    
     if(root->val==node1 || root->val==node2)
         return root;
     TreeNode<int> *lft=LCA(root->left,node1,node2);
         TreeNode<int> *rgt=LCA(root->right,node1,node2);
    
     if(lft && rgt)
         return root;
    if(lft) return lft;
    return rgt;
    
    
}
void distance(TreeNode<int> *root, int node1, int node2,int lca,int curr_h=1)
{
      if(root==NULL) return;
      
     if(root->val==node1) h1=curr_h;
     if(root->val==node2) h2=curr_h;
     if(root->val==lca) lh=curr_h;
    
     distance(root->left,node1,node2,lca,curr_h+1);
     distance(root->right,node1,node2,lca,curr_h+1);
     
}
int findDistanceBetweenNodes(TreeNode<int> *root, int node1, int node2)
{
    h1=-1;h2=-1;lh=-1;
    TreeNode<int> * lca=LCA(root,node1,node2);
    if(lca==NULL) return -1;
    
    distance(root,node1,node2,lca->val);
    if(h1==-1 || h2==-1 || lh==-1) return -1;
    
    return h1+h2 - 2*lh;
    
}