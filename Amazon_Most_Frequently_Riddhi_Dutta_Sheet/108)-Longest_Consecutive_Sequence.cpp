========================================================================================================
============== ++Approach 1++ Simple sort then check  O(nlogn)Time and O(1)Space =======================
========================================================================================================



========================================================================================================
============== ++Approach 2++ Using Hashmap  O(n)Time and O(n)Space ====================================
========================================================================================================
class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        
        unordered_map<int,int>mp;
        for(auto x:nums) mp[x]++;
        int maxx=0;
        for(int i=0;i<nums.size();i++)
        {
            if(mp[nums[i]]==0) continue;
            
            int curr=nums[i];
            mp[curr]=0;
            int count=1;
            int left=curr,right=curr;
            while(true)
            {
                if(mp.find(right+1)!=mp.end() && mp[right+1]>0)
                {   mp[right+1]=0;
                    count++;
                    right++;
                }
                else
                {
                    break;
                }
            }
            while(true)
            {
                if(mp.find(left-1)!=mp.end() && mp[left-1]>0)
                {   mp[left-1]=0;
                 
                    count++;
                    left--;
                }
                else
                {
                    break;
                }
            }
            
            maxx=max(maxx,count);
           
        }
        return maxx;
        
    }
};