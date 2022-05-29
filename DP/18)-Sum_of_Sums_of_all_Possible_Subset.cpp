/*
Naive Approach: A naive approach is to find all the subsets using power set and then summate
                all the possible subsets to get the answer. 
                Time Complexity: O(2N)
Efficient Approach: An efficient approach is to solve the problem using observation. 
                    If we write all the subsequences, a common point of observation is that
                    each number appears 2(N – 1) times in a subset and hence will lead to the 2(N-1) 
                    as the contribution to the sum. Iterate through the array and add (arr[i] * 2N-1) to the answer. 

*/
class Solution {
public:
    
    int Sum(vector<int>&arr) {    // For general for(i=0 to n) ans=ans*(arr[i]+1)  and at last Subtract 1 

        int n=arr.size();
        int ans=0;
        int times=(1<<(n-1));
        for(int i=0;i<n;i++)
        {
            
            ans += arr[i]*times;
        }

        return ans;
        
        
    }
};