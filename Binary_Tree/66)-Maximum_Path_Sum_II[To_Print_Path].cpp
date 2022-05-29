class Solution {
public:
     vector<vector<int>>res;
     void storeInResult(int start_Index,vector<int>curr_path)
     {
          vector<int>temp;
          for(int i=start_Index;i<curr_path.size();i++)
           temp.push_back(curr_path[i]); 
         res.push_back(temp);

     }
     void helper(TreeNode* root,int targetSum,vector<int>&curr_path)
     {
          if(root==NULL) return;

          curr_path.push_back(root->val);
          
          helper(root->left,targetSum,curr_path);

          helper(root->right,targetSum,curr_path);
          
         int sum=0;
          for(int i=curr_path.size()-1;i>=0;i--)
          {
                sum+= curr_path[i];
                if(sum==targetSum)
                { 
                  storeInResult(i,curr_path);   
                }

          }
          

          curr_path.pop_back();


     }
    
    int pathSum(TreeNode* root, int targetSum) {
       vector<int>curr_path;
       helper(root,targetSum,curr_path) 
       return res; 

        
    }
};