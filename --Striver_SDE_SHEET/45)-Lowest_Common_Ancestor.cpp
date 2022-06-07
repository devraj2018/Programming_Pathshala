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
TreeNode<int>* lowestCommonA(TreeNode<int>* root, int x, int y) {
       
        if(root==NULL) return NULL;
        
        if(root->data==x || root->data==y) return root;
        
        TreeNode<int>* lft=lowestCommonA(root->left,x,y);
        TreeNode<int>* rgt=lowestCommonA(root->right,x,y);
        
        if(lft&&rgt) return root;
        
        if(lft) return lft;
        return rgt;
    }
int lowestCommonAncestor(TreeNode<int> *root, int x, int y)
{
         if(root==NULL) return 0;
         TreeNode<int>*lca=lowestCommonA(root,x,y);
        return lca->data;
}