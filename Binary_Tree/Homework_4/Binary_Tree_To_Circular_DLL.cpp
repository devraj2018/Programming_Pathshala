class Solution
{
  public:
    void helper(Node* root,Node *&head,Node *&tail)
         { if(root==NULL) return;
    
           helper(root->left,head,tail);
      
           if(head==NULL)
              {
               head=root;tail=root;
              }
           else
             {
             tail->right=root;
             root->left=tail;
             tail=tail->right;
             }
      
           helper(root->right,head,tail);
         }
    Node *bTreeToCList(Node *root)
    {
        Node* head=NULL,*tail=NULL;
        helper(root,head,tail);
        
        tail->right=head;   // Dont forget to write both these condition to make it circular
        head->left=tail;   //
        return head;
    }
};