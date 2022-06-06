class Solution {
public:
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        
        vector<int>Indegree(numCourses,0);
        vector<int>adj[numCourses];
        
        for(int i=0;i<prerequisites.size();i++)
        {
            adj[prerequisites[i][1]].push_back(prerequisites[i][0]);
            Indegree[prerequisites[i][0]]++;
            
        }
        queue<int>q;
        for(int i=0;i<numCourses;i++)
        {
            if(Indegree[i]==0) q.push(i);
        }
        vector<int>res;
        
        while(!q.empty())
        {
            int curr=q.front();
            q.pop();
            res.push_back(curr);
            
            for(auto child:adj[curr])
            {
                
                Indegree[child]--;
                 if(Indegree[child]==0) q.push(child);
                
            }
            
        }
        
        return res.size()==numCourses;
        
    }
};