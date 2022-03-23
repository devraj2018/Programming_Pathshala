class Solution {
public:
    
    vector<int> inorderTraversal(TreeNode* root) {
        vector<int>res;
        
        TreeNode* curr=root;
        
         while(curr!=NULL)
            {
               if(curr->left==NULL)
                 {
                    res.push_back(curr->val);
                    curr=curr->right;
                 }
               else
                {
                   TreeNode* predecessor=curr->left;
                  while( predecessor->right!=NULL &&  predecessor->right!=curr)
                     {
                        predecessor= predecessor->right;
                     }
                 
                  if( predecessor->right==curr)  // Already a backlink and we completed left part
                     {
                       res.push_back( curr->val);
                       predecessor->right=NULL;
                       curr=curr->right;
                     }
                  else
                    {
                      predecessor->right=curr;
                      curr=curr->left;
                    }
                }
          }
        return res;
        
        
         
    }
};