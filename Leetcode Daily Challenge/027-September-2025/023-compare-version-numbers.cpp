// https://leetcode.com/problems/compare-version-numbers/




#include <bits/stdc++.h>
using namespace std;

class Solution {
private:
    vector<int> getRevision(string &s) {
        vector<int> rev;
        istringstream ss(s);
        string str;
        while (getline(ss, str, '.')) {
            rev.push_back(stoi(str));
        }
        return rev;
    }

    // TC : O(M + N)    // Where M = v1.length() && N = v2.length()
    // SC : O(M + N)
    int way_1(string &v1, string &v2) {
        vector<int> rev1 = getRevision(v1);
        vector<int> rev2 = getRevision(v2);

        int i = 0, j = 0;
        while (i < rev1.size() || j < rev2.size()) {
            int val1 = (i < rev1.size() ? rev1[i] : 0);
            int val2 = (j < rev2.size() ? rev2[j] : 0);
            if (val1 < val2) {
                return -1;
            } else if (val1 > val2) {
                return 1;
            }
            i ++, j ++;
        }
        return 0;
    }

    // TC : O(M + N)
    // SC : O(1)
    int way_2(string &v1, string &v2) {
        int m = v1.length(), n = v2.length();

        int val1 = 0, val2 = 0;
        for (int i = 0, j = 0; i < m || j < n; i ++, j ++) {
            while (i < m && v1[i] != '.') {
                val1 = val1 * 10 + (v1[i] - '0');
                i ++;
            }
            while (j < n && v2[j] != '.') {
                val2 = val2 * 10 + (v2[j] - '0');
                j ++;
            }
            if (val1 < val2) return -1;
            else if (val1 > val2) return 1;
            val1 = val2 = 0;
        }
        return 0;
    }
public:
    int compareVersion(string version1, string version2) {
        // return way_1(version1, version2);
        return way_2(version1, version2);
    }
};