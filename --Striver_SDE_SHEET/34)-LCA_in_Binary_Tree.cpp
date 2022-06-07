/************************************************************

    Following is the TreeNode class structure

    template <typename T>
    class TreeNode {
       public:
        T data;
        TreeNode<T> *left;
        TreeNode<T> *right;

        TreeNode(T data) {
            this->data = data;
            left = NULL;
            right = NULL;
        }
    };

************************************************************/

int lowestCommonAncestor(TreeNode<int> *root, int x, int y)
{
         if(root==NULL) return 0;
        
        if(root->data==x || root->data==y) return root->data;
        
        int lft=lowestCommonAncestor(root->left,x,y);
        int rgt=lowestCommonAncestor(root->right,x,y);
        
        if(lft&&rgt) return root->data;
        
        if(lft) return lft;
        return rgt;
}