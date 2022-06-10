void pred(BinaryTreeNode<int>* root,int key,int &ans)
{
    if(root==NULL)
        return;
    if(root->data<key)
    {
        ans=root->data;
        return pred(root->right,key,ans);
    }
    return pred(root->left,key,ans);
}
void succ(BinaryTreeNode<int>* root,int key,int &ans)
{
    if(root==NULL)
        return;
    if(root->data>key)
    {
        ans=root->data;
        return succ(root->left,key,ans);
    }
    return succ(root->right,key,ans);
}
pair<int,int> predecessorSuccessor(BinaryTreeNode<int>* root, int key)
{
    // Write your code here.
    int ans1=-1;
    int ans2=INT_MAX;
    pred(root,key,ans1);
    succ(root,key,ans2);
    if(ans2==INT_MAX)
        ans2=-1;
    return {ans1,ans2};

}