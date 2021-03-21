#include <iostream>
#include<bits/stdc++.h>
using namespace std;

map<pair<int, int>, int> mp;
int lps(string str, int i, int j)
{
    // base case when string length is 1
    if(i==j){
        return 1;
    }

    // case when string length is two and both characters are same
    if(str[i]==str[j] && i+1 == j){
        return 2;
    }

    if(str[i]==str[j]){
        if(mp[{i,j}]){
            return mp[{i, j}];
        }
        else{
            mp[{i, j}] = lps(str, i+1, j-1) + 2;
            return mp[{i, j}];
        }
    }
    return max(lps(str, i+1, j), lps(str, i, j-1));
}

int main()
{
    string str = "GEEKSFORGEEKS";
    int n = str.size();
    cout<<"The length of longest palindromic subsequence is :"<<lps(str, 0, n-1);
}
