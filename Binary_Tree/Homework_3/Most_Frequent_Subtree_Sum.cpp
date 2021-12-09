class Solution {
public:
    int maxx=0;
    unordered_map<int,int>mp;
    int subtreeSum(TreeNode* root)
       {  
          if(root==NULL) return 0;
          int lsum=subtreeSum(root->left);
          int rsum=subtreeSum(root->right);
        
          int sum=lsum+rsum+root->val;
          mp[sum]++;
          maxx=max(maxx,mp[sum]);
          return sum;
        }
    vector<int> findFrequentTreeSum(TreeNode* root) {
        vector<int>res;
        subtreeSum(root);
        for(auto x:mp)
        {  if(x.second==maxx)  res.push_back(x.first);
            
        }
        return res;
        
    }
};