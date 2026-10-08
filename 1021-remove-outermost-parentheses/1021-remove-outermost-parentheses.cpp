class Solution {
public:
    string removeOuterParentheses(string s) {
        string res = "";
        int cnt = 0;
        for(auto &i : s){
            if(i == '('){
                if(cnt > 0) res += i;
                cnt++;
            }
            else{
                cnt--;
                if(cnt > 0) res += i;
            }
        }
        return res;
    }
};