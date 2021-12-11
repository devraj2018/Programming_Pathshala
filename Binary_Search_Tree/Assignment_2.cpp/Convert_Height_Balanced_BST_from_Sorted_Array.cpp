class Solution {
public:
    TreeNode* helper(vector<int>& nums,int start_I,int end_I)
    {  if(start_I >end_I)  return NULL;
       
       int mid=(start_I+end_I)/2;
       TreeNode* root=new TreeNode(nums[mid]);
       root->left=helper(nums,start_I,mid-1);
       root->right=helper(nums,mid+1,end_I);
       return root;
   }
    TreeNode* sortedArrayToBST(vector<int>& nums) {
        return helper(nums,0,nums.size()-1);
    }
};