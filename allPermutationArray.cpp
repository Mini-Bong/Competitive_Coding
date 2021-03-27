#include<bits/stdc++.h>
using namespace std;

void printArray(vector<int> arr){
    for(int i=0; i<arr.size(); i++)
    {
        cout<<arr[i]<<" ";
    }
    cout<<"\n";
}

vector<vector<int>> allPermutation(vector<int> arr)
{
    sort(arr.begin(), arr.end());
    vector<vector<int>> res;
    res.push_back(arr);
    while(next_permutation(arr.begin(), arr.end())){
        res.push_back(arr);
    }
    return res;
}

int main(){
    int n;
    cin>>n;
    vector<int> arr(n);
    for(int i=0; i<n; i++){
        cin>>arr[i];
    }
    vector<vector<int>> res = allPermutation(arr);
    for(int i=0; i<res.size(); i++){
        printArray(res[i]);
    }
    return 0;
}