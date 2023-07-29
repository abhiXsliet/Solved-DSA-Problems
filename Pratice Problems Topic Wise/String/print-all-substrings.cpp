#include <iostream>
#include <string>
#include <unordered_set>
using namespace std;

string subString(string& str) {
    int n = str.size();
    for(int len = 1; len <= n; len++) {
        for(int i = 0; i <= n - len; i++) {
            
            int j = len + i - 1;
            for(int k = i; k <= j; k++) {
                cout << str[k];
            }
            cout << endl;
        }
    }
}

int main() {
    string str = "leetcode";

    subString(str);

    cout << endl;
    return 0;
}
