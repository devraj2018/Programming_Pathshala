
/*----- Method-1 ->Brute Force Do inorder traversal store it and check if array is
                   strictly incresing or not O(n)Extra space to store inorder--------*/

/*----- Method-2 ->Brute Force Do inorder traversal and keep track of prev ele and check
                     O(1)Extra space --------
 
class Solution {
public:
    bool ans=true;
    void helper(TreeNode* root,long long &prev)
    {  if(root==NULL)return;
     
        helper(root->left,prev);
     
      if(root->val<=prev)
        {
          ans=false;  return;
        }
      else prev=root->val;
      helper(root->right,prev);
    }
    bool isValidBST(TreeNode* root) {
      long long prev=LLONG_MIN;
      helper(root,prev);
      return ans;
        
    }
};*/

//Method -3-->> By returing max min ans isBst for every child and thn checking for root-------//

/*class Info{
    public:
     long long maxx;  long long minn;  bool isBst;
     Info(long long maxxx,long long minnn,bool is)
     {
         maxx=maxxx;minn=minnn;isBst=is;
     }
};
class Solution {
public:
    Info helper(TreeNode* root)
    {
         if(root==NULL)  return Info(LLONG_MIN,LLONG_MAX,true);
         
        Info lft=helper(root->left);
        Info rgt=helper(root->right);
        
        bool newisBst= (lft.isBst && rgt.isBst) &&(lft.maxx < root->val) &&(rgt.minn > root->val);
        
        return Info(max({lft.maxx,rgt.maxx,(long long)root->val}) , min({lft.minn,rgt.minn,(long long)root->val}), newisBst);
        
    }
    bool isValidBST(TreeNode* root) {
     
        Info ans=helper(root);
        return ans.isBst;
    }

};*/

// Method --4    -----------Most Optimized Approach---------------//

class Solution {
public:
    bool isValidBST(TreeNode* root,long long left=LLONG_MIN,long long right=LLONG_MAX) {
        
        if(root==NULL) return true;
        
        
        if(root->val >right || root->val < left) return false;
        
        return isValidBST(root->left,left,(long long)root->val-1) &&isValidBST(root->right,(long long)root->val+1,right) ;
        
    }
};