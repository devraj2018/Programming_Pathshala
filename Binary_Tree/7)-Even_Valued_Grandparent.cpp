// Approach ----- O(n)Space ------Using unordered map to store parent of every node//
class Solution {
public:
    int ans=0;
    unordered_map<TreeNode*,TreeNode*>parent;
    void find_parent(TreeNode* root,TreeNode* par=NULL)
    { 
        if(root==NULL) return;
         
        parent[root]=par;
        find_parent(root->left,root);
        find_parent(root->right,root);
     }
        
    void sum(TreeNode* root)
      {   
         if(root==NULL) return;
        
         if( parent[root] && parent[parent[root]] && parent[parent[root]]->val%2==0)  ans+=root->val;
          sum(root->left);
          sum(root->right);
     }
    int sumEvenGrandparent(TreeNode* root) {
        find_parent(root);
        sum(root);
        return ans;
   }
};
// Approach 2--  O(1)Space ---- Only recursive space used
class Solution {
public:
    int ans=0;
    void sum(TreeNode* root)
    {  if(root==NULL) return;
       if(root->val%2==0)
         {  
           if(root->left && root->left->left)  ans+=root->left->left->val;
           if(root->left && root->left->right)  ans+=root->left->right->val;
           if(root->right && root->right->left)  ans+=root->right->left->val;
           if(root->right && root->right->right)  ans+=root->right->right->val;
         }
      sum(root->left);
      sum(root->right);
     }
    int sumEvenGrandparent(TreeNode* root) {
        
        sum(root);
        return ans;
        
    }
};