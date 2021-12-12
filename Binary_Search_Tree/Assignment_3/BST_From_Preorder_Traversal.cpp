class Solution {
public:
    unordered_map<int,int>mp;
    TreeNode* helper(vector<int>&preorder,int &curr_I,int start,int end)
    {
         if(start>end) return NULL;
        
         int mid=mp[preorder[curr_I]];
        
         TreeNode* newroot=new TreeNode(preorder[curr_I]);
         curr_I++;
        
         newroot->left=helper(preorder,curr_I,start,mid-1);
         newroot->right=helper(preorder,curr_I,mid+1,end);
        
        return newroot;
        
        
    }
    TreeNode* bstFromPreorder(vector<int>& preorder) {
      
        vector<int> pre=preorder;
        sort(preorder.begin(),preorder.end());
        int curr_I=0;
        for(int i=0;i<preorder.size();i++)
            mp[preorder[i]]=i;
        
        return helper(pre,curr_I,0,preorder.size()-1);
        
        
    }
};