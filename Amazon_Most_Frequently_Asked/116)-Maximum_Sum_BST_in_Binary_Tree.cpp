
class Solution {
    struct data{
        int sum,maxx,minn;
        bool isBst;
    };
public:
    data helper(TreeNode* root,int &ans)
    {
         if(root==NULL) return {0,INT_MIN,INT_MAX,true};
        
         if(root->left==NULL && root->right==NULL) {
             ans=max(ans,root->val);
             return {root->val,root->val,root->val,true};
         }
        
        data lft=helper(root->left,ans);
        data rgt=helper(root->right,ans);
        
        if(lft.isBst && rgt.isBst && lft.maxx< root->val && root->val <rgt.minn)
           {
             int sum=root->val+lft.sum+rgt.sum;
              ans=max(ans,sum);
              return {sum,max({root->val,lft.maxx,rgt.maxx}),min({root->val,lft.minn,rgt.minn}),true};
           }
         return {0,INT_MIN,INT_MAX,false};
       
    }
    int maxSumBST(TreeNode* root) {
        
        if(root==NULL) return 0;
        int ans=0;
        helper(root,ans);
        return  ans;
        
    }
};