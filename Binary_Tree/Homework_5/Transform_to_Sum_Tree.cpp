class Solution {
  public:
    int helper(Node* root)
    { if(root==NULL) return 0;
    
      int lsum=helper(root->left);
      int rsum=helper(root->right);
      
      int root_val=root->data;
      root->data=lsum+rsum;
      
      return lsum+rsum+root_val;    
    }
    void toSumTree(Node *node)
    {
       helper(node);
    }
};