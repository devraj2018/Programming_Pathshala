class Solution
{   //If we use map rather than unordered map , we end up getting (nlongn)Time complexity 
    // I used unordered map and keep track of what's the maxx horizontal distance in left side 
    // --As well sa on right side

    //So we eun loop from minn to maxx we get all our unorderd map keys 
    //And our time complexity will be O(n) [not nlogn]
    public:
    //Function to find the vertical order traversal of Binary Tree.
    vector<int> verticalOrder(Node *root)
    { int maxx=INT_MIN,minn=INT_MAX;
       unordered_map<int,vector<int>>mp;   
       vector<int>res;
       if(root==NULL) return res;
       queue<pair<Node*,int>>q;
       q.push({root,0});
       while(!q.empty())
       {
             Node* curr=q.front().first;
             int hd=q.front().second;
             q.pop();
             maxx=max(maxx,hd);
             minn=min(minn,hd);
             
             mp[hd].push_back(curr->data);
             
             if(curr->left) q.push({curr->left,hd-1});
             if(curr->right) q.push({curr->right,hd+1});
           
       }
       for(int i=minn;i<=maxx;i++)
       {
            for(auto ele:mp[i])
              res.push_back(ele);
           
       }
       return res;
    }
};

// Leetcode -Variant-->In this Question, ELement at same row and col (stored in sorted order)
//Also there may be duplicate --So use multiset to tackle duplicate ele

class Solution {  // With unordered_map we get O(n)Complexity
public:
    vector<vector<int>> verticalTraversal(TreeNode* root) {
        
       vector<vector<int>>res;
       if(root==NULL) return res;
        
       queue<pair<TreeNode*,int>>q;
       unordered_map<int,vector<int>>mp;
  
       int maxx=INT_MIN,minn=INT_MAX;    // To get rid of map and used unorderd_map  
        q.push({root,0});
        while(!q.empty())
        {   int size=q.size();             // Also remember we used multiset here so it will effect time Complexity
             multiset<pair<int,int>>ms;
             for(int i=1;i<=size;i++)
               {
               TreeNode* curr=q.front().first;
               int hd=q.front().second;
               q.pop();
               maxx=max(maxx,hd); minn=min(minn,hd);
               
               ms.insert({curr->val,hd});
               if(curr->left) q.push({curr->left,hd-1});
               if(curr->right) q.push({curr->right,hd+1});
               
              }
             for(auto x:ms)   mp[x.second].push_back(x.first);
         }
        
        for(int i=minn;i<=maxx;i++)  res.push_back(mp[i]);
     return res;
        
    }
};
