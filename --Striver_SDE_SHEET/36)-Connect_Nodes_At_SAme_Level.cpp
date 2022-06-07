/*
    ----------------- Binary Tree node class for reference -----------------

    template <typename T>
    class BinaryTreeNode {
        public : 
            T data;
            BinaryTreeNode<T> *left;
            BinaryTreeNode<T> *right;
            BinaryTreeNode<T> *next;

            BinaryTreeNode(T data) {
                this -> data = data;
                left = NULL;
                right = NULL;
                next = NULL;
            }
    };
*/
#include<bits/stdc++.h>
void connectNodes(BinaryTreeNode< int > *root) {
     if(root==NULL) return;
        
        queue<BinaryTreeNode< int >*>q;
        q.push(root);
        BinaryTreeNode< int >* prev=NULL;
        while(!q.empty())
        {
             int size=q.size();
             prev=NULL;
             for(int i=0;i<size;i++)
             {
                  BinaryTreeNode< int >* curr=q.front();
                  q.pop();
                 
                  if(prev)
                  {
                      prev->next=curr;
                  }
                  prev=curr;
                 
                 if(curr->left) q.push(curr->left);
                 if(curr->right) q.push(curr->right);
                 
            }
            
            
            
        }
       
}