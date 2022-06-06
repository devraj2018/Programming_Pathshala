class Solution
{
    public:
    //Function to return a list of nodes visible from the top view 
    //from left to right in Binary Tree.
    vector<int> topView(Node *root)
    {
         vector<int>res; 
         if(root==NULL) return res;
        
        
         unordered_map<int,int>mp;
         queue<pair<Node*,int>>q;
         int maxx=0,minn=0;
         q.push({root,0});
        
        while(!q.empty())
        {
                 Node* curr=q.front().first;
                 int vd=q.front().second;
                 q.pop();
            
                 maxx=max(maxx,vd);
                 minn=min(minn,vd);
            
                  mp[vd]=curr->data;
            
                 if(curr->left) q.push({curr->left,vd-1});
                 if(curr->right) q.push({curr->right,vd+1});
               
          
           
        }
        
        for(int i=minn;i<=maxx;i++)
        {
            res.push_back(mp[i]);
        }
        return res;
        
    }

};
