
class Solution {
    private:
       vector<string>ans;
    public:
    void Path(TreeNode* root,string curr)
    { 
         if(root==NULL)
           return;

         curr+=to_string(root->val);
         curr+="->";
         if(root->left==NULL && root->right==NULL)
          {
             curr.pop_back();curr.pop_back();
             ans.push_back(curr);
          }
        Path(root->left,curr);
        Path(root->right,curr);
  }
    vector<string> binaryTreePaths(TreeNode* root) {
        string curr="";
        Path(root,curr);
        return ans;
     
    }
};