// https://codeforces.com/problemset/problem/1511/C




#include<bits/stdc++.h>
using namespace std;
using ll = long long;

vector<int> processQuery(vector<int> &colors, vector<int> &queries, int n, int q) {
    unordered_map<int, int> mpp;
    for (int i = 0; i < n; i ++) {
        if (!mpp.count(colors[i])) 
            mpp[colors[i]] = (i + 1);
    }
    
    vector<int> ans;
    for (int query : queries) {
        int firstOccIdx = mpp[query];
        ans.push_back(firstOccIdx);

        for (auto &it : mpp) {
            if (it.second < firstOccIdx) {
                it.second += 1;
            }
        }

        mpp[query] = 1;
    }
    return ans;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    

    int n, q;
    cin >> n >> q;
    vector<int> colors(n);
    for (int &val : colors) cin >> val;
    vector<int> queries(q);
    for (int &val : queries) cin >> val;

    vector<int> ans = processQuery(colors, queries, n, q);
    for (int &val : ans) cout << val << " ";
    cout << "\n";

    return 0;
}