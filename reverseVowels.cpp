#include<bits/stdc++.h>
using namespace std;

#define small(c) (c=='a' || c=='e' || c=='i' || c=='o' || c=='u')
#define big(c) (c=='A' || c=='E' || c=='I' || c=='O' || c=='U')

string reverseVowels(string s){
    int n = s.size();
    int left = 0, right = s.size()-1;
    bool l, r = false;
    while(left<=right){
        l = big(s[left]) || small(s[left]);
        r = big(s[right]) || small(s[right]);
        if( l && r){
            swap(s[left], s[right]);
            left++;
            right--;
        }
        else if(l && !r){
            right--;
        }
        else if(!l && r){
            left++;
        }
        else{
            left++;
            right--;
        }
    }
    return s;
}

// driver code
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    string str;
    cin>>str;
    cout<<reverseVowels(str);
    return 0;
}