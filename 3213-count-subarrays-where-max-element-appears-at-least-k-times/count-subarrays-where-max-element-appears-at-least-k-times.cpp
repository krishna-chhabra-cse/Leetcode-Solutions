#define ll long long
class Solution {
public:
    long long countSubarrays(vector<int>& nums, int k) {
        int n = nums.size();
        ll cnt=0;
        ll bad=0;
        ll total = (1LL*n*(n+1))/2;
        int x = *max_element(nums.begin(),nums.end());
        int head=-1,tail=0;
        while(tail<n){
            while(head+1<n && (cnt<k-1 || nums[head+1]!=x)){
                head++;
                if(nums[head]==x) cnt++;
            }
            bad += (head-tail+1);
            if(tail > head){
                tail++;
                head = tail-1;
                cnt=0;
            }
            else{
                if(nums[tail] == x) cnt--;
                tail++;
            }
        }
        return total-bad;
    }
};