
class Solution {
public:
    TreeNode* helper(vector<int>& preorder,int &curr_I,int left,int right)
    {
        if(curr_I==preorder.size()) return NULL; 
        TreeNode* newroot=NULL;
        
        if(preorder[curr_I]>left && preorder[curr_I]<right)
        {
            newroot=new TreeNode(preorder[curr_I]);
            curr_I++;
            newroot->left=  helper(preorder,curr_I,left,newroot->val);
            newroot->right=  helper(preorder,curr_I,newroot->val,right);
            
        }
        return newroot;
        
        
        
        
    }
    TreeNode* bstFromPreorder(vector<int>& preorder) {
        
        int curr_I=0;
        return helper(preorder,curr_I,INT_MIN,INT_MAX);
        
    }
};