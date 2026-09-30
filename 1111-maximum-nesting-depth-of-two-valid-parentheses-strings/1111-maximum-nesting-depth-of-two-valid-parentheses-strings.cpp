class Solution {
public:
    vector<int> maxDepthAfterSplit(string seq) {
        int mx = 0;
        int n = seq.size();
        int l = 0, r = n - 1;

        stack<pair<char, int>>st;
        int cnt = 0;
        for(int i = 0; i < n; i++){
            if(seq[i] == '('){
                st.push({seq[i], i});
                cnt = max(cnt, (int)st.size());

            }else {
                auto it = st.top();
                st.pop();
                if(st.empty()){
                    int idx = it.second;
                    if(mx < cnt){
                        l = idx;
                        r = i;
                        mx = cnt;
                        cnt = 0;
                    }
                }
            }
        }
        vector<int>ans(n, 0);
        int need = mx / 2;

        stack<int>st1;
        for(int i = 0; i < n; i++){
            if(seq[i] == '('){
                st1.push(i);
            }else{
                int idx = st1.top();
                if(i - idx + 1 == (need * 2)){
                    for(int j = idx; j <= i; j++) ans[j] = 1;
                }
                st1.pop();
            }
        }
        return ans;

    }
};