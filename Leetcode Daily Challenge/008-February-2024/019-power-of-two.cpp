// https://leetcode.com/problems/power-of-two/



#include <bits/stdc++.h>
using namespace std;

class Solution {
private:
    // TC : O(N)
    bool solve_1(int n) {
        int ans = 1;
        for (int i = 0; i <= 30; i++){
            if(ans == n){
                return true;
            }
            if(ans < INT_MAX/2)
                ans = ans*2;
        }
        return false;
    }

    // TC : O(N)
    bool solve_2(int n) {
        for(int i = 0; i <= 30; i++) {
            
            int ans = pow(2,i);
            
            if(ans == n){
                return true;
            }
        }
        return false;
    }


    // TC = O(N)
    bool solve_3(long long n) {
        while(n != 0) {
            if (n == 0 || n == 1) return 1;
            
            if(n % 2 == 0) n /= 2;
            else return 0;
        }
        return 0;
    }
    
    // TC = O(1)
    bool solve_4(long long n) {
        if (n == 0) return 0;
        else if ( (n & (n -1)) == 0 ) return 1;
        else return 0;
    }
public:
    bool isPowerOfTwo(int n) {
        // return solve_1(n);

        // return solve_2(n);

        // return solve_3(n);

        return solve_4(n);
    }
};