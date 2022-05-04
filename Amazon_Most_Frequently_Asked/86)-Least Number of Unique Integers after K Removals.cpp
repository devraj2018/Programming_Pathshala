class Solution {
public:
    int findLeastNumOfUniqueInts(vector<int>& arr, int k) {
        unordered_map<int,int>mp;
        for(int i=0;i<arr.size();i++) mp[arr[i]]++;
        
        vector<pair<int,int>>temp;
        for(auto m:mp)
        {
            temp.push_back({m.second,m.first});
        }
        sort(temp.begin(),temp.end());
        
        int i=0,n=temp.size();
       for( i=0;i<n;i++)
        {
            if(temp[i].first<=k)
            {
                k-=temp[i].first;
                mp.erase(temp[i].second);
            }
           else
           {
               break;
           }
            
        }
        return mp.size();
        
        
    }
};