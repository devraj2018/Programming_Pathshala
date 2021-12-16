

// Method -1-->Using stack which taken O(h)space , h is height of tree --Better than Method 2//


//Method -2--> Using O(n)space //
class BSTIterator {  // This solution using O(n) memory
public:
    TreeNode* main;int currI;
    vector<int>v;
    void inorder(TreeNode* root)
    {
        if(root ==NULL) return;
        inorder(root->left);
        v.push_back(root->val);
        inorder(root->right);
    }
    BSTIterator(TreeNode* root) {
        main=root; 
        currI=0;
        inorder(root);
    }
    
    int next() {
        int ans;
        if(hasNext())
        {
            ans=v[currI];
            currI++;
        }
        return ans;
        
    }
    
    bool hasNext() {
        return currI<v.size();
        
    }
};
