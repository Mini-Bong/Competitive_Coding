#include<bits/stdc++.h>

using namespace std;
int res = 0;

bool isValid(int i, int j, int M, int N){
    return (i>=0 && i<M && j>=0 && j<N);
}

int printPath(vector<char>const &path, char last){
    vector<char> arr;
    arr = path;
    arr.push_back(last);
    int n = arr.size();
    for(int i=0; i<n/2; i++){
        if(arr[i]!=arr[n-1-i]){
            return 0;
        }
    }
    /*for (char i : path)
        cout << i << " - ";
    cout << last << endl;*/
    return 1;
}

void findAllPath(vector<vector<char>> grid, vector<char> &path, int i, int j, int m, int n)
{
    if(i==m-1 && j==n-1){
        res += printPath(path, grid[i][j]);
        return;
    }
    path.push_back(grid[i][j]);
    if (isValid(i, j+1, m, n)){
        findAllPath(grid, path, i, j+1, m, n);
    }
    if(isValid(i+1, j, m, n)){
        findAllPath(grid, path, i+1, j, m, n);
    }
    path.pop_back();
}

int main()
{
    int n, m;
    cin>>m>>n;
    vector<vector<char>> grid(m, vector<char>(n));
    for(int i=0;i<m; i++){
        for(int j=0; j<n; j++){
            cin>>grid[i][j];
        }
    }
    vector<char> path;
    int x =0;
    int y =0;
    findAllPath(grid, path, x, y, m, n);
    cout<<res;
    return 0;
}
