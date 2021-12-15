class Solution {  // Most Optimized O(n)time and constant space except recursive stack
public:
    TreeNode* helper(vector<int>& preorder,int &currI,int minn,int maxx)
    {      if(currI>=preorder.size())
               return NULL;
           TreeNode* newroot=NULL; 
           if(minn< preorder[currI] && preorder[currI]<maxx)
           {
               newroot=new TreeNode(preorder[currI]);
               currI++;
               newroot->left=helper(preorder,currI,minn,newroot->val);
               newroot->right=helper(preorder,currI,newroot->val,maxx);
         
           }
       return newroot;
           
  }
    TreeNode* bstFromPreorder(vector<int>& preorder) {
        int currI=0;
        return helper(preorder,currI,INT_MIN,INT_MAX);
     }
};


// Method-2->. O(n*logn) approach bcz sorting in used O(n) space


class Sol {
public:
    unordered_map<int,int>mp;
    TreeNode* helper(vector<int>&preorder,int &curr_I,int start,int end)
    {
         if(start>end) return NULL;
        
         int mid=mp[preorder[curr_I]];
        
         TreeNode* newroot=new TreeNode(preorder[curr_I]);
         curr_I++;
        
         newroot->left=helper(preorder,curr_I,start,mid-1);
        newroot->right=helper(preorder,curr_I,mid+1,end);
        
        return newroot;
        
        
    }
    TreeNode* bstFromPreorder(vector<int>& preorder) {
      
        vector<int> pre=preorder;
        sort(preorder.begin(),preorder.end());
        int curr_I=0;
        for(int i=0;i<preorder.size();i++)
            mp[preorder[i]]=i;
        
        return helper(pre,curr_I,0,preorder.size()-1);
        
        
    }
};
