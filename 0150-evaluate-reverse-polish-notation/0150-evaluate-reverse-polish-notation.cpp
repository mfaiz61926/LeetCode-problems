class Solution {
public:
    int evalRPN(vector<string>& tokens) {
        int n = tokens.size();
        stack<int>st;
        for(int i = 0; i < n; i++){
            if(!st.empty() && tokens[i] == "+" || tokens[i] == "-" || tokens[i] == "*" || tokens[i] == "/"){
                int num1 = st.top(); st.pop();
                int num2 = st.top(); st.pop();
                string op = tokens[i];
                if(op == "+") st.push(num1 + num2);
                else if(op == "-") st.push(num2 - num1);
                else if(op == "*") st.push(num1 * num2);
                else if(op == "/") st.push(num2 / num1);
            }
            else st.push(stoi(tokens[i]));
        }

        return st.top();
    }
};