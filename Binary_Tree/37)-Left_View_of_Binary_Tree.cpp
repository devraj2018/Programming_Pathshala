void helper(Node* root,vector<int>&res,int level=0)   // Recursive -->O(1)space Excluding recursive 
    {      if(root==NULL) return;
     
           if(res.size()==level)
             res.push_back(root->data);        // Better Approach
           helper(root->left,res,level+1);
           helper(root->right,res,level+1);
   }
vector<int> leftView(Node *root)
    {   vector<int>res;
        helper(root,res);
        return res;
    }

vector<int> leftView(Node *root)         // Level order -->O(n)space Queue
{
        if(root==NULL) return {};
       
        vector<int> temp;
       
        queue<Node*> q;
        q.push(root);
        
        while(!q.empty())
        {  
            int size=q.size();
            for(int i=1;i<=size;i++)
            {  Node* curr=q.front();q.pop();     
               if(i==1)
               temp.push_back(curr->data);   // First Node of every Level
               if(curr->left) q.push(curr->left);
               if(curr->right) q.push(curr->right);
                
            }
           
       }
       return temp;
}