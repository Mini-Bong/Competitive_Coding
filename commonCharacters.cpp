/*Given an array A of strings made only from lowercase letters, return a
list of all characters that show up in all strings within the list (including 
duplicates).  For example, if a character occurs 3 times in all strings but
not 4 times, you need to include that character three times in the final answer.*/

#include<bits/stdc++.h>
using namespace std;

string findCommon(string s1, string s2){
    string res = "";
    int arr[26] = {0};
    for(int i=0; i<s1.size(); i++){
        arr[s1[i]-'a']++;
    }
    for(int i=0; i<s2.size(); i++){
        if(arr[s2[i]-'a']>0){
            res += s2[i];
            arr[s2[i]-'a']--;
        }
    }
    return res;
}
vector<string> commonChars(vector<string>& A) {
    int n = A.size();
    int arr[26] = {0};
    string s1 = A[0];
    for(int i=1; i<n; i++){
        string s2 = A[i];
        s1 = findCommon(s1, s2);
    }
    vector<string> res;
    for(int i=0; i<s1.size(); i++){
        string s(1, s1[i]);
        res.push_back(s);
    }
    return res;
}

//driver code
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n;
    cin>>n;
    vector<string> arr(n);
    for(int i=0; i<n; i++){
        cin>>arr[i];
    }
    vector<string> res = commonChars(arr);
    for(int i=0; i<res.size(); i++){
        cout<<res[i]<<" ";
    }
}