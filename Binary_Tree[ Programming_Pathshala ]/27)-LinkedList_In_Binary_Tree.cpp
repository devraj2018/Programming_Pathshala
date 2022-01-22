class Solution {
public:
    bool ans=false;   // Global
    void checkPath(ListNode* head,TreeNode *root)
    {    
          if(head==NULL) 
              {  ans=true;
                  return;
              }
          if(root==NULL) return;
          if(root->val!= head->val) return;
          checkPath(head->next,root->left);
          checkPath(head->next,root->right);
      
    }
    void Path(ListNode* head,TreeNode* root)
    {
         if(root==NULL) return;
        
         if(root->val== head->val) checkPath(head,root);
         if(ans==true) return;
         Path(head,root->left);
         Path(head,root->right);
        
        
    }
    
    bool isSubPath(ListNode* head, TreeNode* root) {
        Path(head,root);
        return ans;
        
    }
};