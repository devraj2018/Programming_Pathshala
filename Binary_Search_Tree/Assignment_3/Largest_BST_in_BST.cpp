class data{
    public:
    int maxx;int minn;
    bool isBst;
    int size;
    data(int maxxx,int minnn,bool is,int s){
        maxx=maxxx;minn=minnn;isBst=is;size=s;
    }
};
class Solution{
    public:
    /*You are required to complete this method */
    // Return the size of the largest sub-tree which is also a BST
    data helper(Node* root,int &ans)
    { 
        if(root==NULL) return data(INT_MIN,INT_MAX,true,0);
        if(root->left==NULL && root->right==NULL) return data(root->data,root->data,true,1);
        
         data lft=helper(root->left,ans);
         data rgt=helper(root->right,ans);
         
         if( (lft.isBst && rgt.isBst) &&(lft.maxx<root->data) &&(rgt.minn>root->data))
         {
             ans= max(ans,1+lft.size+rgt.size);
             return data(max({root->data,lft.maxx,rgt.maxx}) ,min({root->data,lft.minn,rgt.minn}), true,1+lft.size+rgt.size);
             
             
         }
         return data(INT_MIN,INT_MAX,false,0);
          
          
        
    }
    int largestBst(Node *root)
    {
     if(root==NULL) return 0;
     int ans=1;
     data d=helper(root,ans);
     if(ans==0) return d.size;
     return ans;
     
    }
};