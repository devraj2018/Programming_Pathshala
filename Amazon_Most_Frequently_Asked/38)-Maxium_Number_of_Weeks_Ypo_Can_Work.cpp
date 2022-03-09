class Solution {
public:
    long long numberOfWeeks(vector<int>& milestones) {
        
        int max_no= *max_element(milestones.begin(),milestones.end());
        
        long long total=0;
        for(auto x:milestones)
         {
            total+= x;
         }
        
        long long remaining= total- max_no;
        if(remaining >= max_no ) return total;
        
        return 2*remaining+1;
        
        
    }
};