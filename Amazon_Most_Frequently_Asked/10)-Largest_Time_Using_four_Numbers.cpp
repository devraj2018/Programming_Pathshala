class Solution {
public:
    string largestTimeFromDigits(vector<int>& arr) {
        string ans="";
        for(int i=0;i<4;i++)
        {
            for(int j=0;j<4;j++)
            {
                for(int k=0;k<4;k++)
                  {
                    int l= 6-(i+j+k);
                    if(i==j || i==k || j==k) continue;
                    
                    string hour= to_string(arr[i])+ to_string(arr[j]);
                    string minute= to_string(arr[k])+ to_string(arr[l]);
                    string time= hour+":"+minute;
                    
                    if(hour>="00" && hour<="23" && minute>="00" && minute<="59" && time>ans)
                    { ans=time;
                     }
                     
                }
            }
        }
        return ans;
        
    }
};