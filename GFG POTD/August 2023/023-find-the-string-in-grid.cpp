// https://practice.geeksforgeeks.org/problems/find-the-string-in-grid0111/1



//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
private:
    // TC = O(n*m*k)
    // SC = O(1)
    bool dfs(vector<vector<char>>& grid, string word, int i, int j, int rDir, int cDir, int index) {
        if(index >= word.length())
            return true;
            
        if(i < 0 || i >= grid.size() || j < 0 || j >= grid[0].size())
            return false;
            
        if(grid[i][j] == word[index]) {
            return dfs(grid, word, i+rDir, j+cDir, rDir, cDir, index+1);
        } else {
            return false;
        }
    }

public:
	vector<vector<int>>searchWord(vector<vector<char>>grid, string word){
	    
	    vector<vector<int>> ans;
	    int n = grid.size();
	    int m = grid[0].size();
	    
	    int rDir[8] = {-1, -1, 0, 1, 1, 1, 0, -1};
	    int cDir[8] = {0, 1, 1, 1, 0, -1, -1, -1};
	    
	    for(int i = 0; i < n; i++) {
	        for(int j = 0; j < m; j++) {
	            if(grid[i][j] == word[0]) {
	                
	                for(int k = 0; k < 8; k++) {
	                    if( dfs(grid, word, i+rDir[k], j+cDir[k], rDir[k], cDir[k], 1) ) {
	                        ans.push_back({i, j});
	                        break;
	                    }
	                }
	                
	            }
	        }
	    }
	    
	    return ans;
	}
};

//{ Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		int n, m;
		cin >> n >> m;
		vector<vector<char>>grid(n, vector<char>(m,'x'));
		for(int i = 0; i < n; i++){
			for(int j = 0; j < m; j++)
				cin >> grid[i][j];
		}
		string word;
		cin >> word;
		Solution obj;
		vector<vector<int>>ans = obj.searchWord(grid, word);
		if(ans.size() == 0)
		{
		    cout<<"-1\n";
		}
		else
		{
		    for(auto i: ans){
			for(auto j: i)
				cout << j << " ";
			cout << "\n";
		    }
		}
		
		
	}
	return 0;
}
// } Driver Code Ends