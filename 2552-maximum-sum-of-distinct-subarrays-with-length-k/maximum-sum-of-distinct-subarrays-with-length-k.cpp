#define ll long long
class Solution {
public:
int n;
ll subsum(vector<int>& v,int k){
    ll cnt=0;
    int head=-1,tail=0;
    ll sum = 0;
    ll ans = 0;
    map<int,int> mp;
    while(tail<n){
        while(head+1<n && (cnt!=k) && (mp[v[head+1]] == 0)){
            head++;
            mp[v[head]]++;
            cnt++;
            sum += v[head];
        }
        if(cnt==k) ans = max(ans,sum);
        if(tail > head){
            tail++;
            head = tail-1;
            cnt=0;
            sum = 0;
        }
        else{
            sum -= v[tail];
            mp[v[tail]]--;
            cnt--;
            tail++;
        }
    }
    return ans;
}
    long long maximumSubarraySum(vector<int>& nums, int k) {
        n = nums.size();
        ll ans = subsum(nums,k);
        return ans;
    }
};