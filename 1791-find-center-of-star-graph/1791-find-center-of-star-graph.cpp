class Solution {
public:
    int findCenter(vector<vector<int>>& edges) {
        int size = edges.size();
        int n = size  + 1;
        vector<int>ind(n, 0);
        for(auto &i : edges){
            ind[i[0] - 1]++;
            ind[i[1] - 1]++;
        }
        for(auto &i : ind) cout << i << " ";
        for(int i = 0; i < n; i++){
            if(ind[i] == n - 1) return i + 1;
        }

        return n;
    }
};