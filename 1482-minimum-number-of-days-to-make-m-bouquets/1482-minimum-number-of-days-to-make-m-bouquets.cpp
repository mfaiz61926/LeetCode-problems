class Solution {
public:
    bool check(vector<int>&arr, int day, int m, int k){
        int n = arr.size();
        int cnt = 0;
        int noOfB = 0;
        for(int i = 0; i < n; i++){
            if(arr[i] <= day){
                cnt++;
            }else{
                noOfB += (cnt/k);
                cnt=0;
            }
        }
        noOfB += (cnt/k);
        return noOfB >= m;
    }
    
    int minDays(vector<int>& bloomDay, int m, int k) {
        int n = bloomDay.size();
        long long val = 1LL * m * k;
        //size of the array
        if (val > n) return -1; 
        
        int mn = *min_element(bloomDay.begin(),bloomDay.end());
        int mx = *max_element(bloomDay.begin(),bloomDay.end());
        int low = mn,high = mx;
        while(low <= high){
            int mid = low + (high-low)/2;
            if(check(bloomDay,mid,m,k)){
                high = mid-1;
            }else{
                low = mid +1;
            }
        }
        return low;

    }
};