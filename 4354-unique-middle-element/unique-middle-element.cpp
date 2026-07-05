class Solution {
public:
    bool isMiddleElementUnique(vector<int>& nums) {
        int fre[102];
        int n = nums.size();
        for(auto &i:nums)fre[i]++;
        return (fre[nums[n/2]] == 1);
    }
};