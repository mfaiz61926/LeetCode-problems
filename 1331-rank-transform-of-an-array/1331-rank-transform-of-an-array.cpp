class Solution {
public:
    vector<int> arrayRankTransform(vector<int>& arr) {
        if(arr.empty()) return {};
        vector<pair<int,int>>p;
        for(int i = 0; i < arr.size(); i++){
            p.push_back({arr[i], i});
        }

        sort(p.begin(), p.end());

        int c = 1;
        int x = p[0].first;
        p[0].first = c++;

        for(int i = 1; i < p.size(); i++){
            if(p[i].first == x) p[i].first = c - 1;
            else {
                x = p[i].first;
                p[i].first = c++;
            }
        }
        sort(p.begin(), p.end(), [](pair<int,int>&a, pair<int,int>&b){
            return a.second < b.second;
        });

        vector<int>ans;
        for(auto &i : p){
            ans.push_back(i.first);
        }

        return ans;

    }
};