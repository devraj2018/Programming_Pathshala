class Solution {
public:
    bool carPooling(vector<vector<int>>& trips, int capacity) {
        
        vector<int>line(1001,0);
        
        for(auto t:trips)
        {
            line[t[1]]+=t[0];
            line[t[2]]-=t[0];
        }
        for(int i=0;i<=1000;i++)
        {
             capacity-= line[i];
            
             if(capacity<0) return false;
            
         }
        return true;
        
    }
};