class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& nums, int tar) {
     
         
         vector<vector<int>>res;
         if(nums.size()<4) return res;
         sort(nums.begin(),nums.end());
         int n=nums.size();
         long long target=(long long)tar;
         for(int l=0;l<n-3;l++)
           {
               for(int i=l+1;i<n-2;i++)
                    {
                         int j=i+1,k=n-1;
            
                         while(j<k)
                            {
                           long long sum= (long long)nums[l]+(long long)nums[i]+(long long)nums[j]+(long long)nums[k];
                              if(sum>target) k--;
                              else if(sum<target) j++;
                              else
                                {
                                     res.push_back({nums[l],nums[i],nums[j],nums[k]});
                     
                                     int first=nums[j],second=nums[k];
                                     
                                     while(j<k && nums[j]==first) j++;
                                     while(j<k && nums[k]==second) k--;
                                }
                 
                           }
           
                     while(i<n-2 && nums[i]==nums[i+1]) i++;
            
                     }
              while(l<n-3 && nums[l]==nums[l+1]) l++;
            }
        return res;
        
    }
};