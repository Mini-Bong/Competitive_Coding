#include <bits/stdc++.h>
using namespace std;


int minxorpair(int N, std::vector<int> arr) {
	// Navie Solution O(N^2)
	/*int min = INT_MAX;
	for(int i=0; i<N; i++){
	    for(int j=i+1; j<N; j++){
	        if(arr[i]^arr[j]<min){
	            min = arr[i]^arr[j];
	        }
	    }
	}
	return min; */

	// efficient solution O(NlogN)
	sort(arr.begin(), arr.end());
	int minXor = INT_MAX;
	int val = 0;
	for (int i = 0; i < N - 1; i++) {
		val = arr[i] ^ arr[i + 1];
		minXor = min(minXor, val);
	}
	return minXor;

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
	std::vector<int> arr(n);
	for (int i = 0; i < n; i++) {
		cin >> arr[i];
	}
	cout << minxorpair(n, arr);
}