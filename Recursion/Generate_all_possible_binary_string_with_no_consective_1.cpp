#include <iostream>
#include <string>
using namespace std;

void helper(int currI, int &n, int prev, string curr)  // To generate all strings
{

    if (currI == n)
    {
        cout << curr << endl;
        return;
    }

    helper(currI + 1, n, 0, curr + "0");

    if (prev == 0)
        helper(currI + 1, n, 1, curr + "1");
}

// zero[i]=zero[i-1]+one[i-1]   [zero[i]-->no of string ending at i index with last char as 0]
// one[i]=zero[i-1]   [one[i]-->no of string ending at i index with last char as 1]

//We get two recurrence relation so By combining these 2 equation --> zero[i]=zero[i-1]+zero[i-2];
//We get fibonacci recurrence ,Just need to hancdlw base cases differently
int count_using_tabulation(int n)
{
     if(n==0) return 0;
     if(n==1) return 2;

     int a=1,b=2,c;
     for(int i=2;i<=n;i++)
     { c=a+b;
       a=b;
       b=c;

     }
     return c;



}
int main()
{
    int n=5;
    // cin >> n;
    string curr = "";
    helper(0, n, 0, curr);
}