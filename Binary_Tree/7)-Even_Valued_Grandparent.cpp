// Approach ----- O(1)Space ------//
class Solution {
public:
      void helper(TreeNode* root,TreeNode* par,TreeNode* gpar,int &ans)
       {
         if(root==NULL) return;
         
         if(gpar && gpar->val%2==0) ans+=root->val;
         
          helper(root->left,root,par,ans);
          helper(root->right,root,par,ans);
      
      }
    int sumEvenGrandparent(TreeNode* root) {
        
        int ans=0;
        helper(root,NULL,NULL,ans);
        return ans;
        
        
    }
};


// Approach 2--  O(1)Space ---- Only recursive space used
class Solution {
public:
    int ans=0;
    void sum(TreeNode* root)
    {  if(root==NULL) return;
       if(root->val%2==0)
         {  
           if(root->left && root->left->left)  ans+=root->left->left->val;
           if(root->left && root->left->right)  ans+=root->left->right->val;
           if(root->right && root->right->left)  ans+=root->right->left->val;
           if(root->right && root->right->right)  ans+=root->right->right->val;
         }
      sum(root->left);
      sum(root->right);
     }
    int sumEvenGrandparent(TreeNode* root) {
        
        sum(root);
        return ans;
        
    }
};