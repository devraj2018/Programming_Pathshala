class Solution {
public:
    long long numberOfWeeks(vector<int>& milestones) {
        
        int max_milestone=*max_element(milestones.begin(),milestones.end());
        long long total=0;
        for(auto x:milestones) total+=x;
        long long remaining=total-max_milestone;
        
        
        if(remaining >=max_milestone) return total;     
        
        return 2*remaining+1;
        
    }
};