 
class Solution {
public:
    vector<int>res;
    bool ans=true;
    void helper(TreeNode* root, vector<int>& voyage,int &curr_I)
        {
            if(root==NULL) return;
        
            if(voyage[curr_I]!= root->val) {
                 ans=false;
                 return;
                }
        
             curr_I++;
        
             if(curr_I<voyage.size() &&root->left && voyage[curr_I]!=root->left->val)
                 {
                    res.push_back(root->val);
                    helper(root->right,voyage,curr_I);
                    helper(root->left,voyage,curr_I);
                 }
            else
                {  helper(root->left,voyage,curr_I); 
                   helper(root->right,voyage,curr_I);
             
                }
       
      }
    
     vector<int> flipMatchVoyage(TreeNode* root, vector<int>& voyage) {
       
        int curr_I=0;
        helper(root,voyage,curr_I);
        if(ans==false) return {-1};
        return res;
    }
};