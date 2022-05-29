/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    TreeNode* addOneRow(TreeNode* root, int val, int depth) {
        
        TreeNode* node=new TreeNode(val);
        if(depth==1)
        {
            node->left=root;
            return node;
        }
        
        
        queue<TreeNode*>q;
        q.push(root);
        while(!q.empty())
        {
             
             if(depth-2==0) break;
            
             int size=q.size();
             for(int i=0;i<size;i++)
             {
                 TreeNode* curr=q.front();
                 q.pop();
                 
                 if(curr->left) q.push(curr->left);
                 if(curr->right) q.push(curr->right);
                  
             }
            
            depth--;
        }
             int size=q.size();
             for(int i=0;i<size;i++)
             {
                 TreeNode* curr=q.front();
                 q.pop();
                 
                 TreeNode* currleft=curr->left;
                 TreeNode* currright=curr->right;
                 
                 TreeNode* newnode=new TreeNode(val);
                 TreeNode* newnode1=new TreeNode(val);
                 
                 curr->left=newnode;
                 curr->right=newnode1;
                 
                 newnode->left=currleft;
                 newnode1->right=currright;
                 
             
                  
             }
        return root;
        
        
    }
};