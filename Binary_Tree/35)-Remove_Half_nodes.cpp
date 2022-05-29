 Node *RemoveHalfNodes(Node *root)
{
   if(root==NULL) return NULL;
   if(root->left==NULL && root->right==NULL) return root;
   
   if(root->left!=NULL && root->right!=NULL)
     {
         root->left=RemoveHalfNodes(root->left);
         root->right=RemoveHalfNodes(root->right);
         return root;
     }
     else if(root->left)
       return RemoveHalfNodes(root->left);
       
    return RemoveHalfNodes(root->right);
     
     
}