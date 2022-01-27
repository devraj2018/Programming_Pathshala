// O(n) Time and O(1)Time 

class Solution {
public:
    void helper(TreeNode* root,int &prev_sum)
    {   if(root==NULL) return;
     
        helper(root->right,prev_sum);   //First call right
       
        prev_sum+= root->val;
        root->val=prev_sum;
     
        helper(root->left,prev_sum);   //then call left
     }
    TreeNode* bstToGst(TreeNode* root) {
        int prev_sum=0;
        helper(root,prev_sum);
        return root;
    }
};



//   O(n) Time and O(n) SPace
class Solution {
public:
    void inorder(TreeNode* root,vector<int>&v)
    {
        
         if(root==NULL) return;
         inorder(root->left,v);
         v.push_back(root->val);
         inorder(root->right,v);
        
    }
    void helper(TreeNode* root,vector<int>&v,int &curr_I)
    {
         if(root==NULL) return;
        
         helper(root->left,v,curr_I);
         root->val=v[curr_I];
         curr_I++;
         
         helper(root->right,v,curr_I);
        
        
        
    }
    TreeNode* bstToGst(TreeNode* root) {
        
        if(root==NULL ) return NULL;
        
        vector<int>v;
        inorder(root,v);
        
        for(int i=v.size()-2;i>=0;i--)
        {
            v[i]+= v[i+1];
        }
         int curr_I=0;
        
         helper(root,v,curr_I);
        return root;
        
    }
};