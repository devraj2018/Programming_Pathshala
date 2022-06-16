bool findPattern(string pat, string txt)
{
   int M=pat.length();
   int N=txt.length();
   int lps[M];
   int len = 0;
   lps[0] = 0; // lps[0] is always 0
  
    
    int i = 1;
    while (i < M) {
        if (pat[i] == pat[len]) {
            len++;
            lps[i] = len;
            i++;
        }
        else 
        {
             if (len != 0) {
                len = lps[len - 1];
   
            }
            else  
            {
                lps[i] = 0;
                i++;
            }
        }
    }
     i = 0;  
    int j = 0;  
    while (i < N) {
        if (pat[j] == txt[i]) {
            j++;
            i++;
        }
  
        if (j == M) {
            return true;
            j = lps[j - 1];
        }
   
        else if (i < N && pat[j] != txt[i]) {
            if (j != 0) j = lps[j - 1];
            else i = i + 1;
        }
    }
    return false;

}