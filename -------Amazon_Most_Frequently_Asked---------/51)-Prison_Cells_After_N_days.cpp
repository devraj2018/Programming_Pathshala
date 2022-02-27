class Solution {
public:
    vector<int> prisonAfterNDays(vector<int>& nums, int n) {
    
        vector<int>res=nums;
        n=(n-1)%14 +1;
        res[0]=0;
        res[7]=0;
        
        for(int i=1;i<=n;i++)
            {
              for(int j=1;j<=6;j++)
                 {
                    if(nums[j-1]== 0 && nums[j+1]==0) res[j]=1;
                    else if(nums[j-1]== 1 && nums[j+1]==1) res[j]=1;
                    else res[j]=0;
                 }
            nums=res;
         }
        return res;
     }
};