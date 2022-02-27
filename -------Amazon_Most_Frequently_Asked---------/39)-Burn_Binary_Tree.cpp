unordered_map<TreeNode*,TreeNode*>parent;
 void buildParent(TreeNode* root,TreeNode* &target,int t,TreeNode* par=NULL)
 {
       if(root==NULL) return;

       parent[root]=par;
       if(root->val==t)
       {
           target=root;
       }
       buildParent(root->left,target,t,root);
       buildParent(root->right,target,t,root);
 }

int Solution::solve(TreeNode* A, int B) {
      TreeNode* target=NULL;
      buildParent(A,target,B);
      
      unordered_set<TreeNode*>visited;
      queue<TreeNode*>q;
      q.push(target);
      visited.insert(target);
      int ans=0;
      while(!q.empty())
      {
            int size=q.size();
            for(int i=1;i<=size;i++)
            {
                TreeNode* curr=q.front();
                 q.pop();

                if(curr->left && visited.find(curr->left)==visited.end())
                {
                    q.push(curr->left);
                    visited.insert(curr->left);
                } 
                if(curr->right && visited.find(curr->right)==visited.end())
                {
                    q.push(curr->right);
                    visited.insert(curr->right);
                } 
                if(parent[curr] && visited.find(parent[curr])==visited.end())
                {
                    q.push(parent[curr]);
                    visited.insert(parent[curr]);
                }
               

            }
             ans++;
           
  }
  return ans-1;   //   Because last iteration we are doing and we dont require that
                  // In that iteration all nodes are already burnt

 
}

------------------------------------------------------------------------------------------------------------
------------------------------------------------------------------------------------------------------------
------------------------------------------------------------------------------------------------------------




 void preorder(int B,TreeNode* root, unordered_map<TreeNode*,TreeNode*>&parent,TreeNode* par,int &count,TreeNode*& target)
 { if(root==NULL) return;

   parent[root]=par;
   count++;
 
   if(root->val==B)
   {
       target=root;
   }
   
   preorder(B,root->left,parent,root,count,target);
   
   preorder(B,root->right,parent,root,count,target);


 }
int Solution::solve(TreeNode* A, int B) {
    unordered_map<TreeNode*,TreeNode*>parent;
    int count=0;
    TreeNode* target=NULL;
    preorder(B,A,parent,NULL,count,target);
    unordered_set<TreeNode*> visited;
    int ans=0;
    queue<pair<TreeNode*,int>>q;
    q.push({target,0});
    visited.insert(target);
   

    while(!q.empty())
    {  
        TreeNode* curr=q.front().first;
        int t=q.front().second;
        ans=max(ans,t);
        q.pop();
        if(curr->left && visited.find(curr->left)==visited.end())
         {
             q.push({curr->left,t+1});
             visited.insert(curr->left);
         }
          if(curr->right && visited.find(curr->right)==visited.end())
         {
             q.push({curr->right,t+1});
             visited.insert(curr->right);
         }
          if(parent[curr] && visited.find(parent[curr])==visited.end())
         {
             q.push({parent[curr],t+1});
             visited.insert(parent[curr]);
         }
    }
    return ans;


}
