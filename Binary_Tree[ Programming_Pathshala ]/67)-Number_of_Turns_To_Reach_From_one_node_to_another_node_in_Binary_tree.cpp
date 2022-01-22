class Solution{
  public:
     string s1,s2;     // To store path l and r format
     int ans=0;
     Node* lowestCommonAncestor(Node* root,int a,int b) {    //Its LCA
        if(root==NULL) return NULL;
        if(root->data== a || root->data==b) return root;
        
        Node* lft=lowestCommonAncestor(root->left,a,b);
        Node* rgt=lowestCommonAncestor(root->right,a,b);
        
        if(lft && rgt) return root;
        if(lft==NULL) return rgt;
        return lft;
     }
    void path(Node* root,int a,int b,string curr="") // Store Path from LCA to first and LCA to second
    { if(root==NULL) return;
      if(root->data== a)s1=curr;
      if(root->data== b) s2=curr;
      path(root->left,a,b,curr+"l");
      path(root->right,a,b,curr+"r");
    }
   int NumberOFTurns(Node* root, int first, int second)
      { int count=0;
        Node* lca=lowestCommonAncestor(root,first,second);
      
        if(lca==NULL) return -1;
        path(lca,first,second);
        if(s1.length()==-1 && s2.length()==-1) return -1;
      
        reverse(s1.begin(),s1.end());  //Reverse path of first BCZ we have to go from first->LCA->second
        s1=s1+s2;                  // and in s1 we have stored path from LCA to first so reverse it
                                  // Then concatenate both these so we can traverse from first to second
      for(int i=0;i<(s1.length()-1);i++)
      { 
           if(s1[i]!=s1[i+1])          // If two adjacent char(l or r) are different means we took turn;
             count++;
      }
      if(count==0) return -1;
      return count;
  
    }
};