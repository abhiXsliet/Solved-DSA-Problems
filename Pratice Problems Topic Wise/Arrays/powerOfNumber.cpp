#include<bits/stdc++.h>
using namespace std;
#include<math.h>

// reversed number as the power of number
long long solveRec(long long N, long long R) {
    if (R == 0) return 1;

    long long num  = (N * solveRec(N, R-1))%1000000007;
    return num;
}

// Reverse the number
long long revN(long long n ) {

    long long reversed = 0;
    while(n != 0) {
        long long digit = n % 10;
        reversed = reversed * 10 + digit;
        n = n / 10;
    }
    return reversed;
}

int main() {
    long long n = 12;

    cout << "Reversed Number " << revN(n) << endl;
    long long rev = revN(n);

    cout << solveRec(n, rev);

    cout << endl;
    return 0;
}