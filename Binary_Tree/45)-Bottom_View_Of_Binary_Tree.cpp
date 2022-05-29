class Solution {
  public:
    vector <int> bottomView(Node *root) {
       int minn=INT_MAX;
        int maxx=INT_MIN;
        
        unordered_map<int,int>mp;
        vector<int>res;
        if(root==NULL) return res;
        queue<pair<Node*,int>>q;
        q.push({root,0});
        
        while(!q.empty())
        {
            Node* curr=q.front().first;
            int vh=q.front().second;
            q.pop();
            minn=min(minn,vh);
                  maxx=max(maxx,vh);
            
               mp[vh]=curr->data;
            
            if(curr->left) q.push({curr->left,vh-1});
            if(curr->right) q.push({curr->right,vh+1});
        }
    
      
      for(int i=minn;i<=maxx;i++)
        {
            res.push_back(mp[i]);
        }
        return res;
    }
};