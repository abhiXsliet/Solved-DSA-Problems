// https://leetcode.com/problems/powx-n/description/



class Solution {
public:
    double myPow(double x, int n) {
        long long pow = n;
        if(n < 0) pow = (-1)*pow;
        double ans = 1;
        while(pow) {
            if(pow % 2) {
                ans = ans * x;
                pow --;

            } else {
                x = x*x;
                pow = pow/2;
            }
        }

        if(n < 0) 
            ans = (double)(1.0) / (double)(ans);

        return ans;
    }
};