class Solution { 
    private: int max_h=0,ans=0;
public:
     void sum_recursive(TreeNode* root,int height=1) // Uses RecursiveStack as a Extra Space
       {   if(root==NULL) return;
           if(root->left==NULL && root->right==NULL)
             {  
                  if(height>max_h)
                   {  ans=0;  max_h=height;
                   }
                  if(height==max_h)
                    ans+=root->val;
                 return;  
             }
             sum(root->left,height+1);
             sum(root->right,height+1);
      }
    void sum_Iterative(TreeNode* root) {   // Uses Queue as a Extra Space
         queue<TreeNode*>q;
         q.push(root);
         while(!q.empty())
          {  ans=0;
             int size=q.size();
             for(int i=1;i<=size;i++)
              {
                 TreeNode* curr=q.front(); q.pop();
                 ans+=curr->val;
                 if(curr->left) q.push(curr->left);
                if(curr->right) q.push(curr->right);
              }  
          }
    }
    
     int deepestLeavesSum(TreeNode* root)
     {  
         sum_recursive(root); //   or sum_Iterative(root);
         return ans;
    }