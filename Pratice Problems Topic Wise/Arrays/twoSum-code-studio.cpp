// https://www.codingninjas.com/studio/problems/two-sum_839653



#include<bits/stdc++.h>
#include<unordered_map>
using namespace std;

vector<pair<int,int>> twoSum(vector<int>& arr, int target, int n)
{
	vector<pair<int, int>> ans;
	unordered_map<int, int> map;
	for(int i=0; i<n; i++) {
		int ele = arr[i];
		int requirement = target-ele;
		if(map[requirement]) {
			ans.push_back(make_pair(requirement, ele));
			map[requirement]--;
		} 
		else 
			map[arr[i]]++;
	} 

	if(ans.empty())
		ans.push_back({-1, -1});
	
	return ans;
}
