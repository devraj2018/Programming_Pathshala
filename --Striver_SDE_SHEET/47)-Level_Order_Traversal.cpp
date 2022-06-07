/************************************************************

    Following is the BinaryTreeNode class structure

    template <typename T>
    class BinaryTreeNode {
       public:
        T val;
        BinaryTreeNode<T> *left;
        BinaryTreeNode<T> *right;

        BinaryTreeNode(T val) {
            this->val = val;
            left = NULL;
            right = NULL;
        }
    };

************************************************************/
vector<int> getLevelOrder(BinaryTreeNode<int> *root)
{
     vector<int> res;
        if(root==NULL) return res ;
        
        queue<BinaryTreeNode<int>*>q;
        q.push(root);
        
        while(!q.empty())
        {    
            int size=q.size();
            for(int i=0;i<size;i++)
            {   BinaryTreeNode<int>* curr=q.front();
                q.pop();
                res.push_back(curr->val);
               if(curr->left) q.push(curr->left);
              if(curr->right) q.push(curr->right);
                 
                
                
            }
        
           
            
        }
        return res;
}