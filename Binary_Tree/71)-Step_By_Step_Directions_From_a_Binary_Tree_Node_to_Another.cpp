class Solution {
public:
    bool foundA=false,foundB=false;
    string s1="",s2="";
    string curr_path="";
     TreeNode* LCA(TreeNode* root,int a,int b)
        { 
         
         if(root==NULL) return NULL;
         
         if(root->val== a || root->val == b) return root;
       
         TreeNode* lft=LCA(root->left,a,b);
         TreeNode* rgt=LCA(root->right,a,b);
         
         if(lft&& rgt) return root;
         if(lft) return lft;
         return rgt;
     }
    void path1(TreeNode* root,int a )
     {
         if(root==NULL) return;
         if(foundA ) return;
        
         if(root->val==a) {s1=curr_path; foundA=true;}
          
         curr_path+="U";
         path1(root->left,a );
         curr_path.pop_back();
         curr_path+="U";
         path1(root->right,a);
         curr_path.pop_back();
     }
    void path2(TreeNode* root, int b )
     {
         if(root==NULL) return;
         if( foundB) return;
        
         if(root->val==b) {s2=curr_path;foundB=true;}
        
         curr_path+="L";
         path2(root->left,b);
         curr_path.pop_back();
         curr_path+="R";
         path2(root->right,b);
        curr_path.pop_back();
     }
    string getDirections(TreeNode* root, int a, int b) {
        
          TreeNode* lca=LCA(root,a,b);
          
          curr_path="";
          path1(lca,a);
          curr_path="";
          path2(lca,b);
          
          if(s1.size()==0) return s2;
          if(s2.size()==0) return s1;
        
          return s1+s2;
        
    }
};