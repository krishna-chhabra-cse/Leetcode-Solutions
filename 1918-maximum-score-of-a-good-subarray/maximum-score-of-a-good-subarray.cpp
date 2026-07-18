class Solution {
public:
    int maximumScore(vector<int>& nums, int k) {
        int n = nums.size();
        vector<int> nse(n),pse(n);
        for(int i=0;i<n;i++){
            int idx = i-1;
            while(idx!=-1 && nums[idx] >= nums[i]) idx = pse[idx];
            pse[i] = idx;
        }
        for(int i=n-1;i>=0;i--){
            int idx = i+1;
            while(idx!=n && nums[idx] > nums[i]) idx = nse[idx];
            nse[i] = idx;
        }
        int ans = 0;
        for(int i=0;i<n;i++){
            int left = pse[i]+1;
            int right = nse[i]-1;
            if(left <= k && right >= k){
                ans = max(ans,nums[i]*(right-left+1));
            }
        }
        return ans;
    }
};