

 TreeNode<int>* helper(vector<int>&nums,int s,int e)
    {
         if(s>e) return NULL;
        
          int mid=s+(e-s)/2;
          TreeNode<int>* root=new TreeNode<int>(nums[mid]);
        
          root->left=helper(nums,s,mid-1);
         root->right=helper(nums,mid+1,e);
        return root;
        
        
        
        
    }
TreeNode<int>* sortedArrToBST(vector<int> &arr, int n)
{
    return helper(arr,0,n-1);
}