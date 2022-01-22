NODE* helper(int x,int y,NODE *root,vector<int> &vec)
{ if(root==NULL) return NULL;

   vec.push_back(root->data);
   if(root->data<x &&root->data <y)
      return helper(x,y,root->right,vec);

    if(root->data>x &&root->data >y)
     return  helper(x,y,root->left,vec);    
    return root;   
     
}
int pthCommonAncestor(int x,int y,NODE *root,int p,vector<int> &vec){
     helper(x,y,root,vec);
     if(vec.size()<p) return -1;
     
     return vec[vec.size()-p];
     
     
}