#include<bits/stdc++.h>
using namespace std;

string multiplyStrings(string s1, string s2) {
   //Your code here
   int n1 = s1.size();
   int n2 = s2.size();
   string res = "";
   vector<int> arr(n1+n2, 0);
   string str1, str2;
   int counter = 0;
   int inc = 0;
   for(int j=n2-1; j>=0; j--) // second string iterator
   {
       counter = inc;
       int carry = 0;
       for(int i=n1-1; i>=0; i--)  // first string iterator
       {
           int sum = (int)(s1[i]-'0')*(int)(s2[j]-'0') + carry + arr[counter];
           arr[counter] = sum%10;
           carry = sum/10;
           counter++;
       }
       if(carry>0){
           arr[counter] += carry;
       }
       inc++;
   }
   int carry = 0;
   for(int i=0; i<arr.size(); i++){
       if((arr[i]+carry)>9){
           int temp = arr[i];
           arr[i] = (temp+carry)%10;
           carry = temp/10;
       }
       else{
           arr[i] += carry;
           carry = 0;
       }
   }
   bool flag = false;
   for(int i=arr.size()-1; i>=0; i--){
       if(arr[i]>0){
           flag = true;
       }
       if(flag){
           res += to_string(arr[i]);
           flag = true;
       }
   }
   if(!flag){
       res = "0";
   }
   return res;
}

int main()
{
    int n; // factorial number;
    cin>>n;
    string res = "1";
    for(int i=2; i<=n; i++){
        res = multiplyStrings(to_string(i), res);
    }
    cout<<res;
}
