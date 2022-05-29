class Solution {
public:
    int jump(vector<int>& nums) {
        
        int n=nums.size();
        int start=0,end=0;
        int maxReachable=0;
        int moves=0;
        while(end<n-1)
        {
             for(int i=start;i<=end;i++)
              {
                 maxReachable=max(maxReachable,i+nums[i]);
              }
            
             start=end+1;
             end=maxReachable;
            
             if(start>end) return -1;
             moves++;
        }
        return moves;
        
    }
};