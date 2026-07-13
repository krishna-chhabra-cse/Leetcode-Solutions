class Solution {
public:
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        vector<vector<int>> v;
        sort(nums.begin(),nums.end());
        int n = nums.size();
        set<vector<int>> svt;
        for(int mask=0;mask<(1<<n);mask++){
            vector<int> arr;
            for(int pos=0;pos<n;pos++){
                if(mask & (1<<pos)) arr.push_back(nums[pos]);
            }
            svt.insert(arr);
        }
        for(auto &i:svt) v.push_back(i);
        return v;
    }
};