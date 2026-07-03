class Solution {
public:
    int minimumFlips(int n) {
        string s;
        while(n){
            s += n % 2;
            n >>= 1;
        }
        int cnt = 0;
        for(int i = 0; i < s.size(); i++){
            if(s[i] != s[s.size() - 1 - i]) cnt++;
        }
        return cnt;
    }
};