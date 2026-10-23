class Solution {
public:
    bool f(int j, string & p, int m){
        for(int i = j;i < m; i++){
            if(p[i] != '*') return false;
        }
        return true;
    }
    bool solve(int i , int j , string & s, string & p, int n, int m, vector<vector<int>>&dp){
        // base case here
        if(i >= n && j >= m) return true;
        if(j >= m && j < n) return false;
        if(i >= n && j < m) return f(j, p, m);

        if(dp[i][j] != -1) return dp[i][j];
        if(s[i] == p[j] || p[j] == '?'){
            return dp[i][j] = solve(i + 1, j + 1, s, p, n, m, dp);
        }
        else if(p[j] == '*'){
           return dp[i][j] =  solve(i + 1, j, s, p, n, m, dp) || solve(i, j + 1, s, p, n, m, dp);
        }
        
        return  false;
    }
    bool isMatch(string s, string p) {
        int n = s.size();
        int m = p.size();
        vector<vector<int>>dp(n + 1, vector<int>(m + 1, -1));
        return  solve(0, 0, s, p, n, m, dp);
    }
};