class Solution {
public:
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
        
        int final_remaining=0;
        int curr_remaining=0;
        int start=0;
        
        int n=gas.size();
        
        for(int i=0;i<n;i++)
        {
             final_remaining+= gas[i]-cost[i];
             curr_remaining+= gas[i]-cost[i];
            
             if(curr_remaining<0)
             {
                 start=i+1;
                 curr_remaining=0;
             }
             
       }
        if(final_remaining<0) return -1;
        return start;
        
    }
};