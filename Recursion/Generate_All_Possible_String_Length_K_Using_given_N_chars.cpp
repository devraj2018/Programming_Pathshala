#include <iostream>
#include <vector>
#include <string>
using namespace std;

void Generate(char arr[], int &n, int curr_I, int &k, vector<string> &all, string curr)
{
     if (curr_I == k)
     {
          all.push_back(curr);
          return;
     }
     string temp;
     for (int i = 0; i < n; i++)
     {
          temp = curr;
          temp.push_back(arr[i]);
          Generate(arr, n, curr_I + 1, k, all, temp);
     }
}

int main()
{
     int n = 3, k = 4;
     //cin>>n>>k;
     char arr[] = {'a', 'b', 'c'};
     //  for(int i=0;i<n;i++)
     //  cin>>arr[i];

     vector<string> all;
     string curr = "";
     Generate(arr, n, 0, k, all, curr);

     for (int i = 0; i < all.size(); i++)
          cout << all[i] << endl;
}
