/* Given an integer array nums where every element appears three
times except for one, which appears exactly once.
Find the single element and return it. */

#include<bits/stdc++.h>
using namespace std;
int single_number(vector<int> nums){
    int n = nums.size();
    int res = 0;
    for(int i=0; i<32; i++){
        int count = 0;
        for(int j=0; j<n; j++){
            if(nums[j]&(1<<i)){
                count++;
            }
        }
        if(count%3){
            res += (1<<i);
        }
    }
    return res;
}

// driver code
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n;
    cin>>n;
    vector<int> arr(n);
    for(int i=0; i<n; i++){
        cin>>arr[i];
    }
    cout<<single_number(arr);
    return 0;
}