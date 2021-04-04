/* Given two integer arrays nums1 and nums2, return an array of their intersection.
Each element in the result must be unique and you may return the result in any order. */


#include<bits/stdc++.h>
using namespace std;

vector<int> intersection(vector<int>& nums1, vector<int>& nums2) {
    map<int, int> mp;
    int n1 = nums1.size();
    for(int i=0; i<n1; i++){
        mp[nums1[i]]++;
    }
    int n2 = nums2.size();
    vector<int> res;
    set<int> st;
    for(int i=0; i<n2; i++){
        if(mp[nums2[i]] && st.find(nums2[i])==st.end()){
            res.push_back(nums2[i]);
            st.insert(nums2[i]);
        }
    }
    return res;
}
//driver code
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n1, n2;
    cin>>n1;
    vector<int> arr1(n1);
    for(int i=0; i<n1; i++)
    {
        cin>>arr1[i];
    }
    cin>>n2;
    vector<int> arr2(n2);
    for(int i=0; i<n2; i++){
        cin>>arr2[i];
    }
    vector<int> res = intersection(arr1, arr2);
    for(int i=0; i<res.size(); i++){
        cout<<res[i]<<" ";
    }
}