class Solution {
public:
    
    int helper(Node* root,int &res)
    {
         if(root==NULL) return 0;
         
         if(root->left==NULL && root->right==NULL) return root->data;
         
         int lsum=helper(root->left,res);
         int rsum=helper(root->right,res);
         
          if(root->left && root->right)   //  If both child exists means we can consider path from 
           {  res=max(res,lsum+rsum+root->data);   // Left leave to root to right leave
              return max(lsum,rsum)+root->data;
           }
          else if(root->left)  // If Only left child exists,we cannot update res bcz right child is missing
           {  
              return lsum+root->data;
           }
           
             return rsum+root->data;// If Only right child exists,we cannot update res bcz left child is missing
           
         
    }
    int maxPathSum(Node* root)
    {  int res=INT_MIN;
       int x= helper(root,res);
        if(res == INT_MIN) // Base case when only one leaf node exits
         	return x; //In that case we return path sum from root to that leaf;
    
         return res; // Else we have our answer 
    }
};
