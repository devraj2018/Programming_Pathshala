/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
     int la=-1,lb=-1;
     string ans="";
     void levelHelper(TreeNode* root,int a,int b,int level=0)
     {
         if(!root) return;
         
         if(root->val==a){
             la=level;
         }
         if(root->val==b){
             lb=level;
         }
         levelHelper(root->left,a,b,level+1);
         levelHelper(root->right,a,b,level+1);
         
     }
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
    void path(TreeNode* root,int b,string &curr_path)
    {
        if(root==NULL) return;
        
        if(root->val==b)
        {
            ans+=curr_path;
        }
        
        curr_path+="L";
        path(root->left,b,curr_path);
        curr_path.pop_back();
        
         curr_path+="R";
        path(root->right,b,curr_path);
        curr_path.pop_back();
    }
    
     string getDirections(TreeNode* root, int startValue, int destValue) {
        TreeNode* lca=LCA(root,startValue,destValue);
         levelHelper(lca,startValue,destValue);
                 
         for(int i=0;i<la;i++)
                 ans+="U";
         string curr="";
         path(lca,destValue,curr);
         return ans;
        
    }
};