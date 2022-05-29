/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Codec {
public:

    // Encodes a tree to a single string.
    void serHelper(TreeNode* root,string &curr)
    {
         if(root==NULL)
         {
             curr+="#";
             return;
         }
        
         curr+= to_string(root->val)+",";
         serHelper(root->left,curr);
         serHelper(root->right,curr);
        
        
    }
    string serialize(TreeNode* root) {
        
        string curr="";
        serHelper(root,curr);
        return curr;
        
    }

    // Decodes your encoded data to tree.
    TreeNode* desHelper(string s,int &curr_I)
    {
         if(curr_I>=s.length()) return NULL;
        
          if(s[curr_I]=='#')
          {
              curr_I++;
              return NULL;
          }
        
         string temp="";
         bool neg=false;
        
         if(s[curr_I]=='-')
         {
             curr_I++;
             neg=true;
         }
         while(curr_I<s.length() && s[curr_I]!=',')
         {
             temp+=s[curr_I];
             curr_I++;
         }
        curr_I++;  // To move one step next to comma
        
        
         int val=stoi(temp);
         if(neg) val*=-1;
        
         TreeNode* root= new TreeNode(val);
         
         root->left=desHelper(s,curr_I);
         root->right=desHelper(s,curr_I);
        
        return root;
        
        
         
        
        
        
        
    }
    TreeNode* deserialize(string data) {
        int curr_I=0;
        return desHelper(data,curr_I);
        
    }
};

// Your Codec object will be instantiated and called as such:
// Codec ser, deser;
// TreeNode* ans = deser.deserialize(ser.serialize(root));