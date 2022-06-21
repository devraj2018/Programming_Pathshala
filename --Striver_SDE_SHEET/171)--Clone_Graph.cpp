/***************************************************************************

	Class for graph node is as follows:

	class graphNode
	{
		public:
    		int data;
    	vector<graphNode *> neighbours;
    	graphNode()
    	{
        	data = 0;
        	neighbours = vector<graphNode *>();
    	}

    	graphNode(int val)
    	{
        	data = val;
        	neighbours = vector<graphNode *>();
    	}

    	graphNode(int val, vector<graphNode *> neighbours)
    	{
        	data = val;
        	this->neighbours = neighbours;
    	}
	};

******************************************************************************/
#include<bits/stdc++.h>
void dfs(graphNode *node, unordered_set<graphNode*>&visited,unordered_map<graphNode*,graphNode*>&mp)
{
     
    visited.insert(node);
    graphNode* newnode=new graphNode(node->data);
    
    mp[node]=newnode;
    
    for(auto adj: node->neighbours )
    {
        if(visited.find(adj)==visited.end())
        {
            dfs(adj,visited,mp);
        }
     }
    
    
}
graphNode *cloneGraph(graphNode *node)
{
    unordered_set<graphNode*>visited;
    unordered_map<graphNode*,graphNode*>mp;
    
    if(node==NULL) return NULL;
    
     graphNode* newHead=NULL;
     dfs(node,visited,mp);
     newHead= mp[node];
    
    for(auto n:mp)
    {
        for(auto n2:n.first->neighbours)
            n.second->neighbours.push_back(mp[n2]);
    }
    return newHead;
    
}