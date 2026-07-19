class Solution {
public:
    string smallestSubsequence(string s) {
        vector<int>last(26);
        //last occurrence of every char
        for(int i = 0; i < s.size(); i++){
            last[s[i] - 'a'] = i;
        }

        vector<bool>inStack(26, false);
        string st;

        for(int i = 0; i < s.size(); i++){
            char ch = s[i];

            //if already included
            if(inStack[ch - 'a']) continue;

            //remove larger char from stack if they appear in future
            while(!st.empty() && st.back() > ch && last[st.back() - 'a'] > i){
                inStack[st.back() - 'a'] = false;
                st.pop_back();
            }

            st.push_back(ch);
            inStack[ch - 'a'] = true;
        }
        
        return st;
    }
};