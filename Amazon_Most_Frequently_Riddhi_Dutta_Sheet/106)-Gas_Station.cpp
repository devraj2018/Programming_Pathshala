class Solution {
public:
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
        
        int total_remaining=0;
        int curr_remaining=0;
        
        int start=0;
        
        for(int i=0;i<gas.size();i++)
        {
            total_remaining+= gas[i]-cost[i];
            curr_remaining+= gas[i]-cost[i];
            
            if(curr_remaining<0)
               { curr_remaining=0;
                 start=i+1;
               }
            
        }
        
        if(total_remaining<0) return -1;
        return start;
        
    }
};