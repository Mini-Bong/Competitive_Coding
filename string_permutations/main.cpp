#include <iostream>

using namespace std;

void string_permute(string s, int l, int r)
{
    if(l==r)
    {
        cout<<s<<"\n";
    }
    else{
        for(int i=l; i<=r; i++)
        {
            swap(s[l], s[i]);
            string_permute(s, l+1, r);
            swap(s[l], s[i]);
        }
    }
}
int main()
{
    string str;
    cout<<"Enter any string: ";
    cin>>str;
    int n = str.size();
    string_permute(str, 0, n-1);
    return 0;
}
