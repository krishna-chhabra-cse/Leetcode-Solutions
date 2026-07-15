class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& arr) {
        int n = arr.size();
        vector<int> ans(n,0);
        for(int i=n-1;i>=0;i--){
            int idx = i+1;
            while(idx!=n && arr[idx]<=arr[i]){
                idx = ans[idx];
            }
            ans[i] = idx;
        }
        for(int i=0;i<n;i++){
            if(ans[i]==n) ans[i]=0;
            else{
                ans[i] -= i; 
            }
        }
        return ans;
    }
};