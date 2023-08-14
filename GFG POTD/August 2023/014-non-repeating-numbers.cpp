// https://practice.geeksforgeeks.org/problems/finding-the-numbers0215/1


//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution
{
public:
    vector<int> singleNumber(vector<int> nums) 
    {
        vector<int> result;
        
        int xorAns = 0;
        for(int i = 0; i < nums.size(); i++) 
            xorAns = xorAns^nums[i];
            
        // find the right most bit of distinct number 
        // formula => x  = x & ~(x-1)
        // for 3, 4 right most set bit => 001
        xorAns = xorAns & ~(xorAns - 1);
        
        // separate numbers -> & with numbers, for different result
        // for e.g., separating 3 4
        
        // let distinct number is x, y
        int x = 0;
        int y = 0;
        for(int i = 0; i < nums.size(); i++) {
            if(xorAns & nums[i]) {
                x ^= nums[i];
            } else {
                y ^= nums[i];
            }
        }
        
        if(x > y) {
            result.push_back(y);
            result.push_back(x);
        } else {
            result.push_back(x);
            result.push_back(y);
        }
        
        return result;
    }
};

//{ Driver Code Starts.
int main(){
    int T;
    cin >> T;
    while(T--)
    {
    	int n; 
    	cin >> n;
    	vector<int> v(2 * n + 2);
    	for(int i = 0; i < 2 * n + 2; i++)
    		cin >> v[i];
    	Solution ob;
    	vector<int > ans = ob.singleNumber(v);
    	for(auto i: ans)
    		cout << i << " ";
    	cout << "\n";
    }
	return 0;
}
// } Driver Code Ends