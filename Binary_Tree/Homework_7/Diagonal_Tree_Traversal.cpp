/**
 * Definition for binary tree
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
void inorder(TreeNode* root,map<int,vector<int>>&mp,int d)
{ if(root==NULL)
    return;
   mp[d].push_back(root->val);
   inorder(root->left,mp,d+1);
   inorder(root->right,mp,d); 

}
vector<int> Solution::solve(TreeNode* A) {
    map<int,vector<int>> mp;
    vector<int> res;
    inorder(A,mp,0);
    for(auto x:mp)
    { for(auto y:x.second)
        { res.push_back(y);
        }
     }
    return res;
}