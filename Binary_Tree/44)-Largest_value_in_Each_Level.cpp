class Solution {
public:
    vector<int> largestValues(TreeNode* root) {
        vector<int>temp;
        queue<TreeNode*> q;
        q.push(root);
        int maxx;
        if(root==NULL) return temp;
        while(!q.empty())
        {   maxx=INT_MIN;
            int size=q.size();
            for(int i=0;i<size;i++)
            {
                
                TreeNode* curr=q.front();q.pop();
                maxx=max(maxx,curr->val);
                if(curr->left)q.push(curr->left);
                if(curr->right)q.push(curr->right);
            }
            temp.push_back(maxx);
            
        }
        return temp;
        
    }
};