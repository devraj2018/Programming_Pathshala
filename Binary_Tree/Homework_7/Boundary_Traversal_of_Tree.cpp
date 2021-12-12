class Solution {
public:
    vector<int>res;
    void left_Boundary(Node* root)
    {  if(root==NULL) return;
       if(root->left==NULL && root->right==NULL) return;
      
       res.push_back(root->data);
       if(root->left)  left_Boundary(root->left);
       else left_Boundary(root->right);
    }
    void right_Boundary(Node* root)
    {  if(root==NULL) return;
       if(root->left==NULL && root->right==NULL) return;
      
       if(root->right) right_Boundary(root->right);
       else right_Boundary(root->left);
       
       res.push_back(root->data);
      
    }
    void leaves(Node* root)
    {  if(root==NULL) return;
    
       if(root->left==NULL && root->right==NULL) res.push_back(root->data);
        leaves(root->left);
        leaves(root->right);
    }
    vector <int> boundary(Node *root)
    {
       if(root==NULL) return res;
       res.push_back(root->data);
       left_Boundary(root->left);
       leaves(root);
       right_Boundary(root->right);
       return res;
    }
};