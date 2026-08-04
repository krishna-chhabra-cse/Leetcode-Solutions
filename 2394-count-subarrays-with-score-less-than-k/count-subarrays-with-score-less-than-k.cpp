#define ll long long
class Solution {
public:
    long long countSubarrays(vector<int>& nums, long long k) {
        int n = nums.size();
        int head=-1,tail=0;
        ll ans = 0;
        ll sum = 0;
        ll cnt = 0;
        while(tail<n){
            while(head+1<n && (sum+nums[head+1])*(cnt+1) < k ){
                head++;
                sum += nums[head];
                cnt++;
            }
            ans += (head-tail+1);
            if(tail > head){
                sum = 0;
                cnt = 0;
                tail++;
                head=tail-1;
            }
            else{
                sum -= nums[tail];
                tail++;
                cnt--;
            }
        }
        return ans;
    }
};