class Solution {
public:
    using ll = long long; 
    const ll Neg = -4e18;
    long long maxSubarraySum(vector<int>& nums, int k) {
        ll noOp = Neg;
        ll mul = Neg;
        ll mulDone = Neg;
        ll div = Neg;
        ll divDone = Neg;

        ll ans = Neg;
        for(int x : nums){
            ll M = 1LL * x * k;
            ll D = x / k;

            ll newNoOp = max(1LL * x, noOp + x);

            //currently inside multiplied segment
            ll newMul = max({M, noOp + M, mul + M});  

            //Multiplied already finished
            ll newMulDone = max({1LL * x, mul + x,  mulDone + x});

            //currently inside divided seg
            ll newDiv = max({D, noOp + D, div + D});

            //div already finished
            ll newDivDone = max({1LL * x, div + x, divDone + x});

            noOp = newNoOp;
            mul = newMul;
            mulDone = newMulDone;
            div = newDiv;
            divDone = newDivDone;

            ans = max({ans, noOp, mul, mulDone, div, divDone});
        }

        return ans;
    }
};