class Solution {
public:
    vector<string>ans;
    string ss = "()";
    int nn;

    bool valid(string &s){
        stack<int>st;
        for(int i = 0; i < s.size(); i++){
            if(s[i] == '(') st.push(s[i]);
            else{
                if(st.empty()) return false;
                st.pop();
            }
        }
        return st.empty();
    }

    void solve(int i, string &s){
        if(i == 2*nn){
            if(valid(s)){
                ans.push_back(s);
            }
            return;
        }
        solve(i + 1, s);
        if(s[i] == '(') s[i] = ')';
        else s[i] = '(';
        solve(i + 1, s);
    }
    vector<string> generateParenthesis(int n) {
        nn = n;
        string s = "";
        for(int i = 0; i < n; i++) s += ss;
        solve(0, s);
        return ans;
    }
};