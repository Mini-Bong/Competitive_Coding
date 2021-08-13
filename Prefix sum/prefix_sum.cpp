
// this is the implementation of prefix sum, in subsquent program
// I will implement the application of prefix sum.


#include<bits/stdc++.h>
using namespace std;

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
	std::vector<int> arr(n);
	for (int i = 0; i < n; i++) {
		cin >> arr[i];
	}
	vector<int> prefixSumArray(n);
	prefixSumArray[0] = arr[0];
	for (int i = 1; i < n; i++) {
		prefixSumArray[i] = prefixSumArray[i - 1] + arr[i];
	}

	for (int i = 0; i < n; i++) {
		cout << prefixSumArray[i] << " ";
	}
	cout << "Completed!!";
}