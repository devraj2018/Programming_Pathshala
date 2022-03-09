class Solution {
public:
    string largestTimeFromDigits(vector<int>& arr) {
        
        unordered_map<int,int>mp;
         
        for(auto x:arr) mp[x]++;
        string ans="";
        
        bool flag=false;
        for(int i=2;i>=0;i--)
        {  if(mp.find(i)!=mp.end() && mp[i]!=0)
             {   ans+= to_string(i);
                 flag=true;
                 mp[i]--;
                 break;
             }
         }
        // cout<<"11"<<endl;
        if(flag==false) return "";
        flag=false;
        if(ans[0]=='2')
        {
            for(int i=3;i>=0;i--)
            {
                if(mp.find(i)!=mp.end() && mp[i]!=0)
                 {   ans+= to_string(i);
                     flag=true;
                     mp[i]--;
                     break;
                  }
            }
        }
        else
        {
             for(int i=9;i>=0;i--)
            {
                if(mp.find(i)!=mp.end() && mp[i]!=0)
                 {   ans+= to_string(i);
                     flag=true;
                     mp[i]--;
                     break;
                  }
            }
        }
        // cout<<"11"<<endl;
        if(flag==false) return "";
        
        ans+=":";
        flag=false;
         for(int i=5;i>=0;i--)
            {
                if(mp.find(i)!=mp.end() && mp[i]!=0)
                 {   ans+= to_string(i);
                     flag=true;
                     mp[i]--;
                     break;
                  }
            }
        // cout<<"11"<<endl;
        //     cout<<ans<<endl;
          if(flag==false) return "";
         flag=false;
         for(int i=9;i>=0;i--)
            {
                if(mp.find(i)!=mp.end() && mp[i]!=0)
                 {   ans+= to_string(i);
                     flag=true;
                     mp[i]--;
                     break;
                  }
            }
        // cout<<"11"<<endl;
        // cout<<ans<<endl;
        if(flag==false) return "";
        
        return ans;
        
     
    }
};