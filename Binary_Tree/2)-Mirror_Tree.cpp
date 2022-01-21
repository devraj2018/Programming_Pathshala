class Solution {
  public:
    // Function to convert a binary tree into its mirror tree.
    void mirror(Node* root) {
       if(root==NULL) return;
       
        Node* temp=root->left;
        root->left=root->right;
        root->right=temp;
        
        mirror(root->left);
        mirror(root->right);
       
    }
};