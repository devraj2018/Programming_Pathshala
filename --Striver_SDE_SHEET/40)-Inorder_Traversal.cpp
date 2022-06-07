/*
    Following is Binary Tree Node structure:
    class TreeNode
    {
    public:
        int data;
        TreeNode *left, *right;
        TreeNode() : data(0), left(NULL), right(NULL) {}
        TreeNode(int x) : data(x), left(NULL), right(NULL) {}
        TreeNode(int x, TreeNode *left, TreeNode *right) : data(x), left(left), right(right) {}
    };
*/
vector<int> getInOrderTraversal(TreeNode *root)
{
    vector<int>res;
    if(root==NULL) return res;
    
    while(root)
    {
         if(root->left==NULL)
         {
             res.push_back(root->data);
             root=root->right;
         }
         else{
             
             TreeNode* pred=root->left;
             while(pred->right!=NULL && pred->right!=root)
             {
                 pred=pred->right;
             }
             if(pred->right==NULL)
             {
                 pred->right=root;
                 root=root->left;
             }
             else
             {
                 pred->right=NULL;
                 res.push_back(root->data);
                 root=root->right;
             }
             
         }
      }
      return res;
}