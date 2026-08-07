class Solution {
public:
    int threeSumClosest(vector<int>& arr, int target) {
        int n = arr.size();
        int diff = INT_MAX;
        int ans = 0;
        sort(arr.begin(),arr.end());
        for(int j=0;j<n;j++){
            int i=0,k=n-1;
            int sum = 0;
            while(i<j && k>j){
                sum = arr[i]+arr[j]+arr[k];
                if(abs(sum-target) < diff){
                    diff=abs(sum-target);
                    ans = sum;
                }
                if(sum==target) return target;
                else if(sum > target){
                    k--;
                }
                else{
                    i++;
                }
            }
        }
        return ans;
    }
};