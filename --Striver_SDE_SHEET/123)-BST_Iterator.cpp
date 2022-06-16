/************************************************************

    Following is the TreeNode class structure

    template <typename T>
    class TreeNode {
       public:
        T data;
        TreeNode<T> *left;
        TreeNode<T> *right;

        TreeNode(T data) {
            this->data = data;
            left = NULL;
            right = NULL;
        }
    };

************************************************************/

class BSTiterator
{
    public: 
    vector<int>res;
     int idx;
    
    void inorder(TreeNode<int> *root)
    {
        if(root==NULL) return;
        
        inorder(root->left);
        res.push_back(root->data);
        inorder(root->right);
    }
    BSTiterator(TreeNode<int> *root)
    {
        idx=0;
        inorder(root);
        
    }

    int next()
    {
         if(idx==res.size()) return -1;
         int ans=res[idx];
         idx++;
         return ans;
    }

    bool hasNext()
    {
        if(idx==res.size()) return false;
        return true;
    }
};


/*
    Your BSTIterator object will be instantiated and called as such:
    BSTIterator iterator(root);
    while(iterator.hasNext())
    {
       print(iterator.next());
    }
*/