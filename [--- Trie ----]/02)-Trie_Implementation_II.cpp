struct Node{
    Node* link[26];
    int endWith=0;
    int cntPrefix=0;
    
    bool containsKey(char ch)  return link[ch-'a']!=NULL;
     
     
};
class Trie{
        Node* root;
     public:

      Trie(){  root=new Node();
       }

    void insert(string &word){
         Node* node=root;
         for(int i=0;i<word.length();i++)
             {
                if(!node->containsKey(word[i])) node->link[word[i]-'a']=new Node();
             
                node=node->link[word[i]-'a'];
                node->cntPrefix++;
             }
        node->endWith++;
    }

    int countWordsEqualTo(string &word){
        Node* node=root;
        for(int i=0;i<word.length();i++)
           {
              if(node->containsKey(word[i]))  node=node->link[word[i]-'a'];
              else return 0;
          }
        return node->endWith;
    }

    int countWordsStartingWith(string &word){
          Node* node=root;
          for(int i=0;i<word.length();i++)
            {
              if(node->containsKey(word[i]))  node=node->link[word[i]-'a'];
              else return 0;
            }
        return node->cntPrefix;
    }

    void erase(string &word){
          Node* node=root;
          for(int i=0;i<word.length();i++)
            {
               node=node->link[word[i]-'a'];
               node->cntPrefix--;
           }
          node->endWith--;
     }
};