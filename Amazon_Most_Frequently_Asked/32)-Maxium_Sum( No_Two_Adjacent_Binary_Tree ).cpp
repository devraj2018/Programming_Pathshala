lass Solution{
  public:
   int sum=0;
    //Function to return the maximum sum of non-adjacent nodes.
    unordered_map<Node*,int>mp;
    int helper(Node* root)
    {
         if(root==NULL) return 0;
        
         if(mp.find(root)!=mp.end()) return mp[root];
        
         int take=root->data;
         int non_take=0;
         if(root->left)
            {
              take+= helper(root->left->left);
              take+= helper(root->left->right);
            }
         if(root->right)
            {
              take+= helper(root->right->left);
              take+= helper(root->right->right);
            }
            
          
          non_take+= helper(root->left) + helper(root->right);
          
          return mp[root]=max(take,non_take); 
     }
    int getMaxSum(Node *root) 
    {
         if(root==NULL) return 0;
         return helper(root);
    }
    
};