class Solution {
public:
    double findMaxAverage(vector<int>& nums, int k) {
        int n = nums.size();
        int cnt=0;
        double sum=0,ans=INT_MIN;
        int head=-1,tail=0;
        while(tail<n){
            while(head+1<n && (cnt<k)){
                head++;
                cnt++;
                sum += nums[head];
            }
            if(cnt==k) ans = max(ans,(sum/k*(1.0)));
            if(tail > head){
                tail++;
                head = tail-1;
                sum=0;
                cnt=0;
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