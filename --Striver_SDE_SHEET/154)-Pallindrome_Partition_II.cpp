 
bool isPalindrome(string str, int i, int j) {
    while (i <= j) {
        if (str[i++] != str[j--]) {
            return false;
        }
    }
    return true;
}

 
int minPalinPartition(string str, int i, int j) {
     

    if (i == j || isPalindrome(str, i, j)) return 0;
   
    int min = INT_MAX;
    for (int k = i; k <= j - 1; k++) {
         int count = 1 + minPalinPartition(str, i, k) + minPalinPartition(str, k + 1, j);
         if (count < min)   min = count;
        
    }
 
    return min;
}

int palindromePartitioning(string str) {
    int n = str.size();
    return minPalinPartition(str, 0, n - 1);
}
