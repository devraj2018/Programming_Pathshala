class Solution{
  public:
    // root : the root Node of the given BST
    // target : the target sum
    unordered_set<int>s;bool ans=false;
    void helper(struct Node* root,int target)
    {    if(ans) return;
         if(root==NULL) return;
        helper(root->left,target);
         if(s.find(target-root->data)!=s.end())
          { ans=true;
               return;
          }
         s.insert(root->data);
       helper(root->right,target);
          
    }
    int isPairPresent(struct Node *root, int target)
    {
       helper(root,target);
       if(ans)
       return 1;
       return 0;
    }
};