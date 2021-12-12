class Info{
    public:
    int maxx;  int minn;  bool isBst; int sum;
    Info(int maxx_x,int minn_n,bool isBst_t,int sum_m)
    {
        maxx=maxx_x; minn=minn_n; isBst=isBst_t; sum=sum_m;
    }
};
class Solution {
public:
    int ans=0;
    Info helper(TreeNode* root)
    {  
         if(root==NULL) return Info(INT_MIN,INT_MAX,true,0);
        
         Info lft=helper(root->left);
         Info rgt=helper(root->right);
        
         if((lft.isBst && rgt.isBst) && (lft.maxx<root->val) && (root->val < rgt.minn) )
         {
                ans=max(ans,root->val+lft.sum+rgt.sum);
                int newmax=max({root->val,lft.maxx,rgt.maxx});
                int newmin=min({root->val,lft.minn,rgt.minn});
                int newsum=root->val +lft.sum+rgt.sum;
          
                return Info(newmax,newmin,true,newsum);
         }
         return Info(INT_MIN,INT_MAX,false,0);
       
    }
    int maxSumBST(TreeNode* root) {
        
        helper(root);
        return ans;
        
    }
};