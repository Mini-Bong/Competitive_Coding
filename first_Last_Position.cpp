#include<bits/stdc++.h>
using namespace std;

vector<int> searchRange(vector<int>&nums, int target){
    vector<int> res;
        if(nums.size()==0){
            res.push_back(-1);
            res.push_back(-1);
            return res;
        }
        bool isThere = binary_search(nums.begin(), nums.end(), target);
        if(isThere){
            int first = lower_bound(nums.begin(), nums.end(), target)-nums.begin();
            int last = upper_bound(nums.begin(), nums.end(), target)-nums.begin();
            res.push_back(first);
            res.push_back(last-1);
        }
        else{
            res.push_back(-1);
            res.push_back(-1);
        }
        return res;
}

// driver code
int main()
{
    int n, target;
    cin>>n;
    vector<int> arr(n);
    for(int i=0; i<n; i++){
        cin>>arr[i];
    }
    cin>>target;
    vector<int> res = searchRange(arr, target);
    cout<<res[0]<<" "<<res[1];
}