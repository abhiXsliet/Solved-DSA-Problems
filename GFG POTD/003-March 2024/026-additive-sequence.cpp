// https://www.geeksforgeeks.org/problems/additive-sequence/1



//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function template for C++

class Solution {
  private:
    string addStrings(string num1, string num2){
        int i = num1.length() - 1;
        int j = num2.length() - 1;
        string output = "";
        int carry = 0;
        while(i >= 0 or j >= 0 or carry){
            int sum = carry;
            if(i >= 0){
                sum += num1[i--] - '0';
            }
            if(j >= 0){
                sum += num2[j--] - '0';
            }
            int rem = sum%10;
            carry = sum/10;
            output.push_back(rem + '0');
        }
        reverse(output.begin(), output.end());
        return output;
    }
  public:
    // TC : O(N^3)
    // SC : O(N)
    bool isAdditiveSequence(string num) {
        int n = num.length();
        
        for(int i = 1; i <= n/2; i++){
            for(int j = 1; max(i,j) <= n-i-j; j++){
                string first  = num.substr(0,i);
                string second = num.substr(i,j);
                
                if(first.length() > 1  && first[i]  == '0')  break;
                if(second.length() > 1 && second[i] == '0') break;
                
                int start = i + j;
                string sum;
                while(start < n){
                    sum = addStrings(first, second);
                    if(start + sum.length() > n || sum != num.substr(start, sum.length())){
                        break;
                    }
                    first  = second;
                    second = sum;
                    start += sum.length();
                }
                if(start == n){
                    return true;
                }
            }
        }
        return false;
    }
};


//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;

    Solution sol;

    while (t--) {
        string s;
        cin >> s;

        bool result = sol.isAdditiveSequence(s);
        cout << result << endl;
    }

    return 0;
}

// } Driver Code Ends