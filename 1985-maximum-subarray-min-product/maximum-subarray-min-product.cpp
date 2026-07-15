#define mod 1000000007
#define ll long long
class Solution {
public:
    int maxSumMinProduct(vector<int>& nums) {
        int n = nums.size();
        vector<long long> pref(n+2,0);
        vector<int> nse(n),pse(n);
        pref[0] = 0;
        for(int i=1;i<=n;i++){
            pref[i] = (nums[i-1] + pref[i-1]);
        }
        pref[n+1] = pref[n];
        for(int i=0;i<n;i++){
            int idx = i-1;
            while(idx!=-1 && nums[idx]>=nums[i]){
                idx = pse[idx];
            }
            pse[i] = idx;
        }
        for(int i=n-1;i>=0;i--){
            int idx = i+1;
            while(idx!=n && nums[idx]>nums[i]){
                idx = nse[idx];
            }
            nse[i] = idx;
        }
        long long ans = 0;
        for(int i=0;i<n;i++){
            long long contrib = pref[nse[i]] - pref[pse[i]+1];
            long long var = nums[i]*1LL*contrib;
            ans = max(ans,var);
        }
        ans %= mod;
        return ans;
    }
};