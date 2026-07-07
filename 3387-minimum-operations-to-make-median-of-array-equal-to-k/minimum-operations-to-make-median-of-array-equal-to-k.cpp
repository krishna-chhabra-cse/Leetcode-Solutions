#define ll long long
class Solution {
public:
    long long minOperationsToMakeMedianK(vector<int>& nums, int k) {
        int n = nums.size();
        sort(nums.begin(), nums.end());
        ll ops = 0;
        if (nums[n/2] > k) {
            for (int i = n / 2; i>=0; i--) {
                if (nums[i] > k)
                    ops += nums[i]-k;
            }
        }
        else if(nums[n/2] < k){
            for (int i = n / 2; i < n; i++) {
                if (nums[i] < k)
                    ops += k - nums[i];
            }
        }
        return ops;
    }
};