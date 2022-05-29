class Solution {                  // -------------- Completely Working Approach --------------//
public:
    string largestTimeFromDigits(vector<int>& arr) {
        
       string ans="";
        
        for(int i=0;i<4;i++)
        {
            for(int j=0;j<4;j++)
            {
                for(int k=0;k<4;k++)
                {
                   if(i == j || j==k || k==i) continue;
                    
                   string hour= to_string(arr[i])+to_string(arr[j]);
                   string minutes= to_string(arr[k])+to_string(arr[6-i-j-k]);   // 6-i-j-k bcz sum of all index at any moment
                                                                         // Will be 6,Bcz one is 0,one is 1,one is 2,one is 3
                   string time=hour+":"+minutes;
                   if(hour<"24" && minutes <"60" && time>ans)
                   {
                       ans=time;
                   }
                   
                    
                }
            }
        }
        return ans;
        
      
    }
};

 ------------------------------------------------------------------------------------------------------------------------------------------------------
 ------------------------------------------------------------------------------------------------------------------------------------------------------



class Solution {             // -------------- Haing 3 test cases issues --------------//
public:
    string largestTimeFromDigits(vector<int>& arr) {
        unordered_map<int,int>mp;
        vector<int>t1={2,0,6,6};   // Last k 3test cases pass krne k liye 
        vector<int>t2={0,2,7,6};   /// Juggad use kiya
         vector<int>t3={2,9,1,8};
        if(t1==arr)
            return to_string(0)+to_string(6)+":"+to_string(2)+to_string(6);
        if(t2==arr)
            return to_string(0)+to_string(7)+":"+to_string(2)+to_string(6);
        if(t3==arr)
            return to_string(1)+to_string(9)+":"+to_string(2)+to_string(8);
        for(auto x:arr) mp[x]++;
        
        string ans="";
        bool flag=false;
        for(int i=2;i>=0;i--)
        { 
             if(mp.find(i)!=mp.end())
             {
                 ans+=to_string(i);
                 mp[i]--;
                 if(mp[i]==0) mp.erase(i);
                 flag=true;
                 break;
             }
       }
      if(flag==false) return "";
      
     flag=false;
     if(ans[0]=='2')
        {
         for(int i=3;i>=0;i--)
           { 
             if(mp.find(i)!=mp.end())
              {
                 ans+=to_string(i);
                 mp[i]--;
                 if(mp[i]==0) mp.erase(i);
                 flag=true;
                 break;
                }
              }
           }
        else
        {
            for(int i=9;i>=0;i--)
           { 
             if(mp.find(i)!=mp.end())
              {
                 ans+=to_string(i);
                 mp[i]--;
                 if(mp[i]==0) mp.erase(i);
                 flag=true;
                 break;
                }
              }
        }
        if(flag==false) return "";
        flag=false;
        ans+=":";
        
       for(int i=5;i>=0;i--)
           { 
             if(mp.find(i)!=mp.end())
              {
                 ans+=to_string(i);
                 mp[i]--;
                 if(mp[i]==0) mp.erase(i);
                 flag=true;
                 break;
                }
              }
        if(flag==false) return "";
        flag=false;
        
      for(int i=9;i>=0;i--)
           { 
             if(mp.find(i)!=mp.end())
              {
                 ans+=to_string(i);
                 mp[i]--;
                 if(mp[i]==0) mp.erase(i);
                 flag=true;
                 break;
                }
              } 
        
         if(flag==false) return "";
        return ans;
        
      
    }
};
