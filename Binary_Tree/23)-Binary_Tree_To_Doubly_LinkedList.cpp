class Solution
{
    public: 
    //Function to convert binary tree to doubly linked list and return it.
    void helper(Node* root,Node* &head,Node* &tail)
    {
         if(root==NULL) return;
        
         helper(root->left,head,tail);
         if(head==NULL)
         {
             head=root;
             tail=root;
         }
         else
         {
             tail->right=root;
             root->left=tail;
             tail=tail->right;
         }
         helper(root->right,head,tail);
     }
    Node * bToDLL(Node *root)
    {
         Node* head=NULL,*tail=NULL;
         helper(root,head,tail);
         return head;
    }
};