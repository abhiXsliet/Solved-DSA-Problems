// https://codeforces.com/problemset/problem/1917/B




#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int cntDistinct(string &s, int n) {
    int ans = 0;
    unordered_set<int> st;
    for (char &ch : s) {
        st.insert(ch - 'a');
        ans += st.size();
    }
    return ans;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    cin >> t;
    while (t --) {
        int n;
        cin >> n;
        string s;
        cin >> s;
        cout << cntDistinct(s, n) << endl;
    }
    
    return 0;
}