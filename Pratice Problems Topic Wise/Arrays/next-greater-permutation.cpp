// https://www.codingninjas.com/studio/problems/next-greater-permutation_6929564


#include <bits/stdc++.h>
using namespace std;

vector<int> solve_brute(vector<int>& A) {
    // Step 1: Find all possible permutations of elements present and store them.

    // Step 2: Search input from all possible permutations.

    // Step 3: Print the next permutation present right after it.

    // TC = O(N! * N)
    // SC = O(N) recursive depth
}

vector<int> solve_better(vector<int>& A) {
    next_permutation(begin(A), end(A));
    return A;
}

vector<int> solve_optimal(vector<int>& A) {
    int n = A.size();

    int idx = -1;
    for (int i = n - 2; i >= 0; i--) {
        if (A[i] < A[i + 1]) {
            idx = i;
            break;
        }
    }

    if (idx == -1) {
        reverse(begin(A), end(A));
        return A;
    }

    for (int i = n - 1; i >= 0; i--) {
        if (A[i] > A[idx]) {
            swap(A[i], A[idx]);
            break;
        }
    }

    reverse(begin(A) + idx + 1, end(A));
    return A;
}

vector<int> nextGreaterPermutation(vector<int> &A) {
    // return solve_brute(A);
    // return solve_better(A);
    
    return solve_optimal(A);
}