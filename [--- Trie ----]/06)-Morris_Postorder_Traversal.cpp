class Solution {
public:
    vector<int> postorderTraversal(TreeNode* root) {
         vector<int> res;
        
        while(root!=NULL)
        {
            if(root->right==NULL)
            {
                res.push_back(root->val);
                root=root->left;
            }
            else{
                
                TreeNode * successor=root->right;
                
                while(successor->left!=NULL && successor->left!=root)
                {
                    successor=successor->left;
                }
                

                
                if(successor->left==NULL) // Means we haven't traversed right part yet
                {
                    res.push_back(root->val);
                    successor->left=root;
                    root=root->right;
                }
                else{
                    successor->left=NULL;
                      root=root->left;
                }
                
            }
            
        }
        reverse(res.begin(),res.end());
        return res;
    }
};