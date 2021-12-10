class Solution {
public:
    vector<int>res;
   
    bool helper(TreeNode* root, vector<int>& voyage,int &curr_Index)
    {  
           if(root==NULL) return true;
          
           if(root->val != voyage[curr_Index])
               return false;
           curr_Index++;
           if(root->left && root->left->val != voyage[curr_Index])
           {    res.push_back(root->val);
                return helper(root->right,voyage,curr_Index) && helper(root->left,voyage,curr_Index);
           }
          else
              return helper(root->left,voyage,curr_Index) && helper(root->right,voyage,curr_Index);
        
    }
    vector<int> flipMatchVoyage(TreeNode* root, vector<int>& voyage) {
        int curr_Index=0;
        if(helper(root,voyage,curr_Index))
        {
            return res;
        }
        return {-1};
        
    }
};