class Solution
{
	public:
	//Function to return list containing vertices in Topological order. 
	vector<int> topoSort(int V, vector<int> adj[]) 
	{
	    vector<int>res;
	    vector<int>Indegree(V,0);
	    for(int i=0;i<V;i++)
	    {
	        for(auto x:adj[i])
	         {
	              Indegree[x]++;
	          }
	    }
	    queue<int>q;
	    for(int i=0;i<V;i++)
	    {
	        if(Indegree[i]==0)
	         q.push(i);
	    }
	    while(!q.empty())
	    {
			
	          int curr=q.front();
	          q.pop();
	          res.push_back(curr);
	          
	          for(auto x:adj[curr])
	          {
	               Indegree[x]--;
	               if(Indegree[x]==0)
	                  q.push(x);
	          }
	           
	     }
	     return res;
	}