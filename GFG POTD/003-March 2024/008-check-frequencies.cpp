// https://www.geeksforgeeks.org/problems/check-frequencies4211/1



//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends

//User function template for C++
class Solution{
private:
    bool checkFreq(vector<int>& freq) {
        int curr = -1;
        for (int i = 0; i < freq.size(); i++) {
            if (freq[i] == 0) continue;
            else if (curr == -1) curr = freq[i];
            else if (curr != freq[i]) return false;
        }
        return true;
    }
public:	
    // TC : O(N)
    // SC : O(N)
	bool sameFreq(string s)
	{
	    vector<int> freq(26, 0);
	    for(char& ch : s) {
	        freq[ch - 'a']++;
	    }
	    
	    // if all the freq are same
	    if (checkFreq(freq)) 
	        return true;
	        
	    for (int i = 0; i < freq.size(); i++) { // O(26)
	        if (freq[i] != 0) {
	            freq[i] --;
	            
	            if (checkFreq(freq))
	                return true;
	           
	            freq[i] ++;
	        }
	    }
	    
	    return false;
	}
};


//{ Driver Code Starts.
int main(){
    int t;
    cin>>t;
    while(t--)
    {
        string s;
        cin>>s;
        Solution ob;
        cout<<ob.sameFreq(s)<<endl;
    }
}



// } Driver Code Ends