class Solution {
    struct comp{
        public:
        bool operator()(const pair<int,string>a,const pair<int,string>b)
        {    if(a.first<b.first) return true;
             if(a.first>b.first) return false;
             return a.second>b.second;
        }
      };
public:
   
    vector<string> topKFrequent(vector<string>& words, int k) {
        
        unordered_map<string,int>mp;
        for(auto s:words)  mp[s]++;
            
        priority_queue<pair<int,string>,vector<pair<int,string>>,comp>pq;
        for(auto x:mp) pq.push({x.second,x.first});
            
         vector<string>res;
         while(k--)
          {
            string temp=pq.top().second;
            pq.pop();
            res.push_back(temp);
          }
        return res;
        
    }
};