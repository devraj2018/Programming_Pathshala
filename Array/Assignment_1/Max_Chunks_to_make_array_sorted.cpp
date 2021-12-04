class Solution {
public:
    int maxChunksToSorted(vector<int>& arr) {
        int ans=0;
        int currsum=0;
        int indexsum=0;      
        int n=arr.size();
       for(int i=0;i<n;i++)
       { indexsum+=i;
         currsum+=arr[i];
        
         if(currsum==indexsum)
             ans++;
           
       }
        return ans;
    }
};