/*  For 3 numbers
   = a + b + c + ab + bc + ca + abc 
   = a + ac + b + bc + ab + abc + c + 1 - 1
   = a(1+c) + b(1+c) + ab(1+c) + c + 1 - 1
   = (a + b + ab + 1)(1+c) - 1 
   = (1+a) * (1+b) * (1+c) - 1  
*/
class Solution {
public:
    
    int Sum(vector<int>&arr) {    // For general for(i=0 to n) ans=ans*(arr[i]+1)  and at last Subtract 1 

        int n=arr.size();
        int ans=1;
        for(int i=0;i<n;i++)
        {
            ans = ans * (arr[i]+1);
        }

        return ans-1;
        
        
        
    }
};