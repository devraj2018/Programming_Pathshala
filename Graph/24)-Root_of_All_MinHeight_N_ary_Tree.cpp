class Solution {
public:
    vector<int> findMinHeightTrees(int n, vector<vector<int>>& edges) {
        
        if(edges.size()==0) {
            
            vector<int>temp;
            for(int i=0;i<n;i++) temp.push_back(i);
            return temp;
        }
        vector<int>adj[n];
        vector<int>Indegree(n,0);
        for(int i=0;i<edges.size();i++)
        {
             adj[edges[i][0]].push_back(edges[i][1]);
             adj[edges[i][1]].push_back(edges[i][0]);
             Indegree[edges[i][0]]++;
             Indegree[edges[i][1]]++;
        }
        queue<int>q;
        for(int i=0;i<n;i++)
        {
             if(Indegree[i]==1) q.push(i);
        }
        vector<int>res;
        
        while(!q.empty())
        {
            res.clear();
            int size=q.size();
            for(int i=0;i<size;i++)
            {
                int curr=q.front();q.pop();
                
                res.push_back(curr);
                
                for(auto child:adj[curr])
                {
                    Indegree[child]--;
                    if(Indegree[child]==1) q.push(child);
                }
            }
        }
        return res;   // Answer in last level of queue 
    } 
};