class Solution {
private:
    // TC : O(N)
    // SC : O(N)
    string solve_approach_1(string path) {
        stack<string> stk;
        
        stringstream ss(path);
        string token = "";

        while (getline(ss, token, '/')) {
            if (token == "" || token == ".") 
                continue;
            
            if (token != "..")
                stk.push(token);
            else if (!stk.empty()) 
                stk.pop();
        }

        if (stk.empty()) 
            return "/";

        string res = "";
        while (!stk.empty()) {
            res = "/" + stk.top() + res;
            stk.pop();
        }

        return res;
    }

    // TC : O(N)
    // SC : O(N)
    string solve_approach_2(string path) {
        stack<string> stk;
        
        for (int i = 0; i < path.size(); i++) {
            if (path[i] == '/') continue;

            string token;
            while (i < path.size() && path[i] != '/') {
                token += path[i];
                i ++;
            }

            if (token == ".") 
                continue;
            else if (token == "..") {
                if (!stk.empty()) 
                    stk.pop();
            } 
            else 
                stk.push(token);
        }

        if (stk.empty()) 
            return "/";

        string res = "";
        while (!stk.empty()) {
            res = "/" + stk.top() + res;
            stk.pop();
        }

        return res;
    }

    // TC : O(N)
    // SC : O(N)
    string solve_approach_3(string path) {
        deque<string> tokens;
        
        stringstream ss(path);
        string token;
        while (getline(ss, token, '/')) {
            if (token == "" || token == ".") 
                continue;

            if (token != "..") {
                tokens.push_back(token);
            }
            else if (!tokens.empty()) {
                tokens.pop_back();
            }
        }

        if (tokens.empty()) 
            return "/";

        string res;
        while (!tokens.empty()) {
            res += "/" + tokens.front();
            tokens.pop_front();
        }
        return res;
    }

    // TC : O(N)
    // SC : O(N)
    string solve_approach_4(string path) {
        vector<string> tokens;
        
        stringstream ss(path);
        string token;
        while (getline(ss, token, '/')) {
            if (token == "" || token == ".") 
                continue;

            if (token != "..") {
                tokens.push_back(token);
            }
            else if (!tokens.empty()) {
                tokens.pop_back();
            }
        }

        if (tokens.empty()) 
            return "/";

        string res;
        for (auto& token : tokens) {
            res += "/" + token;
        }
        return res;
    }
public:
    string simplifyPath(string path) {
        // return solve_approach_1(path);   

        // return solve_approach_2(path);      // without getline() fn.

        // return solve_approach_3(path);      // using deque

        return solve_approach_4(path);      // using vector
    }
};