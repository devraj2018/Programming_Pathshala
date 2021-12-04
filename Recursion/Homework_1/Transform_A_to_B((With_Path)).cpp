#include <bits/stdc++.h>

using namespace std;
void helper(long long curr_number, long long target, vector<long long> res, bool &ans, vector<long long> &finalP)
{
    if (curr_number > target)
        return;
    res.push_back(curr_number);

    if (curr_number == target && ans == false)
    {
        finalP = res;
        ans = true;
    }

    long long newa = 2 * curr_number, newb = curr_number * 10 + 1;

    helper(newa, target, res, ans, finalP);
   
    helper(newb, target, res, ans, finalP);
   
}
int main()
{
    long long a, b;
    cin >> a >> b;
    bool ans = false;
    vector<long long> path;
    vector<long long> finalP;
    helper(a, b, path, ans, finalP);

    if (ans)
    {
        cout << "YES" << endl<<finalP.size()<<endl;
        for (int i = 0; i < finalP.size(); i++)
            cout << finalP[i] << " ";
    }
    else
        cout << "NO" << endl;
}