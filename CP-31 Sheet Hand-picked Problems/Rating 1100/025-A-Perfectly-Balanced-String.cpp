// https://codeforces.com/problemset/problem/1673/B




#include <bits/stdc++.h>
using namespace std;
using ll = long long;

bool isBalanced(string &s) {
    int n = s.length();
    unordered_map<char, int> mpp;
    for (char &ch : s) mpp[ch] ++;

    int k = mpp.size();
    unordered_map<char, int> kSized;
    int i = 0, j = 0;
    while (j < n) {
        kSized[s[j]] ++;
        if (j - i + 1 == k) {
            if (kSized.size() < k) {
                return false;
            }
            kSized[s[i]] --;
            if (!kSized[s[i]]) kSized.erase(s[i]);
            i ++;
        }
        j ++;
    }
    return true;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    

    int t;
    cin >> t;
    while (t --) {
        string s;
        cin >> s;
        if (isBalanced(s)) cout << "Yes";
        else cout << "No";
        cout << "\n";
    }
    return 0;
}