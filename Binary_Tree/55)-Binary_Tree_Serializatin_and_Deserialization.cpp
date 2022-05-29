class Codec {
public:
    string s;
   // Encodes a tree to a single string.
    void ser_helper(TreeNode* root)
    {  if(root==NULL)
         { s+="#";  return;            //to_string-->also converts for negative number
         }
       s+=to_string(root->val)+"|";     // "|" -> used for seperator ,after a node value  
       ser_helper(root->left);      
       ser_helper(root->right);
         
    }
    string serialize(TreeNode* root) {
       ser_helper(root);
        return s;
    }
    

    // Decodes your encoded data to tree.
    TreeNode* des_helper(string data,int &curr_I)
    {   
         if(curr_I>=data.length() || data[curr_I]=='#')
             return NULL;
         bool isNeg=false;
         if(data[curr_I]=='-')       //To handle the case when we have negative number
         {
             isNeg=true;
             curr_I++;
         }
        
        string temp="";
        while(data[curr_I]!='|')
        {
            temp+=data[curr_I];
            curr_I++;
        }
        int val=stoi(temp);
        if(isNeg)
            val*=(-1);
        TreeNode* root=new TreeNode(val);
        curr_I++;
        root->left=des_helper(data,curr_I);
        curr_I++;
        
        root->right=des_helper(data,curr_I);
        
         return root;
        
        
        
        
    }
    TreeNode* deserialize(string data) {
        if(data.length()==1) return NULL;
        int curr_I=0;
        return des_helper(data,curr_I);
        
    }
};
