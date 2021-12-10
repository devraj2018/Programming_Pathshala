#include<bits/stdc++.>
using namespace std;

int getHeight(TreeNode* root)
{
      int height=0;
      while(root)
      {
          height++;
          root=root->left;
      }
      return height;
}
int countTotalNodes(TreeNode* root)
{   if(root==NULL) return 0;
    int height=getHeight(root);

    int nodes_except_last_level= (1<<(height-1))-1;  // (2^(h-1))-1

    int max_leaves_count= 




}