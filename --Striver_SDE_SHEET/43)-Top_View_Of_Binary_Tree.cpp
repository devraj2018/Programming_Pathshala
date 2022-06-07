/************************************************************

    Following is the TreeNode class structure:

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
vector<int> getTopView(TreeNode<int> *root) {
      vector<int>res; 
         if(root==NULL) return res;
        
        
         unordered_map<int,int>mp;
         queue<pair<TreeNode<int>*,int>>q;
         int maxx=0,minn=0;
         q.push({root,0});
        
        while(!q.empty())
        {
                 TreeNode<int>* curr=q.front().first;
                 int vd=q.front().second;
                 q.pop();
            
                 maxx=max(maxx,vd);
                 minn=min(minn,vd);
            
                 if(mp.find(vd)==mp.end()) 
                     mp[vd]=curr->val;
            
                 if(curr->left) q.push({curr->left,vd-1});
                 if(curr->right) q.push({curr->right,vd+1});
               
          
           
        }
        
        for(int i=minn;i<=maxx;i++)
        {
            res.push_back(mp[i]);
        }
        return res;
}