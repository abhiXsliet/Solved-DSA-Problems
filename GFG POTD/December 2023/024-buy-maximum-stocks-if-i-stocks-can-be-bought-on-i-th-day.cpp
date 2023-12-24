// https://www.geeksforgeeks.org/problems/buy-maximum-stocks-if-i-stocks-can-be-bought-on-i-th-day/1



//{ Driver Code Starts
/* Driver program to test above function */

#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
public:
    int buyMaximumProducts(int n, int k, int price[]){
        vector<pair<int, int>> priceIdx(n);
        
        for (int i = 0; i < n; i++) {
            priceIdx[i].first  = price[i];
            priceIdx[i].second = i + 1;
        }
        
        // sort a/c to stock price
        sort(begin(priceIdx), end(priceIdx));
        
        int stocksCnt = 0;
        
        for (auto it : priceIdx) {
            if(k >= it.first) {
                int buyAllowed  = floor(k / it.first);
                int buyPossible = min(it.second, buyAllowed);
            
                k         -= it.first * buyPossible;
                stocksCnt += buyPossible;
            }
        }
        
        return stocksCnt;
    }
};


//{ Driver Code Starts.
int main()
{
	int t;
	cin>>t;
	while(t--)
	{
	    int n, k;
	    cin >> n >> k;
	    int price[n];
	    for(int i = 0 ; i < n; i++){
	        cin >> price[i];
	    }
	    Solution ob;
	    int ans = ob.buyMaximumProducts(n, k, price);
	    cout << ans<<endl;
	}
	return 0;
}

// } Driver Code Ends