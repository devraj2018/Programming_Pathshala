class Solution {
public:
    TreeNode* deleteNode(TreeNode* root, int key) {
        
        if(root==NULL) return NULL;
        
        if(root->val>key) root->left= deleteNode(root->left,key);
        else if(root->val < key) root->right= deleteNode(root->right,key);
        else
        {   
             if(root->left==NULL && root->right==NULL) return NULL;
              else if(root->left && root->right)
              {  
                  
                   TreeNode* temp=root->right;
                    while(temp->left) temp=temp->left;
                   
                    root->val=temp->val;
                    
                    root->right=deleteNode(root->right,root->val);
                    return root;
                  
              }
             else if(root->left)  return root->left;
             else  return root->right;
        }
        return root;
        
    }
};