#include<bits/stdc++.h>
using namespace std;

int pivotPoint(vector<int> arr, int low, int high)
{
    if(high<low){
        return -1;
    }
    if(high == low){
        return low;
    }
    int mid = (low+high)/2;
    if(mid<high && arr[mid]>arr[mid+1]){
        return mid;
    }
    if(mid>low && arr[mid]<arr[mid-1]){
        return mid-1;
    }
    if(arr[low] >=arr[mid]){
        return pivotPoint(arr, low, mid-1);
    }
    return pivotPoint(arr, mid+1, high);
}

// driver code
int main(){
    int n;
    cin>>n;
    vector<int> arr(n);
    for(int i=0; i<n; i++){
        cin>>arr[i];
    }
    cout<<"The pivot value is on "<<pivotPoint(arr, 0, n-1)<<" index";
}