void leftB(TreeNode<int>* root,vector<int>&res)
{
    if(root==NULL) return;
    
    if(root->left==NULL && root->right==NULL) return;
    res.push_back(root->data);
    
    if(root->left)
        leftB(root->left,res);
    else if(root->right)
        leftB(root->right,res);
    
    
}
void rightB(TreeNode<int>* root,vector<int>&res)
{
    if(root==NULL) return;
    
    
     if(root->right)
        rightB(root->right,res);
    else if(root->left)
       rightB(root->left,res);
    
    if(root->left==NULL && root->right==NULL)
        return;
    res.push_back(root->data);
    
    
}
void leaf(TreeNode<int>* root,vector<int>&res)
{
    if(root==NULL) return;
    
    if(root->left==NULL && root->right==NULL)
       {  res.push_back(root->data);
          return;
       }
     
    
      leaf(root->left,res);
      leaf(root->right,res);
}

vector<int> traverseBoundary(TreeNode<int>* root){
   if(root==NULL) return {};
    vector<int>res;
    res.push_back(root->data);
    
    leftB(root->left,res);
    leaf(root->left,res);   // Root Exception Hatane k Liye
    leaf(root->right,res);
    rightB(root->right,res);
    return res;
   
}