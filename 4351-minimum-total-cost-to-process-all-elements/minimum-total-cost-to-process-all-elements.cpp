#define mod 1000000007
class Solution {
public:
long long int binpow(int a,int b){
    if(b==0) return 1LL;
    if(b%2){
        long long int temp = binpow(a,b-1)*1LL;
        return (a*temp*1LL)%mod;
    }
    else{
        long long int temp = (binpow(a,b/2)*1LL)%mod;
        return (temp*temp)%mod;
    }
}
    int minimumCost(vector<int>& nums, int k) {
        int n = nums.size();
        long long int cost = 0;
        long long int stRes = k*1LL; // Starting REsource
        // k is THE FIXED RESOURCE INCREASE COUNT
        long long ops = 0;
        for(int i=0;i<n;i++){
            if(nums[i] > stRes){
                long long int diff = nums[i]-stRes;
                long long int times = (diff/k)*1LL;
                if(diff%k) times++;
                stRes = stRes + 1LL * times * k - nums[i];
                ops += times*1LL;
            }
            else stRes -= nums[i];
        }
        cost = ( ( ( (ops%mod) * ((ops+1)%mod) )%mod) * binpow(2,mod-2) )%mod;
        return cost;
    }
};