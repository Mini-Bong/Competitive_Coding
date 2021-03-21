#include <iostream>
#include<unordered_map>
#include<bits/stdc++.h>
using namespace std;

void findSymPairs(int arr[][2], int n)
{
    unordered_map<int, int> m;
    for(int i=0; i<n; i++)
    {
        int first = arr[i][0];
        int second = arr[i][1];
        // if element and value in hash matches with first element of this pair
        if(m.find(second)!=m.end() && m[second] == first)
        {
            cout<<"( "<<second<<", "<<first<<" )";
        }
        else{
            m[first] = second;
        }
    }
}

int main()
{
    int arr[5][2];
    arr[0][0] = 11; arr[0][1] = 20;
    arr[1][0] = 30; arr[1][1] = 40;
    arr[2][0] = 5;  arr[2][1] = 10;
    arr[3][0] = 40;  arr[3][1] = 30;
    arr[4][0] = 10;  arr[4][1] = 5;
    findSymPairs(arr, 5);
}
