class Solution {
public:
    string smallestPalindrome(string s) {
        int n = s.size();
        map<char, int>mp;
        for(auto &i : s) mp[i]++;

        string a = "", b = "";
        string base ="";
        for(auto &i : mp){
            char c = i.first;
            int cnt = i.second;
            if(cnt & 1){
                base = c;
                cnt--;
            }
            for(int j = 0; j < cnt / 2; j++) a += c;
            for(int j = cnt / 2; j < cnt; j++) b += c;
        }
        reverse(b.begin(), b.end());
        return a + base + b;
    }
};