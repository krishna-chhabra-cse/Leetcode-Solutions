class Solution {
public:
    int numSubarrayProductLessThanK(vector<int>& nums, int k) {
        int head=-1,tail=0;
        int n = nums.size();
        int prod=1;
        int ans = 0;
        while(tail<n){
            while(head+1<n && (prod*nums[head+1]<k)){
                head++;
                prod *= nums[head];
            }
            ans += (head-tail+1);
            if(tail > head){
                tail++;
                head = tail-1;
            }
            else{
                prod /= nums[tail];
                tail++;
            }
        }
        return ans;
    }
};