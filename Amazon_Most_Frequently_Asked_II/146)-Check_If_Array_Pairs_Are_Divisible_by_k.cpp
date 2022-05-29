class Solution {
public:
    bool canArrange(vector<int>& arr, int k) {
        int n=arr.size();
        unordered_map<int,int>mp;
        for(int i=0;i<n;i++) mp[(arr[i]%k+k)%k]++;
        
        if(mp[0]%2!=0) return false;
        
        for(int i=0;i<n;i++)
        {
            int rem=(arr[i]%k+k)%k;
            
            if(rem==0 && mp[0]%2!=0) return false;
            if(rem!=0 && mp[rem]!=mp[k-rem]) return false;
            
            
        }
        return true;
    }
};