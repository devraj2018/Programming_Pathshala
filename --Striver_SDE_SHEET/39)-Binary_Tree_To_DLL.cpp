/*************************************************************
 
    Following is the Binary Tree node structure

    class BinaryTreeNode 
    {
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

*************************************************************/
void helper(BinaryTreeNode<int>* root,BinaryTreeNode<int>*& head,BinaryTreeNode<int>* &tail)
    {
        if(root==NULL)
         return;
        
        helper(root->left,head,tail);
        
        if(head)
        {
            tail->right=root;
            root->left=tail;
            tail=tail->right;
        }
        else
         {
             head=root;
             tail=root;
         }
        
        helper(root->right,head,tail);
        
    }
BinaryTreeNode<int>* BTtoDLL(BinaryTreeNode<int>* root) {
   BinaryTreeNode<int>*head=NULL,*tail=NULL;
    helper(root,head,tail);
    return head;
}