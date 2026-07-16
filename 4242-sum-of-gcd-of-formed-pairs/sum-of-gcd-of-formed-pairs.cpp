class Solution {
public:
    long long gcdSum(vector<int>& nums) {
        int n = nums.size();
        vector<int> v(n);
        int mx = INT_MIN;
        for(int i=0;i<n;i++){
            mx = max(mx,nums[i]);
            v[i] = __gcd(nums[i],mx);
        }
        sort(v.begin(),v.end());
        long long int ans = 0;
        for(int i=0;i<n/2;i++){
            ans += __gcd(v[i],v[n-1-i]);
        }
        return ans;
    }
};