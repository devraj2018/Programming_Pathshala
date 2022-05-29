class Solution {
public:
    int findJudge(int n, vector<vector<int>>& trust) {
        vector<int>Indegree(n+1),Outdegree(n+1);
        
        for(int i=0;i<trust.size();i++)
        {
            Outdegree[trust[i][0]]++;
            Indegree[trust[i][1]]++;
        }
        
        for(int i=1;i<=n;i++)
        {
            if(Indegree[i]==n-1 && Outdegree[i]==0) return i;
            
        }
        return -1;
    }
};