
class Solution {
public:
    void Util(TreeNode* root,int currNumber,int &totalSum)
    {   if(root==NULL ) return;
        currNumber= currNumber*10+ root->val;
        
        if(root->left==NULL && root->right==NULL)
        {
            
            totalSum+= currNumber;
            
        }
      Util(root->left,currNumber,totalSum);
      Util(root->right,currNumber,totalSum);
        
        
        
        
    }
    int sumNumbers(TreeNode* root) {
        int currNumber=0;
        int totalSum=0;
        Util(root,currNumber,totalSum);
        return totalSum;
        
    }
};