/*
    Following is the Binary Tree node structure:

    class BinaryTreeNode {
    public : 
        T data;
        BinaryTreeNode<T> *left;
        BinaryTreeNode<T> *right;

        BinaryTreeNode(T data) {
            this -> data = data;
            left = NULL;
            right = NULL;
        }
    };
*/

bool searchInBST(BinaryTreeNode<int> *root, int val) {
       if(root==NULL) return false;
        
        if(root->data==val) return true;
        
        if(root->data>val)
             return searchInBST(root->left,val);
        return searchInBST(root->right,val);
}