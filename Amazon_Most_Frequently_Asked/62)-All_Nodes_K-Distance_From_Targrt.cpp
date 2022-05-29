class Solution {
public:
    unordered_map<TreeNode*,TreeNode*>parent;
    
    void buildPar(TreeNode* root,TreeNode* par)
    {    if(root==NULL) return;
          parent[root]=par;
         buildPar(root->left,root);
         buildPar(root->right,root);
     }
        
    vector<int> distanceK(TreeNode* root, TreeNode* target, int k) {
        
        vector<int>res;
        buildPar(root,NULL);
        queue<TreeNode*>q;
        q.push(target);
        unordered_set<TreeNode*>visited;
        visited.insert(target);
        while(!q.empty())
        {    int size=q.size();
             for(int i=0;i<size;i++)
               {
                   TreeNode* curr=q.front();
                   q.pop();
                
                  if(k==0) res.push_back(curr->val);
                
                  if(curr->left && visited.find(curr->left)==visited.end())
                    {
                      visited.insert(curr->left);
                      q.push(curr->left);
                    }
                  if(curr->right && visited.find(curr->right)==visited.end())
                    {
                      visited.insert(curr->right);
                      q.push(curr->right);
                   }
                  if(parent[curr] && visited.find(parent[curr])==visited.end())
                   {
                     
                      visited.insert(parent[curr] );
                      q.push(parent[curr] );
                  }
              }
            k--;
        }
        return res;
        
    }
};