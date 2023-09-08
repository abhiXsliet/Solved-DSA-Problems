// find the element at given row and column of a pascle triangle?
// find all the elements of the given row of a pascle triangle?
// print whole pascle triangle?

#include <iostream>
#include <vector>
using namespace std;

// TC = O(col) ~ O(N)
// SC = O(1)
long long get_nCr(int n, int col) {
    long long res = 1;
    for (int i = 0; i < col; i++) {
        res = res * (n - i);
        res = res / (i + 1);
    }
    return res;
}

// TC = O(row * col) ~ O(N^2)
// SC = O(1)
vector<int> generate_nth_row_brute(int r) {
    vector<int> ans;
    
    // for(int i = 0; i < r; i++) {
    //     ans.push_back( get_nCr(r-1, i) );
    // }

    for(int col = 1; col <= r; col++) {
        ans.push_back( get_nCr(r-1, col-1) );
    }
    return ans;
}

// TC = O(row) ~ O(N)
// SC = O(1)
vector<int> generate_nth_row_optimal(int row) {
    long long ans = 1;
    vector<int> res;

    res.push_back(1);
    for (int i = 1; i < row; i++) {
        ans = ans * (row - i);
        ans = ans / i;
        res.push_back(ans);
    }
    return res;
}

// TC = O(row * col * col) ~ O(N^3)
// SC = O(1)
vector<vector<int>> pascleTriangle_brute(int row) {
    vector<vector<int>> res;
    for (int i = 1; i <= row; i++) {
        vector<int> temp;
        for (int j = 1; j <= i; j++) {
            // TC = O(col)
            temp.push_back( get_nCr(i-1, j-1) );
        }
        res.push_back( temp );
    }
    return res;
}

// TC = O(N^2)
// SC = O(1)
vector<vector<int>> pascleTriangle_Optimal(int row) {
    vector<vector<int>> res;
    for (int i = 1; i <= row; i++) {
        res.push_back( generate_nth_row_optimal(i) );
    }
    return res;
}

int main() {
    int row, col;
    cout << "\nEnter row and col (space separated) : ";
    cin >> row >> col;
    cout <<"\nPrinting element at " << row << "-row & " << col << "-col : "
         << get_nCr(row-1, col-1) << endl;

    cout << "\nBrute - Printing all elements at " << row << "-row : ";
    vector<int> generatedElement = generate_nth_row_brute(row);
    for (int& i : generatedElement) 
        cout << i << " ";
    cout << endl;

    cout << "\nOptimal-Printing all elements at " << row << "-row : ";
    vector<int> generatedElementOptimal = generate_nth_row_optimal(row);
    for (int& i : generatedElementOptimal) 
        cout << i << " ";
    cout << endl;

    cout << "\nBrute Printing Pascle Triangle " << endl;
    vector<vector<int>> printPascal = pascleTriangle_brute(row);
    for (auto& i : printPascal) {
        for (auto& j : i) 
            cout << j << " ";
        cout << endl;
    }
    cout << endl;


    cout << "Optimal Printing Pascle Triangle " << endl;
    vector<vector<int>> printPascalOptimal = pascleTriangle_Optimal(row);
    for(auto &i : printPascalOptimal) {
        for (auto &j : i)  
            cout << j << " ";
        cout << endl;
    }
    cout << endl;


    cout << endl;
    return 0;
}