class Solution {
public:
    void leftB(Node* root,vector<int>&res)
    {
        if(root==NULL) return;
    
        if(root->left!=NULL || root->right!=NULL)
          res.push_back(root->data);
          
        if(root->left) leftB(root->left,res);
        else if(root->right) leftB(root->right,res);
    
    }
     void rightB(Node* root,vector<int>&res)
    {
        if(root==NULL) return;
    
       
          
         if(root->right) rightB(root->right,res);
         else if(root->left) rightB(root->left,res);
        
         if(root->left!=NULL || root->right!=NULL)
             res.push_back(root->data);
    
    }
    void leaves(Node* root,vector<int>&res)
    {
        
        
         if(root==NULL) return;
         
         if(root->left==NULL && root->right==NULL) res.push_back(root->data);
         
         leaves(root->left,res);
         leaves(root->right,res);
        
        
        
        
    }
    vector <int> boundary(Node *root)
    {
         if(root==NULL) return {};
         if(root->left==NULL && root->right==NULL) return {root->data};
         vector<int>res;
         res.push_back(root->data);
         
         leftB(root->left,res);
         leaves(root,res);
         rightB(root->right,res);
         
         return res;
    }
};
