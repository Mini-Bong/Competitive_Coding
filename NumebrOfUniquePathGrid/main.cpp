#include <bits/stdc++.h>
using namespace std;
map<pair<int, int>, int> mp;
int UniquePath(int n, int m)
{
    if(n==1 || m==1)
    {
        return 1;
    }
    if(mp[{ n, m }] == 0){
        mp[{ n,m }] =  UniquePath(n-1, m) + UniquePath(n, m-1);
    }
    return mp[{n,m}];

}

int main()
{
    int n = 3;
    int m = 3;
    cout<<UniquePath(n, m);
    return 0;
}
