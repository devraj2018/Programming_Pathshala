class Solution {
public:
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        if(root==NULL) return {};
        vector<vector<int>> res;
        vector<int> temp;
        bool rev=false;
        queue<TreeNode*> q;
        q.push(root);
        while(!q.empty())
        {  
            int size=q.size();
            for(int i=1;i<=size;i++)
            {  TreeNode* curr=q.front();q.pop();
              
               temp.push_back(curr->val);
               if(curr->left) q.push(curr->left);
               if(curr->right) q.push(curr->right);
                
            }
            if(!rev)
            {
                res.push_back(temp);
            }
            else
            {
                reverse(temp.begin(),temp.end());
                res.push_back(temp);
            }
            rev= !rev;
            temp.clear();
       }
        return res;
    }
};