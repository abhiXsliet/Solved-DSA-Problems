// https://www.geeksforgeeks.org/problems/check-if-string-is-rotated-by-two-places-1587115620/1



//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;
// } Driver Code Ends

class Solution
{
    private:
    // TC = O(N)
    // SC = O(N)
    bool solve_brute(string& str1, string& str2) {
        int n = str1.length();
        if (n == 2) str1 == str2;
        
        string s1, s2;
        
        // fill string s1 starting from the char at index-2 of str1
        // s1 += str1.substr(2);    // stl
        
        for (int i = 2; i < n; i++) s1 += str1[i];
        
        // remaining part of s1
        s1 += str1[0];
        s1 += str1[1];
        
        // fill string s2 after filling two char from the back of str1
        s2 += str1[n - 2];
        s2 += str1[n - 1];
        
        // s2 += str1.substr(0, n - 2); // stl
        
        for (int i = 0; i < n - 2; i++) s2 += str1[i];
            
        // check if s1 or s2 equals to str2 then return true 
        if (s1 == str2 || s2 == str2) return true;
        return false;
    }
    
    // TC = O(N)
    // SC = O(1)
    bool solve_optimal(string& str1, string& str2) {
        int n = str1.length();
        
        if (n == 2) return str1 == str2;
        
        for (int i = 0; i < n; i++) {
            if ( (str1[(n-2+i) % n] == str2[i]) || 
                 (str1[(i + 2) % n] == str2[i]) ) {
                
                continue;     
            }
            else return false;
        }
        
        return true;
    }
    public:
    //Function to check if a string can be obtained by rotating
    //another string by exactly 2 places.
    bool isRotated(string str1, string str2)
    {
        // return solve_brute(str1, str2);
        
        return solve_optimal(str1, str2);
    }

};


//{ Driver Code Starts.

int main() {
	
	int t;
	cin>>t;
	while(t--)
	{
		string s;
		string b;
		cin>>s>>b;
		Solution obj;
		cout<<obj.isRotated(s,b)<<endl;
	}
	return 0;
}

// } Driver Code Ends