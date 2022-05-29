struct data{
     public:
     int maxx,minn,size;
     bool isBst;
    //  data(int mx,int mn,int sz,bool is)
    //  {
    //      maxx=mx;minn=mn;size=sz;isBst=is;
    //  }
    


    
};
class Solution{
    public:
    data helper(Node* root,int &ans)
    {
          if(root==NULL) return {INT_MIN,INT_MAX,0,true};
          
          if(root->left==NULL && root->right==NULL) return {root->data,root->data,1,true};
          data lft=helper(root->left,ans);
          
          data rgt=helper(root->right,ans);
          
          if((lft.isBst) &&( rgt.isBst) && (root->data>lft.maxx) &&( root->data<rgt.minn))
          {
              ans=max(ans,(1+lft.size+rgt.size));
              return {max({lft.maxx,rgt.maxx,root->data}),min({lft.minn,rgt.minn,root->data}),1+lft.size+rgt.size,true};
           }
        return {INT_MIN,INT_MAX,0,false};
        
        
        
    }
    
    int largestBst(Node *root)
    { if(root==NULL) return 0;
      int ans=1;
      helper(root,ans);
    
      return ans;
    }
};