#include <iostream>
using namespace std;
bool ans=true;
int actual_level=-1;
void helper(Node* root,int curr_level)
{    
	if(ans==false) return;
	
    if(root==NULL) return;
	 
	 if(root->left==NULL && root->right==NULL)
	 {
	 	   if(actual_level==-1)  actual_level=curr_level;
	 	   else if(curr_level!= actual_level)  ans=false;
	 	       	 
	 	   return;   
	 }
	 helper(root->left,curr_level+1);
	 helper(root->right,curr_level+1);
}

int main() {
    helper(root,0,actual_level);
    if(ans) cout<<"Yes";
	else cout<<"No";  
}