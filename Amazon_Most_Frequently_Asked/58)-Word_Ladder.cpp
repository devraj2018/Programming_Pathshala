class Solution {
public:
    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
        
        unordered_map<string,int>valid;
        unordered_map<string,int>visited;
        
        for(auto s:wordList) valid[s]++;
        
         visited[beginWord]++;
         queue<pair<string,int>>q;
         q.push({beginWord,0});
        
         int res=0;
         while(!q.empty())
            {
               string curr=q.front().first;
               int time=q.front().second;
               q.pop();

               if(curr== endWord) return time+1;
            
               for(int i=0;i<curr.length();i++)
                   {
                      char ch= curr[i];
                      string news=curr;
                 
                      for(int j=0;j<26;j++)
                        {
                           news[i]=j+'a';
                           if(valid.find(news)!=valid.end() && visited.find(news)==visited.end())
                              {
                                  visited[news]++;
                                  q.push({news,time+1});
                              }
                        }
                      curr[i]=ch;
                   }
            }
        return 0;
     }
};


-------------------- Same Just Without Taking pair ----------------------------

class Solution {
public:
    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
        
        unordered_map<string,int>validWord;  // To check word is present or not
        for(auto s:wordList) validWord[s]++;
        
        unordered_set<string>visited;      
        
        if(validWord.find(endWord)==validWord.end()) return 0;  // If end Word is not present
        if(beginWord==endWord) return 0;    // Both are same word
        
        queue<string>q;
        q.push(beginWord);
        visited.insert(beginWord);
        int ans=0;
        
        while(!q.empty())
        {
            int size=q.size();
            ans++;
            for(int i=0;i<size;i++)
            {
                string curr= q.front();
                q.pop();
                
                if(curr==endWord) return ans;      // If we found the word
                
                for(int j=0;j<curr.length();j++)
                {    char x=curr[j];              // Store to backtrack
                    
                     for(int k=0;k<26;k++)
                            {
                               curr[j]='a'+k;     // Change jth index charcater with a to z
                               if(validWord.find(curr)!=validWord.end() && visited.find(curr)==visited.end())
                                 {
                                    q.push(curr);
                                    visited.insert(curr);
                                 }
                            }
                     curr[j]=x;
                }
             }
         }
        return 0;
        
    }
};
