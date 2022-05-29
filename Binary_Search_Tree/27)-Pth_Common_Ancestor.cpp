NODE* helper(int p,int q,NODE* root,vector<int>&arr)
{
    
     if(root==NULL) return NULL;
     
     arr.push_back(root->data);
     
     if(root->data>p && root->data>q) return helper(p,q,root->left,arr);
     else if(root->data<p && root->data<q) return helper(p,q,root->right,arr);
     return root;
     
    
    
}
int pthCommonAncestor(int x,int y,NODE *root,int p,vector<int> &vec){
    
    vector<int>ancestor;
    
    helper(x,y,root,ancestor);
    
    if(p>ancestor.size()) return -1;
    
    return ancestor[ancestor.size()-p];
    
    
    
    
}