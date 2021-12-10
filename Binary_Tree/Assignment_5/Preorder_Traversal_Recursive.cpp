class Solution {
public:
      void pre(TreeNode* root,vector<int> &v)
      { if(root==NULL) return;
           v.push_back(root->val);
          pre(root->left,v);
          pre(root->right,v);
     }
    vector<int> preorderTraversal(TreeNode* root) {
        vector<int> res;
        pre(root,res);
        return res;
    }
};