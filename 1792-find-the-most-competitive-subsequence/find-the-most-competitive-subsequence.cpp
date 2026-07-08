class Solution {
public:
    vector<int> mostCompetitive(vector<int>& nums, int k) {
        int n = nums.size();
        vector<int> v;
        for(int i=0;i<n;i++){
            while(!v.empty() && (nums[i] < v.back()) && (v.size() + n-i-1 >= k)){
                v.pop_back();
            }
            v.push_back(nums[i]);
        }
        return vector<int>(v.begin(),v.begin()+k);
    }
};