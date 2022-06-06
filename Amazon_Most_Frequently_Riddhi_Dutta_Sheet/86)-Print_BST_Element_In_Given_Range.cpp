class Solution {
  public:
  vector<int>res;
   void helper(Node *root, int low, int high)
   {
        if(root==NULL) return;
        
        if(root->data>high) helper(root->left,low,high);
        else if(root->data<low) helper(root->right,low,high);
        else{
            
           
              helper(root->left,low,high);
              res.push_back(root->data);
              helper(root->right,low,high);
            
        }
       
       
   }
  
    vector<int> printNearNodes(Node *root, int low, int high) {
      helper(root,low,high);
      return res;
    }
};