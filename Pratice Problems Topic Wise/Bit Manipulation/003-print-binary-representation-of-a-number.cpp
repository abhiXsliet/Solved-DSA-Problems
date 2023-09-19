#include <bits/stdc++.h>
using namespace std; 

// function to convert decial to binary
void solve1(int num) {
    if (num > 1)
        solve1 (num / 2);

    cout << num % 2 ;
}

void solve2(int num) {
    if (num > 1) 
        solve2(num >> 1);
    
    cout << (num & 1);
}

void solve3(int num) {
    // convert the number to binary of given bit
    bitset<8> b(num);
    cout << b;
}

void func1(int num) {
    while(num != 0) {
        num = num / 2;
        cout << num % 2 ;
    }
}

void func2(int num) {
    long i;
    cout << "in 32-bit  : 0";
    for (i = 1 << 30; i > 0; i /= 2) {
        if ((num & i) != 0) {
            cout << "1" ;
        }
        else cout << "0" ;
    }
}

int main() {
    int n = 2;
    cout << "Binary representation " << "of "  << n << " " ;
    
    solve1(n);
    // solve2(n);
    // solve3(n);
    // func1(n);
    // func2(n);

    cout << endl;
    return 0;
}