class Solution
{
    public:
   
    vector<int> topView(Node *root)
    {
       vector<int>res;
       if(root==NULL) return res;
        
       queue<pair<Node*,int>>q;
       unordered_map<int,int>mp;
  
       int maxx=INT_MIN,minn=INT_MAX;    // get rid of map and used unorderd_map  (for Linear time)
        q.push({root,0});
        while(!q.empty())
        {   int size=q.size();            
            
             for(int i=1;i<=size;i++)
               {
                Node* curr=q.front().first;
                int hd=q.front().second;
                q.pop();
                maxx=max(maxx,hd); minn=min(minn,hd);
               
                if(mp.find(hd)==mp.end())
                    mp[hd]=curr->data;
                if(curr->left) q.push({curr->left,hd-1});
                if(curr->right) q.push({curr->right,hd+1});
               
              }
            
          }
        
        for(int i=minn;i<=maxx;i++)  res.push_back(mp[i]);
     return res;
        
    }

};