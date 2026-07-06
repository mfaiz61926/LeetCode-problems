class Solution {
public:
    int removeCoveredIntervals(vector<vector<int>>& range) {
        int n = range.size();
        sort(range.begin(), range.end(), [](const vector<int>&a, const vector<int>&b){
            if(a[0] == b[0]){
                return a[1] > b[1];
            }
            else return a[0] < b[0];
        });

        vector<vector<int>>ans;
        ans.push_back(range[0]);
        for(int i = 1; i < n; i++){
            if(ans.back()[1] >= range[i][1]) continue;
            else ans.push_back(range[i]);
        }
        for(auto i : ans){
            for(auto it : i){
                cout << it << " ";
            }
            cout << endl;
        }
        return ans.size();

    }
};