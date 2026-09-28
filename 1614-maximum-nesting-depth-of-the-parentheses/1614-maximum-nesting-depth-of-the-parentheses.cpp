class Solution {
public:
    int maxDepth(string s) {
        int cnt = 0;
        int mx = 0;
        for(auto &i : s){
            if(i == '(') cnt++;
            else if(i == ')') cnt--;
            mx = max(mx, cnt);
        }
        return mx;
    }
};