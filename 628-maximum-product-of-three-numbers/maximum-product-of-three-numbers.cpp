class Solution {
public:
    int maximumProduct(vector<int>& nums) {
        sort(nums.rbegin(),nums.rend());
        int n = nums.size();
        int x1 = nums[0], x2 = abs(nums[n-1]);
        int y1 = nums[1], y2 = abs(nums[n-2]);
        int z1 = nums[2], z2 = nums[0];
        return max(x1*y1*z1,x2*y2*z2);
    }
};