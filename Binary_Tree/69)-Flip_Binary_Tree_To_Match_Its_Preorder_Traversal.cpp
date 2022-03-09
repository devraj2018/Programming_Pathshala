class Solution {
public:
    
    vector<int>res;
    
    bool helper(TreeNode* root, vector<int>& voyage,int &curr_I)
    {
               if(root==NULL) return true;  
        
               if(voyage[curr_I]!=root->val) return false;
        
                curr_I++;
              
               if(root->left && root->left->val!=voyage[curr_I])
                  {
                   res.push_back(root->val);
                   return helper(root->right,voyage,curr_I) && helper(root->left,voyage,curr_I);
                   
                  }
              else
                 return helper(root->left,voyage,curr_I) && helper(root->right,voyage,curr_I);
         
     }
    
    vector<int> flipMatchVoyage(TreeNode* root, vector<int>& voyage) {
      
        int curr_I=0;
        if(!helper(root,voyage,curr_I)) return {-1};
        return res;
    }
};