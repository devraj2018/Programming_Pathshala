class Solution {
public:
    TreeNode* helper(TreeNode* root,int val,int depth,int curr_level,TreeNode* par,char dir='L')
    {
            if(root==NULL)
            {   TreeNode* newNode=new TreeNode(val);
                if(curr_level!=depth)
                    return NULL;
                return newNode;
             }
           root->left= helper(root->left,val,depth,curr_level+1,root,'L');
           root->right=helper(root->right,val,depth,curr_level+1,root,'R');
        
           if(curr_level==depth)
             {
                 TreeNode* newNode=new TreeNode(val);
                 if(dir=='L')
                   {
                     newNode->left=root;
                     return newNode;
                   }
                  else
                   {
                   newNode->right=root;
                   return newNode;
                   }
           }
        return root;
         
    }
    TreeNode* addOneRow(TreeNode* root, int val, int depth) {
        
       if(depth==1)
       {
           TreeNode* newroot=new TreeNode(val);
           newroot->left=root;
           return newroot;
           
       }
        int curr_level=1;
        TreeNode* par=NULL;
        return helper(root,val,depth,curr_level,par);
        
    }
};