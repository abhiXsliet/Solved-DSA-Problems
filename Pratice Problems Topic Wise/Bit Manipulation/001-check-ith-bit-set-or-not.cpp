// check the ith bit set or not?

#include <bits/stdc++.h>
using namespace std;

bool check(int n, int k) {
    // left shif the mask k-1 no. of times
    int mask = 1;
    mask = mask << (k-1);
    return (n & mask);
}

int main() {
    int n, i;
    cout << "Enter n, i (space separated) : ";
    cin >> n >> i;

    if(check(n, i)) 
        cout << "Yes" << endl;
    else 
        cout << "No" << endl;

    return 0;
}