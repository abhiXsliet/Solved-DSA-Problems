// Find all the subsets using bit manipulations



#include <bits/stdc++.h>
using namespace std;

int main() {

    int arr[3] = {1, 2, 3};
    int power = pow(2, 3);
    vector<vector<int>> ans;

    for (int c = 0; c < power; c++) {
        vector<int> temp;
        for (int i = 0; i < 3; i++) {
            int power2 = pow(2, i);
            
            if (c & power2) {
                temp.push_back(arr[i]);
            }   
        }
        ans.push_back(temp);
    }
    for (auto& i : ans) {
        for (auto& j : i) {
            cout << j << " ";
        }
        cout << endl;
    }

    return 0;
}