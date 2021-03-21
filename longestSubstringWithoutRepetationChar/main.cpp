#include <bits/stdc++.h>

using namespace std;
int longest_sub_str(string str){
    int maxCount = 0;
    int n = str.size();
    set<char> s;
    for(int i=0; i<n; i++){
        s.clear();
        int count = 1;
        s.insert(str[i]);
        for(int j =i+1 ; j<n; j++){
            if(s.find(str[j])!= s.end()){
                break;
            }
            else{
                s.insert(str[j]);
                count++;
            }
        }
        maxCount = max(maxCount, count);
    }
    return maxCount;
}
int find_substring(string str)
{
    int len = str.size();
    int count = 0;
    vector<int> arr(256,-1);
    int last_index = 0;
    for(int i=0; i<len; i++)
    {
        last_index = max(last_index, arr[str[i]]+1);
        count = max(count, i-last_index+1);
        arr[str[i]] = i;
    }
    return count;
} 
int main()
{
    string str;
    cout<<"Enter the string:";
    cin>>str;
    cout<<"Longest substring without repeating character:"<<find_substring(str)<<endl;
    cout<<"Longest substring using set:"<<longest_sub_str(str);
    return 0;
}
