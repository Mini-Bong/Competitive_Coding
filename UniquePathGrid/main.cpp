#include <bits/stdc++.h>
using namespace std;
int grid[9][9] = {{1, 2, 3},
                {4, 5, 6},
                {7, 8, 9}};

void printCurrPath(int arr[], int n){
    for(int i=0; i<n; i++){
        cout<<arr[i]<<" ";
    }
    cout<<"\n";
}
int printAllPath(int n, int m, int path[], int pathSize, int index)
{
    path[index] = grid[n][m];
    if(n==0 && m==0){
        printCurrPath(path, pathSize);
        return 0;
    }
    if(n==0){
        printAllPath(n, m-1, path, pathSize, index-1);
        return 1;
    }
    if(m==0){
        printAllPath(n-1, m, path, pathSize, index-1);
        return 1;
    }
    return printAllPath(n, m-1, path, pathSize, index-1) + printAllPath(n-1, m, path, pathSize, index -1);
}
int main()
{
    int pathArrayIndex = 5;
    int n = 3;
    int m = 3;
    int pathSize = 5;
    int path[5];
    cout<<printAllPath(n-1, m-1, path, pathSize, pathArrayIndex-1);
}
