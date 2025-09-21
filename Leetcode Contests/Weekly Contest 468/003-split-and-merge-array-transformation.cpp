// https://leetcode.com/contest/weekly-contest-468/problems/split-and-merge-array-transformation/




#include <bits/stdc++.h>
using namespace std;

class Solution {
private:
    string vecToStr(const vector<int>& v) {
        string s;
        for (int x : v) {
            s += to_string(x) + ",";
        }
        return s;
    }
public:
    int minSplitMerge(vector<int>& nums1, vector<int>& nums2) {
        int n = nums1.size();
        
        string target = vecToStr(nums2);

        queue<pair<vector<int>, int>> q;
        q.push({nums1, 0});

        unordered_set<string> visited;
        visited.insert(vecToStr(nums1));

        while (!q.empty()) {
            auto [cur, steps] = q.front();
            q.pop();

            string curStr = vecToStr(cur);
            if (curStr == target) return steps; 

            for (int L = 0; L < n; L ++) {
                for (int R = L; R < n; R ++) {
                    vector<int> seg(cur.begin() + L, cur.begin() + R + 1);

                    vector<int> rem;
                    for (int i = 0; i < L; i++) rem.push_back(cur[i]);
                    for (int i = R + 1; i < n; i++) rem.push_back(cur[i]);

                    for (int pos = 0; pos <= (int)rem.size(); pos ++) {
                        vector<int> nxt = rem;
                        nxt.insert(nxt.begin() + pos, seg.begin(), seg.end());

                        string nxtStr = vecToStr(nxt);
                        if (!visited.count(nxtStr)) {
                            visited.insert(nxtStr);
                            q.push({nxt, steps + 1});
                        }
                    }
                }
            }
        }
        return -1;
    }
};