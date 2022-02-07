
class Solution {
public:
void leftB( Node * root,vector<int>&res)
   { 
    if(root==NULL) return;
    
    if(root->left==NULL && root->right==NULL) return;
    
    res.push_back(root->data);
    
    if(root->left) leftB(root->left,res);
    else if(root->right) leftB(root->right,res);
   }
void rightB(Node* root,vector<int>&res)
   {
      if(root==NULL) return;
    
     if(root->right) rightB(root->right,res);
     else if(root->left) rightB(root->left,res);
    
      if(root->left==NULL && root->right==NULL) return;
      res.push_back(root->data);
    
  }
   void leaf( Node * root,vector<int>&res)
    {
      if(root==NULL) return;
    
      if(root->left==NULL && root->right==NULL)
           {  res.push_back(root->data);
             return;
           }
       leaf(root->left,res);
      leaf(root->right,res);
    }

  vector <int> boundary(Node *root)
     {
       if(root==NULL) return {};
       vector<int>res;
       res.push_back(root->data);
          
       if(root->left==NULL && root->right==NULL) return res;
       leftB(root->left,res);
       leaf(root,res);
       rightB(root->right,res);
      
       return res;
    }
};

// { Driver Code Starts.

/* Driver program to test size function*/

int main() {
    int t;
    string tc;
    getline(cin, tc);
    t=stoi(tc);
    while(t--)
    {
        string s ,ch;
        getline(cin, s);
        Node* root = buildTree(s);
        Solution ob;
        vector <int> res = ob.boundary(root);
        for (int i : res) cout << i << " ";
        cout << endl;
    }
    return 0;
}  // } Driver Code Ends