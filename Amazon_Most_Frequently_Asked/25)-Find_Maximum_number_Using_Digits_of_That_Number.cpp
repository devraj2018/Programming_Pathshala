class Solution {
  public:
    string findMax(string N) {
       vector<int>freq(10,0);
       
       for(int i=0;i<N.length();i++)
       {
           freq[N[i]-'0']++;
       }
       string ans="";
       
       for(int i=9;i>=0;i--)
       {
            if(freq[i]==0) continue;
            
            int x=freq[i];
            while(x--)
            {
                ans.push_back(i+'0');
            }
           
           
       }
        return ans;
    }
};