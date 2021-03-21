#include <iostream>
#include<string>
using namespace std;

string LPS(string s){
    int n = s.size();
    int mid_odd = 0, mid_even = 0;
    int start = 0, end = 0;
    int count = 1;
    int max_len_odd = 0;
    int max_len_even = 0;
    if(n==1){
        return s;
    }
    if(n==2 && s[0]==s[1]){
        return s;
    }
    for(int i=1; i<n; i++){
        count = 1;
        start = i-1;
        end = i+1;
        while(start>=0 && end<n && s[start]==s[end]){
            count+=2;
            start--;
            end++;
        }
        //cout<<count;
         if(max_len_odd<count){
             max_len_odd = count;
             mid_odd = i;
         }
    }
    for(int i=0; i<n; i++){
        count = 0;
        start = i;
        end = i+1;
        while(start>=0 && end<n && s[start] == s[end]){
            count +=2;
            start--;
            end++;
        }
        if(max_len_even<count){
            max_len_even = count;
            mid_even = i;
        }
    }
    string res="";
    if(max_len_odd>max_len_even){
            cout<<"mid_odd "<<mid_odd<<" max_len_odd "<<max_len_odd;
        res = s.substr(mid_odd - (max_len_odd)/2, mid_odd+(max_len_odd)/2 +1);
    }
    else{
        res = s.substr(mid_even + 1 -(max_len_even)/2, mid_even+(max_len_even)/2+1);
    }
    return res;
}

int main()
{
    string str;
    cin>>str;
    cout<<LPS(str);
}
