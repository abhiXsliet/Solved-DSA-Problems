// https://www.codingninjas.com/studio/problems/maximum-size-rectangle-sub-matrix-with-all-1-s_893017


#include <bits/stdc++.h>
using namespace std;


// TC = O(N)
// SC = O(N)
// This function is calculating the indexes of prev smaller element
vector<int> getPrevSmallerHeight(vector<int>& height, int n) {
	
	stack<int> stk;
	stk.push(-1);
	
	vector<int> ans(n);
	
	for (int i = 0; i < n; i++) {
		
		while(stk.top() != -1 && height[stk.top()] >= height[i]) {
			stk.pop();
		}
		
		ans[i] = stk.top();
		stk.push(i);
	}
	return ans;
}

// TC = O(N)
// SC = O(N)
// This function is calculating the indexes of next smaller element
vector<int> getNextSmallerHeight(vector<int>& height, int n) {
	
	stack<int> stk;
	stk.push(-1);
	
	vector<int> ans(n);
	
	for (int i = n - 1; i >= 0; i--) {
		
		while((stk.top() != -1) && (height[stk.top()] >= height[i])) {
			stk.pop();
		}
		
		// in case you push_back to the ans 
		// then you have to reverse it in the end
		// since indexes will get pushed into ans in reverse
		ans[i] = stk.top();
		stk.push(i);
	}
	return ans;
}

// TC = O(N)
// SC = O(N)
int getLargestArea(vector<int>& height) {
	int n = height.size();
	
	vector<int> prevSmaller = getPrevSmallerHeight(height, n);
	vector<int> nextSmaller = getNextSmallerHeight(height, n);
	
	int area = INT_MIN;
	
	for (int i = 0; i < n; i++) {
		int len = height[i];
		
		if (nextSmaller[i] == -1) {
			nextSmaller[i] = n;
		}
		
		int wid = nextSmaller[i] - prevSmaller[i] - 1;
		
		int newArea = len * wid;
		
		area = max(area, newArea);
	}
	
	return area;
}

// TC = O(N * M)
// SC = O(M)
int maximalAreaOfSubMatrixOfAll1(vector<vector<int>> &M, int n, int m){
	// store the height of each column
	vector<int> height(m, 0);
	
	int ans = INT_MIN;
	
	for (int row = 0; row < n; row++) {
		for (int col = 0; col < m; col++) {
			
			if (M[row][col] == 1) {
				height[col]++;
			}
			else height[col] = 0;
		}
		ans = max(ans, getLargestArea(height));
	}
	return ans;
}