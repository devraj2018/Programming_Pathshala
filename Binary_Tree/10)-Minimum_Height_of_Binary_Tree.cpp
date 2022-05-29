

class Solution {         // Approach 2
public:
     int minDepth(TreeNode* root) {
         if(root==NULL) return 0;
        
         int lh=minDepth(root->left);
         int rh=minDepth(root->right);
        
          
        if(root && root->left && root->right)
             return 1+min(lh,rh);
        
        if(root&& root->left)
            return 1+lh;
        
        return 1+rh;
       
    }
};

class Solution {
public:
    int ans=INT_MAX;
    void Depth(TreeNode* root,int h=1) // Approach 1
    {
         if(root==NULL) return;
        
         if(!root->left && !root->right) 
           ans=min(ans,h);
          Depth(root->left,h+1);
        Depth(root->right,h+1);
        
    }
    int minDepth(TreeNode* root) {
        Depth(root);
        if(ans==INT_MAX)
            return 0;
        return ans;
       
    }
};