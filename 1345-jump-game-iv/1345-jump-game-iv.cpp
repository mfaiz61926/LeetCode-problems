class Solution {
public:
    int minJumps(vector<int>& arr) {
        int n = arr.size();

        map<int,vector<int>>mp;
        for(int i = 0; i < n; i++){
            mp[arr[i]].push_back(i);
        }

        queue<pair<int,int>>q;
        vector<int>vis(n, 0);
        q.push({0, 0});
        vis[0] = 1;

        while(!q.empty()){
            int sz = q.size();
            for(int k = 0; k < sz; k++){

                auto it = q.front();
                q.pop();

                int level = it.first;
                int i = it.second;

                if(i == n - 1) return level;
                if(i + 1 < n && !vis[i + 1]){
                    q.push({level + 1, i + 1});
                    vis[i + 1] = 1;
                }
                if(i - 1 >= 0 && !vis[i - 1]){
                    q.push({level + 1, i - 1});
                    vis[i - 1] = 1;
                }
                for(int idx : mp[arr[i]]){
                    if(!vis[idx]){
                        q.push({level + 1, idx});
                        vis[idx] = 1;
                    }
                }
                mp[arr[i]].clear();
            }
        }
        return -1;
    }
};