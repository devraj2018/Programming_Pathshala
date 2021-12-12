class Solution {
public:
    vector<int>inorder;
    TreeNode* helper(int start,int end)
    {
         if(start>end) return NULL;
        
         int mid=start +(end-start)/2;
         TreeNode* newroot=new TreeNode(inorder[mid]);
         newroot->left=helper(start,mid-1);
         newroot->right=helper(mid+1,end);
         return newroot;
     }
    TreeNode* sortedListToBST(ListNode* head) {
        
        while(head)
        { inorder.push_back(head->val); head=head->next;
         }
        return helper(0,inorder.size()-1);
        
        
    }
};