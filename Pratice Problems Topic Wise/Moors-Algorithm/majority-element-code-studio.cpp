// https://www.codingninjas.com/studio/problems/majority-element_6783241



#include<bits/stdc++.h>
using namespace std;
int majorityElement(vector<int> v) {
/* 
	//TC => N(log(N))
	//SC => O(N)
	unorderd_map<int, int>mpp;
	for(int i = 0; i<v.size(); i++) {
		mpp[v[i]]++;
	}
	for(auto& i:mpp) {
		if(i.second > (v.size()/2)) {
			return i.first;
		}
	}
	return -1; 
	*/

	// TC => O(N)
	// SC => O(1)
	int cnt = 0;
	int el ;
	for (int i = 0; i < v.size(); i++) {
		if(cnt == 0) {
			cnt = 1;
			el = v[i];
		} else if(v[i] == el) cnt++;
		else cnt--;
	}
	int count = 0;
	for(int i=0; i<v.size(); i++) {
		if(el == v[i]) count++;
	}
	if(count > (v.size()/2)) {
		return el;
	}
	return -1;
}

