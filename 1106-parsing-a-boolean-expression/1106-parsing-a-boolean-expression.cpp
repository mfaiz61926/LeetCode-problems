class Solution {
public:
    char parse(vector<int>&v, char op){
        if(op == '!'){
            return v[0] == 't' ? 'f' : 't';
        }
        else if(op == '|'){
            bool ok = false;
            for(auto & i : v) if(i == 't') ok = true;
            return ok ? 't' : 'f';
        }
        else {
            for(auto &i : v) if(i == 'f') return 'f';
            return 't';
        }
    }
    bool parseBoolExpr(string exp) {
        int n = exp.size();
        stack<char>st;

        for(int i = 0; i < n; i++){
            if(exp[i] == ',') continue;
            if(exp[i] == ')'){
                vector<int>v;
                while(!st.empty() && st.top() != '('){
                    v.push_back(st.top());
                    st.pop();
                }
                st.pop(); // (
                char optr = st.top(); st.pop();
                char s = parse(v, optr);
                st.push(s);
            }
            else st.push(exp[i]);
        }

        return st.top() == 't';
    }
};