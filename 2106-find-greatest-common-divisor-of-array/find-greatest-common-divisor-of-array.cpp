class Solution {
public:
    int findGCD(vector<int>& nums) {
        int n = nums.size();
        sort(nums.begin(),nums.end());
        int a = nums[0];
        int b = nums[n-1];
        int x = (a>b) ? b : a;
        int ans = 0;
        for(int i=1;i<=x;i++){
            if((a%i==0)&&(b%i==0)){
                ans = i;
            }
        }
        return ans;

    }
};