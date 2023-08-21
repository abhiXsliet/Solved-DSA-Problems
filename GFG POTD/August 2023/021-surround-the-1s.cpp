// https://practice.geeksforgeeks.org/problems/surround-the-1s2505/1


//{ Driver Code Starts

#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends

class Solution {
public:
    int Count(vector<vector<int> >& matrix) {
        int m = matrix.size();
        int n = matrix[0].size();
        int ans = 0;
        
        int row[] = {-1, -1, 0, 1, 1, 1, 0, -1};
        int col[] = {0, 1, 1, 1, 0, -1, -1, -1};
        
        for(int i = 0; i < m; i++) {
            for(int j = 0; j < n; j++) {
                if(matrix[i][j] == 1) {
                    int cnt = 0;
                    for(int k = 0; k < 8; k++) {
                        int new_row = i + row[k];
                        int new_col = j + col[k];
                        
                        if(new_row >= 0 && new_row < m && new_col >= 0 
                            && new_col < n && matrix[new_row][new_col] == 0) {
                            cnt++;
                        }
                    }
                    if(cnt > 0 && cnt % 2 == 0) ans++;
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
		vector<vector<int>> matrix(n, vector<int>(m,0));
		for(int i = 0; i < n; i++){
			for(int j = 0; j < m; j++){
				cin >> matrix[i][j];
			}
		}
		Solution ob;
		int ans = ob.Count(matrix);
		cout << ans <<"\n";
	}
	return 0;
}
// } Driver Code Ends