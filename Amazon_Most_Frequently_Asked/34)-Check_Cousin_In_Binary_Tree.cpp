 
int ha,hb;
bool ans;
BinaryTreeNode<int>* para,*parb;
void helper(BinaryTreeNode<int>* root,int a,int b,int curr_h,BinaryTreeNode<int> * par)
{
    if(root==NULL || ans ) return;
    
    if(root->data==a)
       {
        ha=curr_h;
        para=par;
       }
     if(root->data==b)
       {
        hb=curr_h;
        parb=par;
      }
    if(para && parb && ha==hb && para!=parb)
      {
        ans=true;
        return;
      }
    helper(root->left,a,b,curr_h+1,root);
    helper(root->right,a,b,curr_h+1,root);
    
    
}
string areNodesCousins(BinaryTreeNode<int>* root, vector<int> arr) 
{
     ha=-1,hb=-1,para=NULL,parb=NULL;
     ans=false;
     helper(root,arr[0],arr[1],0,NULL);
     if(ans) return "YES";
      return "NO";
}