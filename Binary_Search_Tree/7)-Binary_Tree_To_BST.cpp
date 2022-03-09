class Solution{
  public:
   
    void retrieve(Node* root,vector<int>&v)
    {   if(root==NULL) return;
          v.push_back(root->data);
          retrieve(root->left,v);
          retrieve(root->right,v);
       
    }
    void Inorder(Node * root,vector<int> &v,int &curr)
    {     if(root==NULL) return;
          Inorder(root->left,v,curr);
          root->data=v[curr];
          curr++;
          Inorder(root->right,v,curr);
     }
    Node *binaryTreeToBST (Node *root)
    { if(root==NULL)   return NULL;
      vector<int> v;
      retrieve(root,v);
      int curr=0;
      sort(v.begin(),v.end());
      Inorder(root,v,curr);
      return root;
    }
};