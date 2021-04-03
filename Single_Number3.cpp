/* Given an integer array nums, in which exactly two elements appear only
once and all the other elements appear exactly twice
Find the two elements that appear only once. You can return the answer in any order. */

#include<bits/stdc++.h>
using namespace std;
vector<int> single_number(vector<int> nums){
    int XOR = 0;
    for(int i:nums){
        XOR ^= i;
    }
    int rightMostSetBit = 1;
    while(true){
        if((XOR & rightMostSetBit)==0){
            rightMostSetBit = rightMostSetBit<<1;
        }
        else{
            break;
        }
    }
    int a = 0, b = 0;
    for(int i : nums){
        if(rightMostSetBit & i){
            a ^= i;
        }
        else{
            b ^= i;
        }
    }
    return {a, b};
    // navie method using map
    /*
    unordered_map<int, int> mp;
    int n = nums.size();
    vector<int> res;
    for(int i=0; i<n; i++){
        mp[nums[i]]++;
    }
    for(auto it : mp){
        if(it.second==1){
            res.push_back(it.first);
        }
    }
    return res; */
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
    vector<int> res = single_number(arr);
    cout<<res[0]<<" "<<res[1];
    return 0;
}