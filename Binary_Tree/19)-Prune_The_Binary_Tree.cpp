class Solution {       //  My actual Approach-->first come up
public:
    pair<int,TreeNode*> count1(TreeNode* root)   
    {   
           if(root==NULL) return {0,NULL};
        
            pair<int,TreeNode*> left_count=count1(root->left);
            pair<int,TreeNode*> right_count=count1(root->right);
        
            if(left_count.first==0) root->left=NULL;
            if(right_count.first==0) root->right=NULL; 
           
            if(left_count.first==0 && right_count.first==0 && root->val==0)
                return {0,NULL};
               
            
            int val=(root->val==1?1:0)+left_count.first+right_count.first;
            return {val,root};
     }
    TreeNode* pruneTree(TreeNode* root) {
        
        pair<int,TreeNode*> ans=count1(root);
        return ans.second;
        
    }
};

class Solution {                 //Another Classic Approach
private:
    
    // Take root by reference so changes persist
    TreeNode* pruneOurTree(TreeNode*& root) {
        if (!root) return nullptr;

		// Go to the bottom of the tree first.
        root->left = pruneOurTree(root->left);
        root->right = pruneOurTree(root->right);
		
		// We only trim if the node's value is 0 and it doesn't have kids
        if (root->val == 0 && root->left == nullptr && root->right == nullptr) {
		// We get rid of it by setting the node to nullptr;
            return nullptr;
        }
		// Otherwise we leave the node the way it is
        return root;
    }
    
    
public:
    
    TreeNode* pruneTree(TreeNode* root) {
        pruneOurTree(root);
        return root;
    }
};