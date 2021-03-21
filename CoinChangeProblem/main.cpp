#include <bits/stdc++.h>
#include "recursiveApproach.cpp"
using namespace std;
// this is the simple recursive call to perform the coin change problem
/*
int numberOfWay(int coins[], int numberOfCoin, int maxPrice)
{
    // if m is 0 then there is 1 solution
    // do not include any coin
    if(maxPrice==0){
        return 1;
    }
    // if m is less then 0 then no solution exists
    if(maxPrice<0){
        return 0;
    }
    // if there is no coin and m is greater then 0 then
    // no solution exists
    if(numberOfCoin<=0 && maxPrice>=1){
        return 0;
    }
    return numberOfWay(coins, numberOfCoin-1, mamPrice)+numberOfWay(coins, numberOfCoin, maxPrice-coins[numberOfCoin-1]);
}*/


 // We are using dynamic programming to perform coin chain problem

int numberOfWay(int coins[], int coinArraySize, int n)
{
    int table[n+1];
    memset(table, 0, sizeof(table));
    table[0] = 1;
    for(int i=0; i<coinArraySize; i++){
        for(int j = coins[i]; j<=n; j++){
            table[j] += table[j-coins[i]];
        }
    }
    return table[n];
}
int main()
{
    int m = 3; // Number of coin;
    int arr[3] = {1, 2, 3};
    int n = 4 ; // price value
    cout<<numberOfWay(arr, m, n)<<endl;
    cout<<coinChange(arr, m, n);
    return 0;
}
