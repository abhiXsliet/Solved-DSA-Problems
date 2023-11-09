// https://www.codingninjas.com/studio/problems/factorial-of-a-large-number_1115471


#include <bits/stdc++.h>
using namespace std;

string calculateFactorial(int n)
{
    vector<int> result;
    result.push_back(1);

    for (int num = 2; num <= n; num++) {
        int carry = 0;
        for (int j = 0; j < result.size(); j++) {
            int val = result[j] * num + carry;

            result[j] = val % 10;
            carry     = val / 10;
        }

        while (carry != 0) {
            result.push_back(carry % 10);
            carry /= 10;
        }
    }

    reverse(result.begin(), result.end());

    string ans = "";
    for (int& i : result) {
        string str = to_string(i);
        ans += str;
    }

    return ans;
}