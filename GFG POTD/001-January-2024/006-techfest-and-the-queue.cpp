// https://www.geeksforgeeks.org/problems/techfest-and-the-queue1044/1



//{ Driver Code Starts

#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends

class Solution {
private:
    // TC : O((b-a+1) * sqrt(num) * log(num)) ~= O(b*sqrt(b)*log(b)) where max. 'num' could be 'b'
    // SC : O(1)
    int getPoints(int num) {
        int points = 0;
        int temp   = num;
        for (int i = 2; i*i <= num; i++) {
            while(num % i == 0) {
                num /= i;
                points++;
            }
        }
        if (num != 1) {
            points++;
        }
        return points;
    }
public:
	int sumOfPowers(int a, int b){
	    int res = 0;
	    for (int i = a; i <= b; i++) {
	        res += getPoints(i);
	    }
	    return res;
	}
};

//{ Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		int a, b;
		cin >>  a >> b;
		Solution obj;
		int ans = obj.sumOfPowers(a, b);
		cout << ans <<"\n";
	}
	return 0;
}
// } Driver Code Ends