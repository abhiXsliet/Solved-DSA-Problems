// https://practice.geeksforgeeks.org/problems/reverse-a-string/1


//{ Driver Code Starts
//Initial Template for C++

#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
//User function Template for C++
class Solution
{
    private:
    // TC = O(N)
    string solve_1(string str) {
        int n = str.length();
        int i = 0, j = n -1;
        while(i <= j) {
            char temp = str[i];
            str[i] = str[j];
            str[j] = temp;
            i++, j--;
        }
        return str;
    }
    
    // TC = O(N)
    string solve_2(string str) {
        int n = str.length();
        int i = 0, j = n -1;
        while(i <= j) {
            swap(str[i++], str[j--]);
        }
        return str;
    }
    
    public:
    string reverseWord(string str)
    {
        // return solve_1(str);
        
        return solve_2(str);
    }
};



//{ Driver Code Starts.

int main() {
	
	int t;
	cin>>t;
	while(t--)
	{
    	string s;
    	cin >> s;
    	Solution ob;
    	cout << ob.reverseWord(s) << endl;
	}
	return 0;
	
}


// } Driver Code Ends