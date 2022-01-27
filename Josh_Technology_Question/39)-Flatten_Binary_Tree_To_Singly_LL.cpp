class Solution {
public:
    void flatten(TreeNode* root) {
        
         if(root)
         {
              TreeNode* temp=root->right;
              root->right=root->left;
              root->left=NULL;
             
              TreeNode* curr=root;
              while(curr->right)
              {
                  curr=curr->right;
              }
              curr->right=temp;
              flatten(root->right);
         }
        
    }
};

//  Another way where we have to return root

TreeNode* Solution::flatten(TreeNode* root) {

    if(root==NULL) return NULL;

    TreeNode* temp=root->right;
    root->right=root->left;
    root->left=NULL;

    TreeNode* curr=root;
    while(curr->right)
    {
        curr=curr->right;
    }
    curr->right=temp;
    root->right=flatten(root->right);
    return root;
 }

