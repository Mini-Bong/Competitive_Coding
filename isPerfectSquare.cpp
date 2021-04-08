/* Given a positive integer num, write a function which returns
 True if num is a perfect square else False.*/

#include<bits/stdc++.h>
using namespace std;

bool isPerfectSquare(int num){
    long int left =1, right = num;
    while(left<=right){
        long mid = (left+right)/2;
        if(mid*mid == num)
            return true;
        if(mid*mid < num){
            left = mid+1;
        }
        else{
            right = mid-1;
        }
    }
    return false;
    
    // by using inbuilt function
    /*long val = sqrt(num);
    val = val*val;
    if(val==num){
        return 1;
    }
    return 0; */
}
 // driver code
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n;
    cin>>n;
    cout<<isPerfectSquare(n);
}