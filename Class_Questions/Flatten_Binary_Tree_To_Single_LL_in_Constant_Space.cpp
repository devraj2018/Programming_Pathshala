 #include <bits/stdc++.h>
  using namespace std;
class TreeNode {
	public:
     int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x){
    	val=x;
    	left=NULL;right=NULL;
    }
  };
  
  TreeNode* flatten(TreeNode* root)
    {  
    	 if(root==NULL) return NULL;
 
    	 TreeNode* curr=root;
    	 TreeNode* temp=root->right;
    	 root->right=root->left;
    	 root->left=NULL;
 
    	 while(curr->right)
    	 {
    	 	curr=curr->right;
    	 }
    	 curr->right=temp;
    	 root->right=flatten(root->right);
    	 return root;
 
    }

    int main() {
 	TreeNode *root=new TreeNode(1);
    root->left=new TreeNode(2);
 	root->right=new TreeNode(5);
 	root->left->left=new TreeNode(3);
 	root->left->right=new TreeNode(4);
 	root->right->right=new TreeNode(6);
 	
 	TreeNode* head=flatten(root);
 	 while(head)  // Flatten print
 	 {
 		cout<<head->val<<" ";
 		head=head->right;
 	 }
 
}