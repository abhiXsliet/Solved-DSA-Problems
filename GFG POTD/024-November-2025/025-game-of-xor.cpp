// https://www.geeksforgeeks.org/problems/game-of-xor1541/1/




#include <bits/stdc++.h>
using namespace std;

class Solution {
  public:
    int subarrayXor(vector<int>& A) {
        int N = A.size();
        if(N%2==0) return 0;
        int ans=A[0];
        for(int i=2;i<N;i+=2){
            ans^=A[i];
        }
        return ans;
    }
};