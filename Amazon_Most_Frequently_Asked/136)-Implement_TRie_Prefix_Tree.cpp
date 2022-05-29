class Trie {
     struct Node{
         
          Node* link[26]={NULL};
          bool isEnd;
          Node(){
              isEnd=false;
              
          }
         
         
     };
public:
    Node* root;
    Trie() {
        root= new Node();
    }
    
    void insert(string word) {
         Node* node=root;
        
         for(int i=0;i<word.length();i++)
         {
              if(node->link[word[i]-'a']==NULL)
                  node->link[word[i]-'a']= new Node();
              node=node->link[word[i]-'a'];
             
         }
        node->isEnd=true;
         
    }
    
    bool search(string word) {
        
        Node* node=root;
        
       for(int i=0;i<word.length();i++)
         {
              if(node->link[word[i]-'a']==NULL)
                 return false;
             node=node->link[word[i]-'a'];
             
         }
        return node->isEnd;
        
    }
    
    bool startsWith(string prefix) {
          Node* node=root;
        
         for(int i=0;i<prefix.length();i++)
         {
              if(node->link[prefix[i]-'a']==NULL)
                 return false;
             node=node->link[prefix[i]-'a'];
             
         }
        return true;
    }
};

/**
 * Your Trie object will be instantiated and called as such:
 * Trie* obj = new Trie();
 * obj->insert(word);
 * bool param_2 = obj->search(word);
 * bool param_3 = obj->startsWith(prefix);
 */