class Solution {
public:
    void preorder(TreeNode* root,vector<int>&res)
    {
        if(root==NULL){ 
            res.push_back(INT_MAX);
            return;
        }
        
        res.push_back(root->val);
        preorder(root->left,res);
        preorder(root->right,res);
    }
    bool isSubtree(TreeNode* root, TreeNode* subRoot) {
      
     vector<int>arr,subarr;
     preorder(root,arr);
     preorder(subRoot,subarr);
        
     int n=arr.size();
     int m=subarr.size(); 
        
     if(n<m) return false;
        
     int i=0;
     while(i<=(n-m))
     {
          int j=0;
          while(j<m && arr[i+j]==subarr[j]) j++;
          i++;
          if(j==m) return true;
      }
     return false;
        
    }
};