/*   
    template <typename T = int>
	class TreeNode
	{
		public:
		T data;
		TreeNode<T> *left;
		TreeNode<T> *right;

		TreeNode(T data)
		{
			this->data = data;
			left = NULL;
			right = NULL;
		}

		~TreeNode()
		{
			if (left != NULL)
			{
		  		delete left;
			}
			if (right != NULL)
			{
			 	delete right;
			}
		}
	};
*/

void helper(TreeNode<int> *root, int x, vector<int>&res, vector<int>&curr)
{
     if(root==NULL) return;
     
     curr.push_back(root->data);
     if(root->data==x)
     {
         res=curr;
         return;
     }
    helper(root->left,x,res,curr);
    helper(root->right,x,res,curr);
    
    curr.pop_back();
    
         
    
}
vector<int> pathInATree(TreeNode<int> *root, int x)
{
   vector<int>res,curr;
    helper(root,x,res,curr);
    return res;
}
