class Solution {
public:
    TreeNode* par1=NULL,*par2=NULL;
    int ah=-1,bh=-1;
bool helper(TreeNode* root,int a,int b,int curr_h=0,TreeNode* par=NULL)
{
       if(root==NULL) return false;
       if(root->val==a)
       {
           ah=curr_h; par1=par;
       }
       if(root->val==b)
       {
           bh=curr_h;  par2=par;
       }
       if(ah==bh && par1!=par2) return true;
       return (helper(root->left,a,b,curr_h+1,root) ||helper(root->right,a,b,curr_h+1,root));    
}

    bool isCousins(TreeNode* root, int x, int y) {
         return helper(root,x,y);
    }
};