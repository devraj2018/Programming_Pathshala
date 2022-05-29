Node* helper(int post[],int &currI,int minn,int maxx)
{ 
    if(currI<0)
     return NULL;
     
    Node* root=NULL;
    if(minn < post[currI] && post[currI]<maxx)
    {
         root= new Node(post[currI]);
         currI--;
         root->right=helper(post,currI,root->data,maxx);
         root->left=helper(post,currI,minn,root->data);
    }
    return root;
    
     
    
}
Node *constructTree (int post[], int size)
{

       int currI=size-1;
       return helper(post,currI,INT_MIN,INT_MAX);
 

}