#include<bits/stdc++.h>
using namespace std;

map<pair<int, int>, int> mp;

int coinChange(int S[], int m, int n){
        if(n==0){
            return 1;
        }
        if(n<0){
            return 0;
        }
        if(m<=0 && n>0){
            return 0;
        }
        if(mp[{m,n}]==0){
            mp[{m,n}] = coinChange(S, m-1, n) + coinChange(S, m, n-S[m-1]);
        }
        return mp[{m, n}];
}

