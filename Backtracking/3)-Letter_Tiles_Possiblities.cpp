class Solution {
public:
    int count=0;
    unordered_map<char,int>freq;
    
    vector<char> temp;
    void helper(string digits,int curr_I=0)
    { 
         if(curr_I==digits.length()) return;
        
        
        for(int i=0;i<digits.length();i++)
        {     
             if(i+1<digits.length() && digits[i]==digits[i+1]) continue;
             if(freq[digits[i]]==0) continue;
             count++;
              
              temp.push_back(digits[i]);
              freq[digits[i]]--;

              helper(digits,curr_I+1);

              freq[digits[i]]++;
              temp.pop_back();
          }
      }
    
    int numTilePossibilities(string tiles) {
        for(auto x:tiles)  freq[x]++;
        sort(tiles.begin(),tiles.end());
        helper(tiles);
        return count;
        
    }
};