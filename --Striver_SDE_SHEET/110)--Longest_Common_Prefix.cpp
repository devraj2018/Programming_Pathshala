class TrieNode
{	
    public:
    char val;
    vector<TrieNode*> child;
    int childCount;
    bool endOfWord;

    TrieNode(char val)
    {
        this->val = val;
        child.resize(26, NULL);
        childCount = 0;
        endOfWord = false;
    }

    ~TrieNode()
    {
        for(int i = 0; i < 26; i++)
        {
            if(child[i] != NULL)
            {
                delete child[i];
            }
        }
    }
};
    
void insert(TrieNode* root, string &word)
{
    TrieNode* cur = root;

    for(int idx = 0; idx < word.size(); ++idx)
    {   
        int diff = word[idx] - 'a';
         if (cur->child[diff] == NULL)
        {
            cur->child[diff] = new TrieNode(word[idx]);
            cur->childCount += 1;
        }

        cur = cur->child[diff];
    }
   cur->endOfWord = true;    
}

string longestCommonPrefix(vector<string> &arr, int n)
{
    
    TrieNode* root = new TrieNode(' ');

     for(int i = 0; i < arr.size(); i++)
      {
        string word = arr[i];
        insert(root, word);
      }

     string answer = "";

   
    string prefix = arr[0];

    for(int idx = 0; idx < prefix.size(); idx++)
    {
        
        if (root->childCount == 1)
        {
            answer += prefix[idx];
            int diff = prefix[idx] - 'a';
            root = root->child[diff];
        }
        else
        {
            break;
        }
        
       
        if (root->endOfWord)
        {
            break;
        }
    }
    
    delete root;
    
    return answer;
}

======================================================================================
===============================    Using Binary Search =============================
======================================================================================

#include<bits/stdc++.h>
bool isCommon(vector<string> &arr, string &prefix, int length, int n)
{
    for(int idx = 0; idx < length; ++idx)
    {  for(int index = 0; index < n; index++)
        {   if (arr[index][idx] != prefix[idx]) return false;
        }
    }
    return true; 
}

string longestCommonPrefix(vector<string> &arr, int n)
{
     
    string prefix = "";
    int minLength = INT_MAX;

    for(int index = 0;index < n; ++index)
      {
        if (arr[index].size() < minLength)
         {
            minLength = arr[index].size();
            prefix = arr[index];
         }
      }

    int start = 0;
    int end = minLength;
    int mid;

    while (start <= end)
       {   
          mid = (start + end) / 2;
          if (isCommon(arr, prefix, mid, n)) start = mid + 1;
          else end = mid - 1;
        }

    mid = (start + end) / 2;
    string answer = prefix.substr(0, mid);
    return answer;
}
