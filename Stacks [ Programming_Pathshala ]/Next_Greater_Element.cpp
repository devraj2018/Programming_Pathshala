class Solution
{
    public:
    //Function to find the next greater element for each element of the array.
    vector<long long> nextLargerElement(vector<long long> arr, int n){
       vector<long long> res(n,-1);
       stack<long long >s;
       s.push(arr[n-1]);
       for(int i=n-2;i>=0;i--)
       {   while(!s.empty() && s.top() <= arr[i])  s.pop();
            if(!s.empty()) res[i]=s.top();
            
            s.push(arr[i]); 
           
       }
       return res;
    }
};