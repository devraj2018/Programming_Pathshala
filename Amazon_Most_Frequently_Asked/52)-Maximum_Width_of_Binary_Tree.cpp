 
class Solution {
public:
    int widthOfBinaryTree(TreeNode* root) {
        
        int ans=INT_MIN;
        if(root==NULL) return 0;
        
        queue<pair<TreeNode*,long long int>>q;
        q.push({root,0});
       
       
        while(!q.empty())
        {
            int size=q.size();
            long long int minn=q.front().second;
            int first,last;
            for(int i=0;i<size;i++)
               {
                  TreeNode* curr=q.front().first;
                  long long int curr_pos= q.front().second-minn;
                  q.pop();
                
                  if(i==0) first=curr_pos;
                  if(i==size-1) last=curr_pos;
                
                  if(curr->left) q.push({curr->left,2*curr_pos+1});
                  if(curr->right) q.push({curr->right,2*curr_pos+2});
               }
            ans=max(ans,last-first+1);
        }
        return ans;
     }
};

