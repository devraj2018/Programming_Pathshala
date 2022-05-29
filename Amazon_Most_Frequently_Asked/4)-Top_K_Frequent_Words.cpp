class Solution {
    struct comp{
        
        public:
          bool operator()(const pair<int,string>&a,const pair<int,string>&b)
          {
               if(a.first<b.first) return true;
               if(a.first>b.first) return false;
              
               return (a.second >= b.second);
              
          }
          
        
    };
public:
    vector<string> topKFrequent(vector<string>& words, int k) {
        
        unordered_map<string,int>mp;
        for(auto s:words) mp[s]++;
        
        vector<pair<int,string>>temp;
        for(auto x:mp) temp.push_back({x.second,x.first});
        
        priority_queue<pair<int,string>,vector<pair<int,string>>,comp>pq(temp.begin(),temp.end());
        
        vector<string>res;
        while(k--)
        {
            res.push_back(pq.top().second);
            pq.pop();
        }
        return res;
        
    }
};