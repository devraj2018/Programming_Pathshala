class Solution {
public:
    int maxSum(vector<int>& nums1, vector<int>& nums2) {
       
        int n1=nums1.size();
        int n2=nums2.size();
        
        long long sum1=0,sum2=0;
        
        int i=0,j=0;
        
        while(i<n1 && j<n2)
        {
            if(nums1[i]<nums2[j])
            {
                sum1+=nums1[i];
                i++;
            }
            else if(nums2[j]<nums1[i])
            {
                sum2+=nums2[j];
                j++;
            }
            else
            {
               sum1+=nums1[i];
               sum2+=nums2[j];
                
               sum1=max(sum1,sum2);
               sum2=sum1;
                i++;j++;
            }
         }
        while(i<n1) sum1+=nums1[i++];
        while(j<n2) sum2+=nums2[j++];
        int mod=1e9+7;
        
        long long ans= max(sum1,sum2)%mod;
        return (int)ans;
    }
};