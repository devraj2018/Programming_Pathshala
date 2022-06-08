#include<bits/stdc++.h>
void helper(BinaryTreeNode<int>* root, int &k,int &ans,unordered_map<int,int>&mp) 
{
    if(root==NULL) return;
    
     helper(root->left,k,ans,mp);
    
     if(mp.find(k-root->data)!=mp.end()) ans=true;
    
    mp[root->data]++;
     
     
    helper(root->right,k,ans,mp);
    
}
bool pairSumBst(BinaryTreeNode<int> *root, int k)
{ unordered_map<int,int>mp;
   int ans=false;
   helper(root,k,ans,mp);
    return ans;
}