/*  Given the root of a binary tree and an integer targetSum,
return the number of paths where the sum of the values along the path equals targetSum.

The path does not need to start or end at the root or a leaf,
but it must go downwards (i.e., traveling only from parent nodes to child nodes).*/


// Its like count subarray sum==k ,and we need to consider all path array//
//Once one path is done we go to other path//

class Solution {
public:
    unordered_map<int,int>mp;
    int ans=0;
    void helper(TreeNode* root,int target,int curr_path_sum=0)
    {  if(root==NULL) return;
       
       curr_path_sum+= root->val;
     
       if(mp.find( curr_path_sum-target)!=mp.end())
             ans+= mp[curr_path_sum-target];
        mp[curr_path_sum]++;
    
         
       helper(root->left,target,curr_path_sum);
       helper(root->right,target,curr_path_sum);
       mp[curr_path_sum]--; 
        
        
        
    }
    int pathSum(TreeNode* root, int targetSum) {
        mp[0]=1;   //    Most important part like our curr_path_sum==target ,Then we need curr_path_sum-target
        helper(root,targetSum); // Inside our map that should be zero
        return ans;
        
    }
};


//------ Brute force n^2 Complexity  -------//

/*class Solution {
public:
    int ans=0;
    void sum(TreeNode* root,int target,int curr_sum=0)
    { if(root==NULL) return;
      
       curr_sum+= root->val;
       if(curr_sum==target) ans++;
       sum(root->left,target,curr_sum);
      sum(root->right,target,curr_sum);
       
        
    }
    void helper(TreeNode* root,int target)
    {
         if(root==NULL) return;
        
         helper(root->left,target);
         helper(root->right,target);
         
         sum(root,target);
        
        
    }
    int pathSum(TreeNode* root, int targetSum) {
        helper(root,targetSum);
        return ans;
    }
};*/