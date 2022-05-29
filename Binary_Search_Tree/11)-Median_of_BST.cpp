int count(Node* root)
{    if(root==NULL) return 0;
      int lc=count(root->left);
      int rc=count(root->right);
      return 1+lc+rc;
    
}
void helper(Node* root,int target,bool iseven,int &curr_c,float &ans)
{    if(root==NULL) return;
     helper(root->left,target,iseven,curr_c,ans);
     curr_c++;
     
     if(iseven &&((curr_c==target) || (curr_c==target+1))) ans+= root->data;
     else if(!iseven && curr_c==target+1) ans=root->data;
     helper(root->right,target,iseven,curr_c,ans);
     
    
}
float findMedian(struct Node *root)
{    float ans=0;
     int cnt=count(root);
     bool iseven=true;
     if(cnt&1) iseven=false;
     int curr_c=0;
     helper(root,cnt/2,iseven,curr_c,ans);
     if(iseven) return ans/2;
     return ans;
}
