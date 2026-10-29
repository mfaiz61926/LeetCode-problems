class Solution {
public:
    string removeKdigits(string num, int k) {
        int n = num.size();
        stack<char>st;

        for(auto &val : num){
            while(!st.empty() && st.top() > val && k > 0){
                st.pop();
                k--;
            }

            st.push(val);
        }

        while(!st.empty() && k){
            st.pop();
            k--;
        }

        string temp = "";
        while(!st.empty()){
            temp += st.top();
            st.pop();
        }

        reverse(temp.begin(), temp.end());
        bool flag = false;

        string ans = "";
        for(auto &i : temp){
            if(i != '0') flag = true;
            if(flag) ans += i;
        }

        return ans.empty() ? "0" : ans;
    }
};