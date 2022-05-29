
class BSTIterator {
public:
    vector<int>res;
    int curr_I=0;
     void helper(TreeNode* root)
     {
         if(root==NULL) return;
         helper(root->left);
         res.push_back(root->val);
         helper(root->right);
     }
     BSTIterator(TreeNode* root) {
        helper(root);
    }
     int next() {
         int ans=res[curr_I];
         curr_I++;
         return ans;
    }
     bool hasNext() {
         if(curr_I<res.size()) return true;
        return false;
   }
};

