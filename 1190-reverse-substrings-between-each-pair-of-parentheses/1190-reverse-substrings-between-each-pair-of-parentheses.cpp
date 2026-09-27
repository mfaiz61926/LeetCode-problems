class Solution {
public:
    string reverseParentheses(string s) {
        int n = s.size();
        string res = "";
        stack<char>st;

        for(int i = 0; i < n; i++){
            if(s[i] == ')'){
                string temp = "";
                while(!st.empty() && st.top() != '('){
                    char ch = st.top();
                    st.pop();
                    temp += ch;
                }
                st.pop(); // remove (
                if(st.empty() && i >= n - 1) return temp;
                for(auto &c : temp) st.push(c);

            }else{
                st.push(s[i]);
            }
        }
        while(!st.empty()){
            res += st.top();
            st.pop();
        }
        reverse(res.begin(), res.end());
        return res;
    }
};