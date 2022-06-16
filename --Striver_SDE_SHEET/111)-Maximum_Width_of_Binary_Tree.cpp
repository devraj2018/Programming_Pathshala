/************************************************************

    Following is the TreeNode class structure

    template <typename T>
    class TreeNode {
       public:
        T val;
        TreeNode<T> *left;
        TreeNode<T> *right;

        TreeNode(T val) {
            this->val = val;
            left = NULL;
            right = NULL;
        }
    };

************************************************************/
#include<bits/stdc++.h>
int getMaxWidth(TreeNode<int> *root)
{
 
        if(root==NULL) return 0;
        
        queue<TreeNode<int>*>q;
        q.push(root);
        int maxx=0;
        while(!q.empty())
        {    
            int size=q.size();
            maxx=max(maxx,size);
            for(int i=0;i<size;i++)
            {   TreeNode<int>* curr=q.front();
                q.pop();
               
                
               if(curr->left) q.push(curr->left);
               if(curr->right) q.push(curr->right);
                 
             }
          
             
        }
        return maxx;
        
}