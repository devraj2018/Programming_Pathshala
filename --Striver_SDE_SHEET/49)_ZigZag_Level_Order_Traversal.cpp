/*************************************************************

    Following is the Binary Tree node structure

    class BinaryTreeNode
    {
    public :
        T data;
        BinaryTreeNode<T> *left;
        BinaryTreeNode<T> *right;

        BinaryTreeNode(T data) {
            this -> data = data;
            left = NULL;
            right = NULL;
        }
    };

*************************************************************/

vector<int> zigZagTraversal(BinaryTreeNode<int> *root)
{
    vector<int>res;
        if(root==NULL) return res;
        
        queue<BinaryTreeNode<int>*>q;
        q.push(root);
        bool rev=false;
        
        while(!q.empty())
        {
            int size=q.size();
            vector<int>temp(size);
            
            for(int i=0;i<size;i++)
            {
                BinaryTreeNode<int>* curr=q.front();
                q.pop();
                
                if(rev) temp[size-i-1]=curr->data;
                else temp[i]=curr->data;
                
                if(curr->left) q.push(curr->left);
                if(curr->right) q.push(curr->right);
                
             }
            rev=!rev;
            for(auto x:temp)
            res.push_back(x);
            
        }
        return res;
        
}
