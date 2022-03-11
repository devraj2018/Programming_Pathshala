 static bool comp(pair<int,int>&a,pair<int,int>&b)
    {
        if(a.first>b.first) return true;
        if(a.first<b.first) return false;
        
        return a.second<b.second;
       
    }
vector<int> sortByFrequency(vector<int>& nums){
	    unordered_map<int,int>mp,firstindex;
        for(int i=0;i<nums.size();i++) {
            mp[nums[i]]++;
            if(firstindex.find(nums[i])==firstindex.end())
                firstindex[nums[i]]=i;
          }
    
       vector<pair<int,int>> temp;
      
       for(auto x:mp) temp.push_back({x.second,firstindex[x.first]});
       
        sort(temp.begin(),temp.end(),comp);
        int n=nums.size();   
        vector<int>res(n);
        int k=0; 
        for(int i=0;i<temp.size();i++)
        {
              for(int j=0;j<temp[i].first;j++)
              {
                  res[k]=nums[temp[i].second];
                  k++;
              }
        }
        return res;
}