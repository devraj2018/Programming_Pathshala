class Solution {
    struct comp{
        bool operator()(pair<int,string>&a,pair<int,string>&b)
        {
            if(a.first>b.first) return true;
            if(a.first<b.first) return false;
            
            return a.second<b.second;
            
        }
    };
public:
    vector<string> topKFrequent(vector<string>& words, int k) {
        
        unordered_map<string,int>mp;
        priority_queue<pair<int,string>,vector<pair<int,string>>,comp>pq;
        
        for(auto &s:words) mp[s]++;
        
        vector<pair<int,string>>temp;
        
        for(auto m:mp) temp.push_back({m.second,m.first});
        
        for(int i=0;i<temp.size();i++)
        {
            if(pq.size()<k)
            {
                pq.push({temp[i].first,temp[i].second});
            }
            else if(pq.size()>=k)
            {
                 if(temp[i].first> pq.top().first)
                    pq.push({temp[i].first,temp[i].second});
                 else if(temp[i].first==pq.top().first && temp[i].second<pq.top().second)
                    pq.push({temp[i].first,temp[i].second});
                
             }
            
             if(pq.size()>k) pq.pop();
            
        }
        vector<string> res;
        while(!pq.empty())
        {
            res.push_back(pq.top().second);
            pq.pop();
            
        }
        reverse(res.begin(),res.end());
        return res;
        
        
        
        
        
    }
};