
class Solution {   // Not returning anything
public:
    void flatten(TreeNode* root) {
     
         if(root==NULL) return;
        
         TreeNode* temp=root->right;
         root->right=root->left;
         root->left=NULL;
        
         TreeNode* predecessor=root;
         while(predecessor->right!=NULL)
         {
             predecessor=predecessor->right;
             
         }
        predecessor->right=temp;
        root=root->right;
        flatten(root);
        
       
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