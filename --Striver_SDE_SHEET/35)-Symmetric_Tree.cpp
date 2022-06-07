/*****************************************************

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
        
        ~BinaryTreeNode() {
            if(left) 
                delete left;
            if(right) 
                delete right;
        }
    };

******************************************************/

bool same(BinaryTreeNode<int>* root1,BinaryTreeNode<int>* root2)
{
    if(root1==NULL && root2==NULL) return true;
        if(root1==NULL || root2==NULL) return false;
     if(root1->data!=root2->data) return false;
    
    return same(root1->left,root2->right) && same(root1->right,root2->left) ;
}
bool isSymmetric(BinaryTreeNode<int>* root)
{
    if(root==NULL ||(root->left==NULL && root->right==NULL)) return true;
    
    return same(root->left,root->right);
    
    
    
    
}