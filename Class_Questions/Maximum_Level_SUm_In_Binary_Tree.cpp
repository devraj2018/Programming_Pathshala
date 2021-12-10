#include <iostream>
using namespace std;

int sum(Node* root)
{
	 int maxx=INT_MIN;
	 queue<Node*>q;
	 if(root==NULL) return 0;
	 q.push(root);
	 int curr_level_sum;
	 while(!q.empty())
	 {   curr_level_sum=0;
	 	 int size=q.size();
	 	 for(int i=0;i<size;i++)
	 	 {
	 	 	 Node* curr=q.front();q.pop();
	 	 	 curr_level_sum+= curr->data;
	 	 	 
	 	 	 if(curr->left) q.push(curr->level);
	 	 	 if(curr->right) q.push(curr->right);
	 	 	
	 	 }
	 	 maxx=max(maxx,curr_level_sum);
       }
	 return maxx;

}
