class Solution {
public:
    bool isPall(string curr,int s,int e)
    {
        while(s<=e)
        {
            if(curr[s]!=curr[e])
                return false;
            s++;e--;
        }
        return true;
    }
    vector<vector<int>> palindromePairs(vector<string>& words) {
        unordered_map<string,int>reverseStore;
        vector<vector<int>>res;
        map<pair<int,int>,bool> mp;
        for(int i=0;i<words.size();i++)
        {
            string s=words[i];
            reverse(s.begin(),s.end());
            reverseStore[s]=i;
        }
        
        for(int i=0;i<words.size();i++)
        {   int n=words[i].length();
            string curr=words[i];
             //To check empty prefix   or suffix  
             if((reverseStore.find("")!=reverseStore.end()) && reverseStore[""]!=i &&isPall(words[i],0,n-1)&&                       mp.find({i,reverseStore[""]})==mp.end() ) 
               {                                                             
               mp[{i,reverseStore[""]}]=true;
               mp[{reverseStore[""],i}]=true;
                 
               res.push_back({i,reverseStore[""]});
               res.push_back({reverseStore[""],i});
               } 
            string prefix="",suffix="";
             for(int j=0;j<n;j++) // For prefix check of all length from 1 length to n length
               {
                   prefix.push_back(words[i][j]);
                   if((reverseStore.find(prefix)!=reverseStore.end()) && reverseStore[prefix]!=i && isPall(curr,j+1,n-1)&& mp.find({i,reverseStore[prefix]})==mp.end())
                       {
                       // cout<<prefix<<" <-[Prefix] whole-> "<<curr<<" SUFFIX PART "<<words[reverseStore[prefix]]<<endl; //Debugging part
                        mp[{i,reverseStore[prefix]}]=true;
                        res.push_back({i,reverseStore[prefix]});
                       }
               }
         
           for(int j=n-1;j>=0;j--) // For suffix check of all length from 1 length to n length
               {
                 suffix = words[i][j]+suffix;
                 if((reverseStore.find(suffix)!=reverseStore.end()) && reverseStore[suffix]!=i && isPall(curr,0,j-1)&& mp.find({reverseStore[suffix],i})==mp.end())
                   {
                     //cout<<suffix<<" <-[suffix] whole-> "<<curr<<" PREFIX PART "<<words[reverseStore[suffix]]<<endl; //Debugging part
                     mp[{reverseStore[suffix],i}]=true;
                     res.push_back({reverseStore[suffix],i});
                  }
              }
            
        }
         
        return res;
        
       
    }
};
// --- Basic Brute Force--Gives TLE //
/*
class Solution {
public:
    bool isPall(string s)
    {
        int i=0,e=s.length()-1;
        while(i<=e)
        {
            if(s[i]!=s[e]) return false;
            i++;e--;
        }
      return true;  
     }
     
    vector<vector<int>> palindromePairs(vector<string>& words) {
        int n=words.size();
         vector<vector<int>>res;
        for(int i=0;i<n;i++)
        {
             for(int j=0;j<n;j++)
              {  string s=words[i]+words[j];
                 if( i!=j && isPall(s)) res.push_back({i,j});
                }
            
         }
        return res;
     }
};
*/