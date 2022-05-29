class Solution {
public:
    int ans=0;
    void count(TreeNode* root,int maxx=INT_MIN)
    {  if(root==NULL) return;
        
       if(root->val>=maxx)
           ans++;
       maxx=max(maxx,root->val);
       count(root->left,maxx);
       count(root->right,maxx);
    }
    
    
    int goodNodes(TreeNode* root) {
        count(root);
        return ans;
        
    }
};