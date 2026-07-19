class Solution {
public:
    bool canReach(vector<int>& start, vector<int>& target) {
        return (((start[0] + target[0]) % 2) == ((start[1] + target[1]) % 2));
    }
};