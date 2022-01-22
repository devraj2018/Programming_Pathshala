Node* helper(int pre[],int &currI,int minn,int maxx,int size)
    {      if(currI>= size)
               return NULL;
            struct Node* newroot=NULL; 
           if(minn< pre[currI] && pre[currI]<maxx)
           {
               newroot=newNode(pre[currI]);
               
               currI++;
               newroot->left=helper(pre,currI,minn,newroot->data,size);
               newroot->right=helper(pre,currI,newroot->data,maxx,size);
         
           }
       return newroot;
           
  }
Node* post_order(int pre[], int size)
{
    
    int currI=0;
    return helper(pre,currI,INT_MIN,INT_MAX,size);
}