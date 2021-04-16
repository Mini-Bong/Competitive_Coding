#include<bits/stdc++.h>
using namespace std;

int count(int n) {
	if (n == 1) {
		return 9;
	}
	int res = 9;
	for (int i = 1; i < n; i++) {
		res *= (10 - i);
	}
	return res;
}

int countNumbersWithUniqueDigits(int n) {
	int res = 1;
	if (n == 0) {
		return 1;
	}
	for (int i = 1; i <= n; i++) {
		res += count(i);
	}
	return res;
}

int main() {
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif

	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int n;
	cin >> n;
	cout << countNumbersWithUniqueDigits(n);
}