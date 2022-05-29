class Solution {
public:
    unordered_map<TreeNode*,TreeNode*>parent;
    void createParent(TreeNode* root,TreeNode* par=NULL)  // Storing parent of each node
    {   if(root==NULL) return;
        parent[root]=par;
        createParent(root->left,root);
        createParent(root->right,root);
    }
    vector<int> distanceK(TreeNode* root, TreeNode* target, int k) {
        vector<int>res;
        createParent(root);
        queue<TreeNode*>q;
        q.push(target);
        unordered_set<TreeNode*>visited;
        visited.insert(target);
        while(!q.empty())
        {  if(k==0)
              {      while(!q.empty())
                      {
                       TreeNode*curr=q.front();q.pop();
                       res.push_back(curr->val);
                      }
               return res;
              }
              
         int size=q.size();
         for(int i=0;i<size;i++)
         {  
             TreeNode*curr=q.front();q.pop();
              
             if(curr->left && visited.find(curr->left)==visited.end())
             {
                 q.push(curr->left); visited.insert(curr->left);
             }
              if(curr->right && visited.find(curr->right)==visited.end())
             {
                 q.push(curr->right); visited.insert(curr->right);
             }
              if(parent[curr] && visited.find(parent[curr])==visited.end())
             {
                 q.push(parent[curr]); visited.insert(parent[curr]);
             }
         }
         k--;
         
        }
            
      return res;  
    }
};