class Solution {
public:
    vector<vector<int>>res;

    void f(int x, int n, int k, vector<int>&temp){
        if(temp.size() == k){
            res.push_back(temp);
            return;
        }
        if(x > n) return;
        //be careful about equals
        temp.push_back(x);

        f(x + 1, n, k, temp);

        temp.pop_back();

        f(x + 1, n, k, temp);
    }
    vector<vector<int>> combine(int n, int k) {
        vector<int>temp;
        f(1, n, k, temp);
        return res;    
    }
};