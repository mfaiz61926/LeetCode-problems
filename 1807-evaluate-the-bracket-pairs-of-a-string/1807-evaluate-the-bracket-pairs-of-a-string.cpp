class Solution {
public:
    string evaluate(string s, vector<vector<string>>& knowledge) {
        unordered_map<string, string>mp;
        for(auto &it : knowledge){
            string key = it[0];
            string val = it[1];
            mp[key] = val;
        }

        string res = "";
        string temp = "";
        int ok = 0;
        for(auto &i : s){
            if(ok && i != ')'){
                temp += i;
            }
            else if(i == '('){
                ok = 1;
            }
            else if(i == ')'){
                ok = 0;
                if(mp.find(temp) != mp.end()){
                    res += mp[temp];
                }
                else res += "?";
                temp = "";
            }
            else res += i;
        }

        return res;
    }
};