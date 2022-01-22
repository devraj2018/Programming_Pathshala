#include <bits/stdc++.h>
using namespace std;
class Node {
public:
	int data;
	Node *left, *right;
	Node(int x)
	{
		data=x;
		left=NULL;right=NULL;
	}
};
vector<vector<int>>res;

void helper(Node* root,unordered_set<int>&s,int sum,bool &flag)
{

    if (root==NULL) return;
    
    if(s.find(sum-root->data)!=s.end())
    {
    	flag=true;
    	res.push_back({root->data,sum-root->data});
    	
    }
    if(root->data>=sum)
    { 
      s.insert(root->data);
       helper(root->left,s,sum,flag);
    }
    else{
       s.insert(root->data);
       helper(root->left,s,sum,flag);
       helper(root->right,s,sum,flag);
       }
    
}
int main()
{
	Node* root = new Node(15);
	root->left = new Node(10);
	root->right = new Node(20);
	root->left->left = new Node(8);
	root->left->right = new Node(12);
	root->right->left = new Node(18);
	root->right->right = new Node(25);
    unordered_set<int>st;
	int target = 30;
	
	
	bool flag=false;
	helper(root,st,target,flag);
	if(flag)
     {
     	for(auto x:res)
     	{
     		 cout<<x[0]<<"  "<<x[1]<<endl;
     	}
     }
	else cout<<"false";
}