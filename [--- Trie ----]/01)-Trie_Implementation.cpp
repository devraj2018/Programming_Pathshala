struct Node{
    Node* link[26];
    bool isEnd=false;
    
    bool containKey(char ch) return (link[ch-'a']!=NULL);
 };

class Trie {
    Node* root;
public:
    Trie() {
        root=new Node();
      }

    /** Inserts a word into the trie. */
    void insert(string word) {
        
        Node* node=root;
        for(int i=0;i<word.length();i++)
        {
             if(! node->containKey(word[i]))
             {
                 node->link[word[i]-'a']=new Node();
             }
            node= node->link[word[i]-'a'];
        }
        node->isEnd=true;

    }

    /** Returns if the word is in the trie. */
    bool search(string word) {
          Node* node=root;
          for(int i=0;i<word.length();i++)
            {
             if(! node->containKey(word[i]))
             {
                return false;
             }
            node= node->link[word[i]-'a'];
        }
        return node->isEnd;

    }

    /** Returns if there is any word in the trie that starts with the given prefix. */
    bool startsWith(string word) {
        Node* node=root;
          for(int i=0;i<word.length();i++)
            {
             if(! node->containKey(word[i]))
             {
                return false;
             }
            node= node->link[word[i]-'a'];
        }
        return true;


    }
};