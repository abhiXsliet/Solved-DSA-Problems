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
        if (i.empty())
            cout << "{}" << " ";
        else 
        {
        
        /* 
            cout << "{";
            for (size_t j = 0; j < i.size(); j++) {
                cout << i[j];
                if (j < i.size() - 1) {
                    cout << " ";
                }
            }
            cout << "}";
               
        */  

            // alternate way of doing above logic
            cout << "{";
            copy(i.begin(), i.end(), ostream_iterator<int>(cout, " "));
            cout << "\b}"; // Remove the trailing space and add a closing curly brace
        }
        cout << endl;
    }

    return 0;
}