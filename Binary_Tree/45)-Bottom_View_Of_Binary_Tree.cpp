class Solution
{
    public:
  
    vector<int> bottomView(Node *root)
    {
       vector<int>res;
       if(root==NULL) return res;
        
       queue<pair<Node*,int>>q;
       unordered_map<int,int>mp;
  
       int maxx=INT_MIN,minn=INT_MAX;    // To get rid of map and used unorderd_map  
        q.push({root,0});
        while(!q.empty())
        {   int size=q.size();            
            
             for(int i=1;i<=size;i++)
               {
               Node* curr=q.front().first;
               int hd=q.front().second;
               q.pop();
               maxx=max(maxx,hd); minn=min(minn,hd);
               
               mp[hd]=curr->data;

               if(curr->left) q.push({curr->left,hd-1});
               if(curr->right) q.push({curr->right,hd+1});
               
              }
            
         }
        
        for(int i=minn;i<=maxx;i++)  res.push_back(mp[i]);
     return res;
        
    }

};