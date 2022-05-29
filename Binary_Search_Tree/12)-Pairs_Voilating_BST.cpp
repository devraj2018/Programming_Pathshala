void retrieve(Node* root,vector<int>&v)
    {   if(root==NULL) return;
           retrieve(root->left,v);
           v.push_back(root->data);
          retrieve(root->right,v);
       
    }
int pairsViolatingBST(Node *root,int n){
         vector<int>v;
         retrieve(root,v);
         int ans=0;
         for(int i=0;i<v.size();i++)
         { 
             for(int j=0;j<i;j++)
              {
                  if(v[j]>=v[i]) ans++;
              }
              
        }
         return ans;
}