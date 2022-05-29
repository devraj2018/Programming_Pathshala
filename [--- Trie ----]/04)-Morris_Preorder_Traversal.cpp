class Solution {
public:
    vector<int> preorderTraversal(TreeNode* root) {
        
        vector<int> res;
        
        while(root!=NULL)
        {
            if(root->left==NULL)
            {
                res.push_back(root->val);
                root=root->right;
            }
            else{

                
                
                TreeNode * predecessor=root->left;
                
                while(predecessor->right!=NULL && predecessor->right!=root)
                {
                    predecessor=predecessor->right;
                }
                
                if(predecessor->right==NULL) // Means we haven't traversed left part yet
                {
                    res.push_back(root->val);
                    predecessor->right=root;
                    root=root->left;
                }
                else{
                    predecessor->right=NULL;
                      root=root->right;
                }
                
            }
            
        }
        return res;
        
    }
};