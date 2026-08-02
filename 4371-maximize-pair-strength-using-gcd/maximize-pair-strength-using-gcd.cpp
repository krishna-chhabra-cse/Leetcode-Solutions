class Solution {
public:
    long long maxPairStrength(vector<int>& nums) {
        int n = nums.size();
        long long ans = 1;
        for(int i=0;i<n;i++){
            long long x = nums[i];
            for(int j=i+1;j<n;j++){
                long long y = nums[j];
                long long z = __gcd(x,y);
                ans = max(ans,(x*y)/(z*z));
            }
        }
        return ans;
    }
};