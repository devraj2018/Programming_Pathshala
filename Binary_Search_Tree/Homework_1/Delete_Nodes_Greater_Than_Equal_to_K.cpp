class Solution{
  public:
    /*The function should return the root of the modified tree*/
    Node* deleteNode(Node* root, int k)
    {
         if(root==NULL) return NULL;
         
         if(root->data < k) root->right=deleteNode(root->right,k);
          else {
               Node *temp=root;
               while(temp && temp->data >=k) temp=temp->left;
               if(temp==NULL) return NULL;
                else
                  {
                  root=temp;
                  root->right=deleteNode(root->right,k);
                  }
              }
          return root;
    }
};