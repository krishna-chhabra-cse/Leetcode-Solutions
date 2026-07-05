class Solution {
public:
    int maxDigitRange(vector<int>& nums) {
        int n = nums.size();
        int fre[10] = {0};
        for(auto &i:nums){
            int x = i;
            int maxi = 0;
            int mini = 10;
            while(x){
                maxi = max(maxi,x%10);
                mini = min(mini,x%10);
                x /= 10;
            }
            fre[maxi-mini] += i;
        }
        for(int i=9;i>=0;i--){
            if(fre[i]){
                return fre[i];
            }
        }
        return 0;
    }
};