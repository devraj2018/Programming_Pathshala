class Codec {
public:
    string s="";
    void serialHelper(TreeNode* root)
    {    if(root==NULL)
           { s+="+";
             return;
           }
       s+= to_string(root->val) + "|";
       serialHelper(root->left);
       serialHelper(root->right);
    }
    string serialize(TreeNode* root) {
        serialHelper(root);
        return s;
     }
     
    TreeNode* desHelper(string data,int n,int &curr_I)
    {    if(curr_I>=n) return NULL;
         if(data[curr_I]=='+') return NULL;
         string temp="";
         while(curr_I<n && data[curr_I]!='|') temp.push_back(data[curr_I++]);
         int value=stoi(temp);
         TreeNode* newroot=new TreeNode(value);
         curr_I++;
         newroot->left=desHelper(data,n,curr_I);
         curr_I++;
         newroot->right=desHelper(data,n,curr_I);
         return newroot;
    }
  // Decodes your encoded data to tree.
    TreeNode* deserialize(string data) {
         int length=data.length();
         int curr_I=0;
         return desHelper(data,length,curr_I);
    }
};
