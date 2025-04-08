// https://www.naukri.com/code360/problems/minimum-swaps-to-sort-array_1806885




#include <bits/stdc++.h>
using namespace std;

// TC : O(N * log(N))
// SC : O(N)
int minSwaps(vector<int> &arr) {
	int n = arr.size();
	vector<pair<int, int>> store;
	for (int i = 0; i < n; i ++) {
		store.push_back({arr[i], i});
	}

	sort(begin(store), end(store));

	int minSwaps = 0;
	for (int i = 0; i < n; i ++) {
		int idx = store[i].second;
		int ele = store[i].first;
		if (idx != i) {
			minSwaps += 1;
			swap(store[i], store[idx]);
			i --;
		}
	}
	return minSwaps;
}