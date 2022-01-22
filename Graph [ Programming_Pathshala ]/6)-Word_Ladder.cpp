class Solution {
public:
    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
        queue<pair<string,int>>q;
        q.push({beginWord,1});
        unordered_set<string> vis;
        unordered_set<string> valid;
        for(auto x:wordList)
        {
            valid.insert(x);
        }
        vis.insert(beginWord); 
       while(!q.empty())   // For every element in queue we have to do only O(26*length_of_string) which is much smaller than
            {              // Checking current string with all other string ,it takes O(no_of_string * length_of_string)
                string curr=q.front().first;
                int dis=q.front().second;
                q.pop();
            
                if(curr== endWord) return dis;
               
                for(int i=0;i<curr.length();i++)   //  Replace every character with a to z and check if is valid and not visited
                   {    char prev=curr[i];
                        for(int j=0;j<26;j++)     // It will greately reduces our time complexity 
                           {   curr[i]=j+'a';
                                if(valid.find(curr)!=valid.end() && vis.find(curr)==vis.end())
                                   {  q.push({curr,dis+1});
                                      vis.insert(curr);
                             
                                   }
                          }
                       curr[i]=prev;
                  
                  }
             
           }
        return 0;
        
    }
};
//------------This will give TLE---------//
/*
class Solution {
public:
    bool isValid(string s1,string s2)
    {
         int count=0;
         for(int i=0;i<s1.length();i++)
         {
             if(s1[i]!=s2[i])
                 count++;
         }
         if(count==1)
             return true;
         return false;
    }
    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
        
        queue<pair<string,int>>q;
        q.push({beginWord,1});
        unordered_set<string> vis;
        vis.insert(beginWord);
        
        while(!q.empty())
        {  
              string curr=q.front().first;
              int dis=q.front().second;
              q.pop();
            
              if(curr== endWord)
                  return dis;
             
              for(int i=0;i<wordList.size();i++)
              {
                   if(isValid(curr,wordList[i]) && vis.find(wordList[i])==vis.end())
                   {
                       q.push({wordList[i],dis+1});
                       vis.insert(wordList[i]);
                   }
                  
              }
             
        }
        return 0;
            
    }
};
*/