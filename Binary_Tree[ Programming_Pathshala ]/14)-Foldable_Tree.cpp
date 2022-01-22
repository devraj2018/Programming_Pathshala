void isSame(Node* root1,Node* root2,bool &ans)
{   
    if(root1==NULL && root2==NULL) return;
    
    if(root1==NULL || root2==NULL) {
        ans=false;
        return;
    }
    isSame(root1->left,root2->right,ans);
    isSame(root1->right,root2->left,ans);

}
bool IsFoldable(Node* root)
{
   bool ans=true;
   if(!root) return ans;
   isSame(root->left,root->right,ans);
   return ans;
   
}