struct Node{
    Node* link[26];
    bool isEnd=false;
    bool containKey(char ch) {return link[ch-'a']!=NULL;}
};
class Trie{
      Node* root;
    public:
      Trie() { root=new Node();}
    
      void insert(string &word)
        {
           Node* node=root;
           for(int i=0;i<word.length();i++)
              {
               if(!node->containKey(word[i])) node->link[word[i]-'a']= new Node();   
               node=node->link[word[i]-'a'];
              }
          node->isEnd=true;
        }
      bool search(string &word)
        {
          Node* node=root;
          for(int i=0;i<word.length();i++)
           {
             if(!node->containKey(word[i]) || !(node->link[word[i]-'a']->isEnd)) return false;
             node=node->link[word[i]-'a'];
           }
          return true;
        }
 };

string completeString(int n, vector<string> &a){
     Trie t;
     int maxL=0;
     string ans="";

     for(int i=0;i<n;i++)  t.insert(a[i]);
     for(int i=0;i<n;i++)
        {
           if(a[i].length()<maxL) continue;
           if(t.search(a[i]))
             {
               if(a[i].length()>maxL)
                 {
                  maxL=a[i].length();
                  ans=a[i];
                 }
               else if(a[i].length()==maxL)
                {
                   if(ans> a[i]) ans=a[i]; 
                }
             }
        
        }
    if(maxL==0) return "None";
    return ans;
    
}