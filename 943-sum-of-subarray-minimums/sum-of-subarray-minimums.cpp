#define mod 1000000007
class Solution {
public:
    int sumSubarrayMins(vector<int>& arr) {
        int n = arr.size();
        // [a,b,c,d,e,f] contrib of each element is pse and nse
        vector<int> pse(n),nse(n);
        for(int i=0;i<n;i++){
            int idx = i-1;
            while(idx!=-1 && arr[idx] > arr[i]){
                idx = pse[idx];
            }
            pse[i] = idx;
        }
        for(int i=n-1;i>=0;i--){
            int idx = i+1;
            while(idx!=n && arr[idx] >= arr[i]) idx = nse[idx];
            nse[i] = idx;
        }
        long long ans = 0;
        for(int i=0;i<n;i++){
            long long contrib = ((i-pse[i])*(nse[i]-i))%mod;
            ans  = (ans%mod + ((arr[i]*contrib*1LL)%mod))%mod;
        }
        return ans;
    }
};