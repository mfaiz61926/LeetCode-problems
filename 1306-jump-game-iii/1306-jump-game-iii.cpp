class Solution {
public:
    bool canReach(vector<int>& arr, int start) {
        int n = arr.size();
        queue<int>q;
        vector<int>vis(n, 0);
        q.push(start);
        vis[start] = 1;
    
        while(!q.empty()){
            int i = q.front();
            q.pop();

            if(arr[i] == 0) return true;

            if(i + arr[i] < n && !vis[i + arr[i]]) q.push(i + arr[i]), vis[i + arr[i]] = 1;
            if(i - arr[i] >= 0 && !vis[i - arr[i]]) q.push(i - arr[i]), vis[i - arr[i]] = 1;
        }

        return false;
    }
};