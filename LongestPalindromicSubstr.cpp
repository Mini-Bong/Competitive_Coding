// Leetcode question 5

#include<bits/stdc++.h>
using namespace std;

string substring(string str, int low, int high)
{
	string res = "";
	for(int i=low; i<=high; i++){
		res += str[i];
	}
	return res;
}

string LongestPalindromicSubstr(string str)
{
	int n = str.size();
	int start = 0;
	int max_len = 1;
	int low, high;
	if(n==1){
		return str;
	}
	for(int i=1; i<n; i++){
		low = i-1;
		high = i;

		// for even length substring
		while(low>=0 && high<n && str[low]==str[high])
		{
			if(high-low+1 > max_len)
			{
				max_len = high-low+1;
				start = low;
			}
			low--;
			high++;
		}
		low = i-1;
		high = i+1;
		while(low<=0 && high<n && str[low] == str[high])
		{
			if(high-low+1 > max_len)
			{
				max_len = high-low+1;
				start = low;
			}
		}
	}
	cout<<"The length of the longest palindrom substring is :"<<max_len<<"\n";
	return substring(str, start, start+max_len-1);
}

int main()
{
	string s;
	cin>>s;
	cout<<LongestPalindromicSubstr(s);
}