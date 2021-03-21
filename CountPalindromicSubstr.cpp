#include<bits/stdc++.h>
using namespace std;
int countSubstrings(string str) {
        int n = str.size();
        int low = 0, high = 0;
        int count = 1;
        for(int i=1; i<n; i++){
            low = i-1;
            high = i;
            count++;
            while(low>=0 && high<n && str[low]==str[high])
            {
                low--;
                high++;
                count++;
            }
            low = i-1;
            high = i+1;
            while(low>=0 && high<n && str[low] == str[high])
            {
                low--;
                high++;
                count++;
            }
        }
        return count;
    }

// driver code
int main()
{
    string str;
    cin>>str;
    cout<<"The number of palindromic Substring: "<<countSubstrings(str);
    return 0;
}