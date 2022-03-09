class Solution {
public:
    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
        
        if(beginWord == endWord) return 0;
        
        unordered_set<string> valid;
        unordered_set<string> visited;
        
        for(auto s:wordList) valid.insert(s);
        
        queue<pair<string,int>>q;
        q.push({beginWord,1});
        visited.insert(beginWord);
        
        while(!q.empty())
        {
             string currWord=q.front().first;
             int time = q.front().second;
            
             q.pop();
            
             if(currWord == endWord) return time;
             
             for(int i=0;i<currWord.length();i++)
             {
                  char ch= currWord[i];
                  
                  for(int j=0;j<26;j++)
                  {
                       currWord[i]=j+'a';
                       
                       if(valid.find(currWord)!= valid.end() && visited.find(currWord)==visited.end())
                           {
                              q.push({currWord,time+1});
                              visited.insert(currWord);
                             // cout<<currWord<<" -> ";
                       
                           }
                      
                  }
                 currWord[i]=ch;
            }
        }
        return 0;
        
    }
};