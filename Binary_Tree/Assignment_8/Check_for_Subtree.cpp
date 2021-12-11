class Solution {     //  Worst case O(n * m) Method
public:
    bool identical(TreeNode* root,TreeNode* sub)
    {  if(root==NULL && sub==NULL ) return true;
     
       if(!root ||!sub || root->val!=sub->val)  return false;
       return identical(root->left,sub->left) && identical(root->right,sub->right);
       
    }
    bool isSubtree(TreeNode* root, TreeNode* subRoot) {
        queue<TreeNode*> q;
        q.push(root);
        bool flag=false;
        while(!q.empty())
        {   TreeNode *curr=q.front();
            q.pop();
             if(curr->val==subRoot->val) flag=identical(curr,subRoot);
             if(flag) return flag;
          if(curr->left) q.push(curr->left);
          if(curr->right) q.push(curr->right);
            
        }
        return flag;
         
    }
};