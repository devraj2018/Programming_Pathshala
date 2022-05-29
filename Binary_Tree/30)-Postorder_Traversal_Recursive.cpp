class Solution {
public:
     void post(TreeNode* root,vector<int>& v)
    {  if(root==NULL) return;
       post(root->left,v);
       post(root->right,v);
       v.push_back(root->val);
    }
    vector<int> postorderTraversal(TreeNode* root) {
        vector<int> v;
        post(root,v);
        return v;
        
    }
};