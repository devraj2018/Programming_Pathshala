class Solution {           // If we don't need to return anything
public:
    void flatten(TreeNode* root) {   
        
        if(root)
        {
             TreeNode* curr=root,*stored_rgt_child=root->right;
             root->right=root->left;
             root->left=NULL;
             
             while(curr->right)
                 curr=curr->right;
            
             curr->right=stored_rgt_child;
             flatten(root->right);
       }
      }
};

class Solution {           // If we need to return root
public:
    TreeNode* flatten(TreeNode* root) {   
          if(root==NULL) return NULL;
        
           TreeNode* curr=root,*stored_rgt_child=root->right;
           root->right=root->left;
           root->left=NULL;
           while(curr->right)
             curr=curr->right;
            
            curr->right=stored_rgt_child;
            root->right=flatten(root->right);
            return root;  // This part is important, Most of the times I missed returning root
    
      }
};