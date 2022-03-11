class Solution{
  public:
   
    string s1="",s2="";
    Node* LCA(Node* root,int a,int b)
    { 
         if(root==NULL) return NULL;
         
         if(root->data== a || root->data == b)
         {
             return root;
         }
         
         Node* lft=LCA(root->left,a,b);
         Node* rgt=LCA(root->right,a,b);
         
         if(lft&& rgt) return root;
         
         if(lft) return lft;
         return rgt;
     }
    void path(Node* root,int a,int b,string curr)
    {
         if(root==NULL) return;
         
         if(root->data == a) s1=curr;
         if(root->data == b) s2=curr;
        
         path(root->left,a,b,curr+"L");
         path(root->right,a,b,curr+"R");
         
     }
    int NumberOFTurns(struct Node* root, int a, int b)
    {
          Node* lca=LCA(root,a,b);
          if(lca==NULL) return -1;
          path(lca,a,b,"");

          if(s1.length()==0 && s2.length()==0)
               return -1;
          reverse(s1.begin(),s1.end());
          s1+=s2;
          int count=0;
          for(int i=0;i<s1.length()-1;i++)
          {
              if(s1[i]!=s1[i+1]) count++;
          }
          if(count==0) return -1;
          return count;

      
    }
};