/*Given a sorted array nums, remove the duplicates in-place such that duplicates
appeared at most twice and return the new length.
Do not allocate extra space for another array;
you must do this by modifying the input array in-place with O(1) extra memory.
*/

#include <bits/stdc++.h>
using namespace std;
int removeDuplicate(vector<int> &nums)
{
    int n = nums.size();
    if(n<3){
        return n;
    }
    int l=1, r = 2;
    while(r<n){
        if(nums[l-1] == nums[r] && nums[l]==nums[r]){
            r++;
        }
        else{
            l++;
            nums[l] = nums[r];
            r++;
        }
    }
    return ++l;
}

int main()
{
    int n;
    cin>>n;
    vector<int> arr(n);
    for(int i=0; i<n; i++){
        cin>>arr[i];
    }
    int new_size = removeDuplicate(arr);
    for(int i=0; i<new_size; i++){
        cout<<arr[i]<<" ";
    }
    return 0;
}
