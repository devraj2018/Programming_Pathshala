// Easy Approach
 
class Solution {
public:
      TreeNode* addOneRow(TreeNode* root, int val, int depth) {
         if(depth==1)
           {
              TreeNode* newroot=new TreeNode(val);
              newroot->left=root;
              return newroot;
           }
            
        queue<TreeNode*>q;
        q.push(root);
        while(!q.empty())
        {
             if(depth==2) break;
            
            int size=q.size();
            for(int i=0;i<size;i++)
               {
                  TreeNode* curr=q.front();
                   q.pop();
                
                   if(curr->left) q.push(curr->left);
                    if(curr->right) q.push(curr->right);
               }
             
             depth--;
         }

        while(!q.empty())
        {
             TreeNode* curr=q.front(); q.pop();
            
             TreeNode* lft=curr->left;
             TreeNode* rgt=curr->right;
            
            TreeNode* newNode1=new TreeNode(val),*newNode2=new TreeNode(val);
            newNode1->left=lft;
            newNode2->right=rgt;
            curr->left=newNode1;
            curr->right=newNode2;
            
       }
        return root;
     }
};



//    Another Approach --- Thoda sa tricky hai   //
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