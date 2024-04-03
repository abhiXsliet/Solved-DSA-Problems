// https://www.codechef.com/problems/ABCC


#include <bits/stdc++.h>
using namespace std;

bool solve() {
    int n;
    cin>>n;
    string s, str;
    cin>>s>>str;
    
    vector<int> a_indices, b_indices, c_indices;
    
    for (int i = 0; i < n; i++) {
        if (s[i] == 'a' && str[i] == 'c') a_indices.push_back(i);
        else if (s[i] == 'b' && str[i] == 'b') b_indices.push_back(i);
        else if (s[i] == 'c' && str[i] == 'a') c_indices.push_back(i);
        else if (s[i] == str[i]) continue;
        else return false;          // ba ab
    }
    
    if (a_indices.size() != c_indices.size()) 
        return 0;
        
    for (int i = 0; i < a_indices.size(); i++) {
        auto it = upper_bound(begin(b_indices), end(b_indices), a_indices[i]);
        if (it == b_indices.end()) return false;
        if ((*it) > c_indices[i]) return false;
    }

    return true;
}

int main() {
	int t;
	cin>>t;
	while(t--) {
	    if(solve())
	        cout << "Yes" << "\n";
	    else 
	        cout << "No" << "\n";
	}
	return 0;
}
