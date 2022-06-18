---------------------------------------------------------------------------------------------------
----------------+++++++++++++++++    Using Trie +++++++------------------------------------------
---------------------------------------------------------------------------------------------------

class Node  {
   public:
   Node *chars[26];
   int wc = 0, pc = 0;
   bool end = false;
   
   bool has(char c) {
       return chars[c - 'a'] != NULL;
   }
   
   Node* get(char c) {
       return chars[c - 'a'];
   }
   
   void put(char c) {
       chars[c - 'a'] = new Node();
   }
};

class Trie {
private:
   Node *root;
   int count = 0;
public:
   Trie() {
       root = new Node();
       count = 0;
   }
   
   Node* insertOpt(string word) {
       Node *node = root;
       
       for(int i=0;i<word.length();++i) {
           if(!node->has(word[i])) {
               node->put(word[i]);
               count++;
           }
           node = node->get(word[i]);
       }
       node->end = true;
       return node;
   }
   
   int getCount() {
       return count;
   }
};

int distinctSubstring(string &word) {
   Trie trie;
   int len = word.length();
   
   for(int i=0;i<len;++i) {
       trie.insertOpt(word.substr(i, len - i));
   }
   
   return trie.getCount();
}





---------------------------------------------------------------------------------------------------
-------------+++++++++++++++++     Brute Force By checking all substring +++++++-------------------
---------------------------------------------------------------------------------------------------
#include<bits/stdc++.h>
int distinctSubstring(string &word) {
    unordered_map<string,int>mp;
    for(int i=0;i<word.size();i++)
    {      string curr="";
            for(int j=i;j<word.size();j++)
            {
                curr+=word[j];
                mp[curr]++;
            }
    }
    return mp.size();
}
