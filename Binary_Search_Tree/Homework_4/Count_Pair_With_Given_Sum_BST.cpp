class Solution
{
public:
  void inorder(Node* root,vector<int>&v)
    {  
          if(root==NULL) return;
           inorder(root->left,v);
           v.push_back(root->data);
           inorder(root->right,v);
          
    }
    
    int countPairs(Node* root1, Node* root2, int x)
    {
      vector<int> v1,v2;
      inorder(root1,v1);
      inorder(root2,v2);
      reverse(v2.begin(),v2.end());
       
      int n1=v1.size(),n2=v2.size();
      int i=0,j=0;
      int count=0;
      while(i<n1 && j<n2)
      {
            if((v1[i]+v2[j])==x)
            {   count++;
                i++;j++;
            }
            else if((v1[i]+v2[j])>x) j++;
            else i++;
       }
      return count;
   }
};