class Solution {
public:
    int height(TreeNode* root,bool &ans)
    {  if(root==NULL) return 0;
     
       int lh=height(root->left,ans);
       int rh=height(root->right,ans);
     
      if(abs(lh-rh)>1)
        { ans=false;
          return 0;
        }
     return 1+max(lh,rh);
     
        
    }
    bool isBalanced(TreeNode* root) {
        bool ans=true;
        height(root,ans);
        return ans;
        
    }
};