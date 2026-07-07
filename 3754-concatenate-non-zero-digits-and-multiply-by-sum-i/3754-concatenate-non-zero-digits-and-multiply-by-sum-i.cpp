class Solution {
public:
    long long sumAndMultiply(int n) {
        string s;
        long long sum = 0;
        while(n){
            int d = n % 10;
            n /= 10;
            sum += d;
            if(d != 0)
            s += to_string(d);
        }
        if(s.empty()) return 0;
        reverse(s.begin(), s.end());
        cout << s << endl;
        int m = stoi(string(s));
        return 1LL * sum * m;
    }
};