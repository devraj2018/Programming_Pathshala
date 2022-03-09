class Solution {     //  Worst case O(n * m) Method
public:
    bool identical(TreeNode* root,TreeNode* sub)
    {  if(root==NULL && sub==NULL ) return true;
     
       if(!root ||!sub || root->val!=sub->val)  return false;
       return identical(root->left,sub->left) && identical(root->right,sub->right);
       
    }
    bool isSubtree(TreeNode* root, TreeNode* subRoot) {
        queue<TreeNode*> q;
        q.push(root);
        bool flag=false;
        while(!q.empty())
        {   TreeNode *curr=q.front();
            q.pop();
             if(curr->val==subRoot->val) flag=identical(curr,subRoot);
             if(flag) return flag;
          if(curr->left) q.push(curr->left);
          if(curr->right) q.push(curr->right);
            
        }
        return flag;
         
    }
};

class Solution {  // O(n)Space and O(n)Time method
public:
    void preorder_with_null(TreeNode* root,  vector<int>&arr) // Its gives distict and unique order for tree
    {
          if(root==NULL)
          {
              arr.push_back(INT_MAX);
              return;
          }
          arr.push_back(root->val);
         preorder_with_null(root->left,arr);
         preorder_with_null(root->right,arr);
     }
    bool isSubtree(TreeNode* root, TreeNode* subRoot) {
        
        vector<int>array;
        vector<int>subarray;
         preorder_with_null(root,array);
         preorder_with_null(subRoot,subarray);
        int window=subarray.size();
        int j;
        if(array.size()<subarray.size()) return false;
        for(int i=0;i<=array.size()-window;i++)
        {   
              if(array[i]!=subarray[0])
                  continue;
              int k=i,j=0;
              while(j<window &&k<array.size() && array[k]==subarray[j])
              {
                  k++;j++;
              }
             if(j==window) return true;
            
            
        }
        return false;
        
    }
};