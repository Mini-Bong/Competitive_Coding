#include <bits/stdc++.h>
using namespace std;

void constructLPS(int *lps, int m, string pattern )
{
    int i = 1;
    int len =0;
    while(i<m){
        if(pattern[i]==pattern[len]){
            len++;
            lps[i] = len;
            i++;
        }
        else{ // pattern[i] != pattern[len]
            if(len!=0){
                len = lps[len-1];
            }
            else{ // if len = 0
                lps[i] = 0;
                i++;
            }
        }
    }
}
void KMPSearch(string text, string pattern)
{
    int pattLength = pattern.size();
    int lps[pattLength];
    lps[0] = 0;
    constructLPS(lps, pattLength, pattern);
    for(int i=0; i<pattLength; i++){
        cout<<lps[i]<<" ";
    }
    int textLength = text.size();
    int i = 0;
    int j = 0;
    while(i<textLength){
        if(text[i]==pattern[j]){
            i++;
            j++;
        }
        if(j==pattLength){
            cout<<"find pattern at index "<<i-j;
            j = lps[j-1];
        }
        else if(i<textLength && pattern[j]!=text[i]){
            if(j!=0){
                j = lps[j-1];
            }
            else{
                i = i+1;
            }
        }
    }
}
int main()
{
    string text = "ABABDABACDABABCABAB";
    string pattern = "ABABCABAB";
    KMPSearch(text, pattern);
    return 0;
}
