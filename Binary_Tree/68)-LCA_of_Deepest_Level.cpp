class Solution {
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        if(root==NULL) return NULL;
        if(root->val== p->val || root->val==q->val) return root;
        
        TreeNode* lft=lowestCommonAncestor(root->left,p,q);
        TreeNode* rgt=lowestCommonAncestor(root->right,p,q);
        
        if(lft && rgt) return root;
        if(lft==nullptr) return rgt;
        return lft;
   }
    void deepestLeaves(TreeNode* root,TreeNode *&a,TreeNode *&b,int &level_a,int &level_b,int curr_level=0)
    {
         if(root==NULL) return;
         
          if(root->left==NULL && root->right==NULL)
          {  
               if(curr_level>level_a)
               {
                    a=root; level_a=curr_level;
               }
               else if(curr_level==level_a)
               {
                   b=root;level_b=curr_level;
               }
               
          }
        deepestLeaves(root->left,a,b,level_a,level_b,curr_level+1);
        deepestLeaves(root->right,a,b,level_a,level_b,curr_level+1);
    }
    TreeNode* lcaDeepestLeaves(TreeNode* root) {
        TreeNode *a=NULL,*b=NULL;
        int level_a=-1,level_b=-1;
        deepestLeaves(root,a,b,level_a,level_b);
        
        if(level_a>level_b)  return a;  // In these case we have only one node at deepest level
                                         // Always stored in a
        return lowestCommonAncestor(root,a,b);
        
    }
};