class Solution {
public:
    vector<int> inorderTraversal(TreeNode* root) {
         vector<int>res;
         if(root==NULL) return res;
         stack<TreeNode*>s;
         while(!s.empty() || root)
            {
                if(root==NULL)
                   {
                     root=s.top();
                     res.push_back(root->val);
                     s.pop();
                     root=root->right;
                   }
                else
                  {   s.push(root);
                      root=root->left;
                   }
          }
        return res;
     }
};