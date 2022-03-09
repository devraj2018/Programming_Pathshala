                         -----------------------------------------
                        | Time O((LogN)^2)  And Space is O(Log n) |
                         -----------------------------------------
class Solution {
public:
    int countNodes(TreeNode* root) {
        int lh=0,rh=0;
        TreeNode* lft=root,*rgt=root;
        while(lft)
        {   lh++;lft=lft->left;
        }
        while(rgt)
        {  
            rh++;rgt=rgt->right;
        }
        if(lh==rh)
           return (1<<(lh))-1;
       return countNodes(root->left)+countNodes(root->right)+1;
    }
};