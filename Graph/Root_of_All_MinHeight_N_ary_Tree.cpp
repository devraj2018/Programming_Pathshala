class Solution {// O(n) Toposort like approach -> Check solution section of this question [Best Expalnation]
public:
    vector<int> findMinHeightTrees(int n, vector<vector<int>>& edges) {
        if(n==1) return {0}; 
        vector<int>adj[n];
         vector<int>res;
         vector<int>Indegree(n,0);
        
         for(int i=0;i<edges.size();i++)
           { adj[edges[i][0]].push_back(edges[i][1]);
             adj[edges[i][1]].push_back(edges[i][0]);
             Indegree[edges[i][0]]++;
             Indegree[edges[i][1]]++;
           }
          queue<int>q;
          for(int i=0;i<n;i++) if(Indegree[i]==1) q.push(i);
            
        while(!q.empty())
        {    res.clear();
             int size=q.size();
               for(int i=1;i<=size;i++)
                  {    
                    int curr=q.front(); q.pop();
                    res.push_back(curr);
                    Indegree[curr]--;
                    for(auto x:adj[curr])
                       {    Indegree[x]--;
                            if(Indegree[x]==1) q.push(x);
                        }
                   }
                  
          }
        return res;
        }
     
};


class Solution { // Take every node as root and find all tree coressponding to min height

public:
    int height( vector<int>adj[],int src,int par)  // Calculate height in O(n)time
    {
          if(adj[src].size()==1 && par!=-1) return 1;
          int m=-1;
           for(auto x:adj[src])
               {  if(x!=par)  // Condition to avoid going back to same node,and its only parent here
                 m=max(m,height(adj,x,src));  // Because there is only one path btw two nodes
               }
        return 1+m;
        
    }
    vector<int> findMinHeightTrees(int n, vector<vector<int>>& edges) { 
        
        vector<int>adj[n];
        for(int i=0;i<edges.size();i++)
        {
            adj[edges[i][0]].push_back(edges[i][1]);
            adj[edges[i][1]].push_back(edges[i][0]);
        }
        unordered_map<int,vector<int>>mp;
        int minn_height=INT_MAX;
        for(int i=0;i<n;i++)
        {
            int h=height(adj,i,-1);
            
            if(h<=minn_height)
            {
                minn_height=h;
                mp[minn_height].push_back(i);
            }
            
        }
        return mp[minn_height];
    }
};