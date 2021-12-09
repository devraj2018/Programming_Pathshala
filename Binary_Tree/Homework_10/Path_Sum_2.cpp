class Solution {
    private:
     vector<vector<int>>res;
    public:
    void helper(TreeNode* root,int curr_sum, vector<int>curr_path,int &target)
    {   
            if(root==NULL) return;
           
            curr_sum+=root->val;
            curr_path.push_back(root->val);
        
            if(root->left==NULL && root->right==NULL)
            {   if(curr_sum==target)
                  res.push_back(curr_path);
                return;
            }
        
        helper(root->left,curr_sum,curr_path,target);
        helper(root->right,curr_sum,curr_path,target);
  }
    
    vector<vector<int>> pathSum(TreeNode* root, int target) {
        vector<int>curr_path;
        int curr_sum=0;
        helper(root,curr_sum,curr_path,target);
        return res;
        
    }
};