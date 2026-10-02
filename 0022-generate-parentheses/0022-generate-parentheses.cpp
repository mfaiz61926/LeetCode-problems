class Solution {
public:
    vector<string>res;

    void solve(int n, string & cur , int open, int closed){
        if(cur.size() == 2*n){
            res.push_back(cur);
            return;
        }

        if(open < n){
            cur.push_back('(');
            solve(n, cur, open+1, closed);
            cur.pop_back();
        }

        if(closed < open){
            cur.push_back(')');
            solve(n, cur, open, closed+1);
            cur.pop_back();
        }
    }
    vector<string> generateParenthesis(int n) {
        string cur = "";
        solve(n, cur , 0, 0);
        return res;
    }
};