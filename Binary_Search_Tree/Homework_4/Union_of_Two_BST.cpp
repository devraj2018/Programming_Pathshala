class Solution {
public:
    
    void inorder(TreeNode* root, vector<int>&res)
    {
        if(root==NULL) return;
        inorder(root->left,res);
        res.push_back(root->val);
        inorder(root->right,res);
    }
    vector<int> getAllElements(TreeNode* root1, TreeNode* root2) {
         vector<int>res,temp;
         inorder(root1,res);
         int n1=res.size();
         inorder(root2,temp);
         int n2=temp.size();
         if(n1==0) return temp;
         if(n2==0) return res;
         res.resize(n1+n2);
     
         int e1=n1-1,e2=n2-1,k=n1+n2-1;
        
        while( e1>=0 && e1<k)
        { 
             if(temp[e2]>=res[e1]) res[k--]=temp[e2--];
             else res[k--]=res[e1--];
          }
        while(e2>=0) res[k--]=temp[e2--];
         
        return res;
        
        
        
        
        
        
    }
};