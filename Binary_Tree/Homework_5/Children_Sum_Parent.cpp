class Solution{
    public:
    int ans=1;
    int sum(Node* root)
    {   if(root==NULL) return 0;
        if(root->left==NULL && root->right==NULL) return root->data;
    
        int lsum=sum(root->left);
        int rsum=sum(root->right);
      
        if(lsum+rsum != root->data)
        {    ans=0;
             return 0;
        }
       return root->data; 
    }
    int isSumProperty(Node *root)
    {
        sum(root);
        return ans;
    }
};