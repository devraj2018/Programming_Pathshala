#include <bits/stdc++.h>
using namespace std;

void rearrange(int arr[], int n)     //O(n) Time and O(n)space//
{
	
	int temp[n];
	for (int i = 0; i < n; i++)
		temp[arr[i]] = i;

	for (int i = 0; i < n; i++)
		arr[i] = temp[i];
}

void rearrange(int arr[], int n)    //O(n) Time and O(1)space//
{
    for (int i = 0; i < n; i++) {
        arr[arr[i] % n] += i * n;
    }
    for (int i = 0; i < n; i++) {
        arr[i] /= n;
    }
}


int main()
{
	int arr[] = { 1, 3, 0, 2 };
	int n = sizeof(arr) / sizeof(arr[0]);
    rearrange(arr, n);
    //Printing part here//
	
}

