class Solution {
  public:
    //Function to return maximum path sum from any node in a tree.
    int ans=INT_MIN;
    
    int helper(Node* root)
    {
           if(root==NULL) return INT_MIN;
           if(root->left==NULL && root->right==NULL)
              {
                ans=max(ans,root->data);
                return root->data;
              }
           
             int lft=helper(root->left);
             int rgt=helper(root->right);
        
            if(lft!=INT_MIN && rgt!=INT_MIN)
                {
                  ans= max({ans,root->data,root->data+lft+rgt,root->data+lft,root->data+rgt});
                  return max({root->data,root->data+rgt,root->data+lft});
                }
            if(lft==INT_MIN)
              {  ans= max({ans,root->data,root->data+rgt});
                 return max(root->data,root->data+rgt);
              }
           
            ans= max({ans,root->data,root->data+lft});
            return max(root->data,root->data+lft);
      }
    
    int findMaxSum(Node* root)
       {
         helper(root);
         if(ans==INT_MIN) return 0;
         return ans;
      }
};