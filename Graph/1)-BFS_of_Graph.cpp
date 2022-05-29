class Solution {
  public:
    // Function to return Breadth First Traversal of given graph.
     vector<int> bfsOfGraph(int V, vector<int> adj[]) {
       vector<bool>vis(V,false);
       vector<int>res;
       queue<int>q;
        q.push(0);
        vis[0]=true;
        while(!q.empty())
           {
            int curr=q.front();
            res.push_back(curr);
            q.pop();
            for(auto neighbour:adj[curr])
               {
                  if(!vis[neighbour])
                     { 
                        vis[neighbour]=true;
                        q.push(neighbour);
                     }
                 }
           
           
           }
       return res;
        
    }
};