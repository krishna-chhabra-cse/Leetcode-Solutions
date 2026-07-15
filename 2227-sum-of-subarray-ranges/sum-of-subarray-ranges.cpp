#define ll long 
#define all(v) (v).begin(), (v).end()
class Solution {
public:
    long long subArrayRanges(vector<int>& nums) {
        ll n = nums.size();
        vector<int> pge(n),nge(n),nse(n),pse(n);
        for(int i=0;i<n;i++){
            int idx = i-1;
            while(idx!=-1 && nums[idx] >= nums[i]){
                idx = pse[idx];
            }
            pse[i]=idx;
        }
        for(int i=0;i<n;i++){
            int idx = i-1;
            while(idx!=-1 && nums[idx] <= nums[i]){
                idx = pge[idx];
            }
            pge[i]=idx;
        }
        for(int i=n-1;i>=0;i--){
            int idx = i+1;
            while(idx!=n && nums[idx] < nums[i]){
                idx = nge[idx];
            }
            nge[i]=idx;
        }
        for(int i=n-1;i>=0;i--){
            int idx = i+1;
            while(idx!=n && nums[idx] > nums[i]){
                idx = nse[idx];
            }
            nse[i]=idx;
        }
        ll ans = 0;
        for(int i=0;i<n;i++){
            ll negcontrib = (i-pse[i])*(nse[i]-i);
            ll poscontrib = (i-pge[i])*(nge[i]-i);
            ans -= nums[i]*negcontrib;
            ans += nums[i]*poscontrib;
        }
        return ans;
    }
};