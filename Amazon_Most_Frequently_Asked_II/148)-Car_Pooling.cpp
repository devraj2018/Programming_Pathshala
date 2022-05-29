class Solution {
public:
    bool carPooling(vector<vector<int>>& trips, int capacity) {
      int arr[1001]={0};
      for(int i=0;i<trips.size();i++)
        {
           arr[trips[i][1]]+=trips[i][0];
           arr[trips[i][2]]-=trips[i][0];
          
        }
        for(int i=0;i<=1000;i++)
        {
            capacity-=arr[i];
            
            if(capacity<0)
             return false;
            
        }
        return true;
    }
};