#include <iostream>
using namespace std;

void storeInorder(Node* root,vector<int>&inorder)
{   if(root==NULL) return;
	storeInorder(root->left,inorder)
	inorder.push_back(root->data);
	storeInorder(root->left,inorder)
}
void transform(Node* root,vector<int>&inorder,int &curr_I)
{
	 if(root==NULL) return;
	 
	 transfrom(root->left,inorder,curr_I);
      
     root->data= inorder[curr_I-1]+inorder[curr_I+1];
     curr_I++;
     
     transfrom(root->right,inorder,curr_I);
	
}

int main() {
   vector<int>inorder;
   inorder.push_back(0);   //  To handle negative indexing for first ele
   storeInorder(root,inorder);
   inorder.push_back(0);  //  To handle out of bound indexing for last ele
   int curr_I=1;
   transform(root,inorder,curr_I);
   
}