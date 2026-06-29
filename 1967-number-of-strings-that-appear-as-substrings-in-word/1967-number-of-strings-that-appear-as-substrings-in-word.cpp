class Solution {
public:
    int numOfStrings(vector<string>& patterns, string word) {
        int cnt = 0;
        for(auto &s : patterns){
            if(word.contains(s)) cnt++;
        }
        return cnt;
    }
};