class Solution {
public:
    vector<vector<string>> findLadders(string beginWord, string endWord, vector<string>& wordList) {
        
         unordered_map<string,int>valid;
         for(auto &s:wordList) valid[s]++;
         
         vector<vector<string>>res;
         if(valid.find(endWord)==valid.end()) return res;
        
         queue<vector<string>>q;
         q.push({beginWord});
         
         while(!q.empty())
           {
               int size=q.size();
            
               for(int i=0;i<size;i++)
                   {
                       vector<string>temp=q.front();
                       q.pop();
                 
                       string curr_str=temp.back();
                       valid.erase(curr_str);   // To avoid infinite loop
                 
                       if(curr_str==endWord)   // Shortest Path found
                          {
                             res.push_back(temp);
                             for(int j=i+1;j<size;j++)
                               {
                                  vector<string>ans=q.front();
                                   q.pop();
                                   if(ans.back()==endWord) res.push_back(ans);
                               }
                           
                             return res;
                           }
                 
                     for(int i=0;i<curr_str.length();i++)
                       {
                           char backtrack=curr_str[i];
                     
                           for(int j=0;j<26;j++)
                             {
                                curr_str[i]=('a'+j);
                                if(valid.find(curr_str)!=valid.end())
                                  {
                                    temp.push_back(curr_str);
                                    q.push(temp);
                                    temp.pop_back();
                                  }
                         
                              }
                         curr_str[i]=backtrack;
                     
                        }
              }
             
            
            
        }
        return res;
        
       
    }
};