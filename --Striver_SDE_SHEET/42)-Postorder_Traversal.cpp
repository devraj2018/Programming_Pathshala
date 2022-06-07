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
vector<int> getPostOrderTraversal(TreeNode *root)
{
       vector<int>res;
    if(root==NULL) return res;
    
    while(root)
    {
         if(root->right==NULL)
         {
             res.push_back(root->data);
             root=root->left;
         }
         else{
             
             TreeNode* succ=root->right;
             while(succ->left!=NULL && succ->left!=root)
             {
                 succ=succ->left;
             }
             if(succ->left==NULL)
             {  res.push_back(root->data);
                 succ->left=root;
                 root=root->right;
             }
             else
             {
                 succ->left=NULL;
                  root=root->left;
             }
             
         }
      }
    reverse(res.begin(),res.end());
      return res;
}