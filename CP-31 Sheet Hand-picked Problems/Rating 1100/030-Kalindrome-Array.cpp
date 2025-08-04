// https://codeforces.com/problemset/problem/1610/B




#include<bits/stdc++.h>
using namespace std;
using ll = long long;

bool isPalindrome(vector<int> &arr) {
    int i = 0, j = arr.size() - 1;
    while (i <= j) {
        if (arr[i] != arr[j]) {
            return false;
        }
        i ++, j --;
    }
    return true;
}

bool isKalindrome(vector<int> &arr, int n) {
    int i = 0, j = n - 1;
    while (i <= j) {
        if (arr[i] != arr[j]) {
            break;
        }
        i ++, j --;
    }

    int removalEle1 = arr[i], removalEle2 = arr[j];

    vector<int> temp;
    for (int &val : arr) {
        if (val != removalEle1) {
            temp.push_back(val);
        }
    }

    if (isPalindrome(temp)) return true;

    temp.clear();
    for (int &val : arr) {
        if (val != removalEle2) {
            temp.push_back(val);
        }
    }

    if (isPalindrome(temp)) return true;

    return false;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    

    int t;
    cin >> t;
    while (t --) {
        int n;
        cin >> n;
        vector<int> vec(n);
        for (int &val : vec) cin >> val;
        if (isKalindrome(vec, n)) cout << "Yes";
        else cout << "No";
        cout << "\n";
    }
    return 0;
}