// https://www.codingninjas.com/studio/problems/majority-element_6915220



#include<bits/stdc++.h>
using namespace std;

vector<int> majorityElement(vector<int> v) {

    /* 	
    //TC => O(N)
    //SC => O(N)
	vector<int>list;
	int n = v.size();
	int m = (int)(n/3) + 1;
	map<int, int>mpp;
	for(int i = 0; i < n; i++) {
		mpp[v[i]]++;

		if(mpp[v[i]] == m) list.push_back(v[i]);
		if(list.size() == 2) break;
	}
	sort(list.begin(), list.end());
	return list; 
    */

	//TC => O(N)
	//SC => O(1)
	int cnt1 = 0, cnt2 = 0;
	int el1 = INT_MIN, el2 = INT_MIN;
	int n = v.size();
	int m = (int)(n/3) + 1;
	for(int i = 0; i < n; i++) {
		if(cnt1 == 0 && el2 != v[i]) {
			cnt1 = 1;
			el1 = v[i];
		} else if(cnt2 == 0 && el1 != v[i]) {
			cnt2 = 1;
			el2 = v[i];
		} 
		else if(el1 == v[i]) cnt1++;
		else if(el2 == v[i]) cnt2++;
		else {
			cnt1--; cnt2--;
		}
	}

	cnt1 = 0; cnt2 = 0;
	for (int i = 0; i < n; i++) {
		if (el1 == v[i])cnt1++;
		if (el2 == v[i])cnt2++;
	}

	vector<int>ans;
	if(cnt1 >= m)ans.push_back(el1);
	if(cnt2 >= m)ans.push_back(el2);
	sort(ans.begin(), ans.end()); //TC => O(2log(2))-> constant
	return ans;
}
        