class Solution{
  public:
    /*You are required to complete below method */
    int evalTree(node* root) {
       
       if(root->left==NULL && root->right==NULL )
       {
           return stoi(root->data);
           
       }
       int lft=evalTree(root->left);
       int rgt=evalTree(root->right);
       
       if(root->data=="+")  return lft+rgt;
       else if(root->data=="*")   return lft*rgt;
       else if(root->data=="-") return lft-rgt;
        return lft/rgt;
       
    }
};