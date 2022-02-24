/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> neighbors;
    Node() {
        val = 0;
        neighbors = vector<Node*>();
    }
    Node(int _val) {
        val = _val;
        neighbors = vector<Node*>();
    }
    Node(int _val, vector<Node*> _neighbors) {
        val = _val;
        neighbors = _neighbors;
    }
};
*/

class Solution {
public:
    unordered_set<Node*>visited;
    unordered_map<Node*,Node*>mp;
     
    void dfs(Node* node)
       {
          visited.insert(node);
          mp[node]=new Node(node->val);
        
          for(auto adjacent: node->neighbors)
            {
                if(visited.find(adjacent)==visited.end())
                  {
                   dfs(adjacent);
                 }
             }
      }
   
    Node* cloneGraph(Node* node) {
        if(node==NULL) return NULL;
        
        dfs(node);
     
        for(auto x:mp)
          {
             for(auto y:x.first->neighbors)
               {
                 x.second->neighbors.push_back(mp[y]);
               }
          }
        return mp[node];
     }
};