class Solution {
public:
    int jump(vector<int>& nums) {
        int left=0,right=0,maxReachable=0;
        int count=0;
        int n=nums.size();
        while(right<n-1)
        {
            for(int i=left;i<=right;i++)
              maxReachable=max(maxReachable,i+nums[i]);
            
            count++;
            left=right+1;
            right=maxReachable;
            
            if(left>right) return -1;    // if not possible to reach end
            
        }
        return count;
        
    }
};