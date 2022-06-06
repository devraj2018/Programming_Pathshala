
class Solution {
public:
    Node* connect(Node* root) {
        
        if(root==NULL) return NULL;
        
        if(root->right)   root->left->next=root->right;
      
        if(root->next && root->next->left)  root->right->next=root->next->left;
        
        root->left=connect(root->left);
        root->right=connect(root->right);
        return root;
     }
};