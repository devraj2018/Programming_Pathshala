void prede(Node* root,Node *&pre)
{
     if(root==NULL  ) return;
     Node* temp=root;
     while(temp->right) temp=temp->right;
     
     pre=temp;
    
}
void succe(Node* root,Node *&suc)
{
     
     if(root==NULL ) return;
      Node* temp=root ;
     while(temp->left) temp=temp->left;
     
     suc=temp;
    
}
void findPreSuc(Node* root, Node*& pre, Node*& suc, int key)
{  
      if(root==NULL) return;
      
      if(root->key==key)
      {   
           if(root->left) prede(root->left,pre);
           if(root->right) succe(root->right,suc);
           return;
      }
      if(root->key >key)
       {  suc=root;
          findPreSuc(root->left,pre,suc,key);
       }
     else
       {  pre=root;
          findPreSuc(root->right,pre,suc,key);
        }
       
}