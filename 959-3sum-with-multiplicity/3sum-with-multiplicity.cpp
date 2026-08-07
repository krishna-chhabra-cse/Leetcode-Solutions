#define mod 1000000007
#define ll long long
class Solution {
public:
    int threeSumMulti(vector<int>& arr, int target) {
        int n = arr.size();
        ll cnt = 0;
        sort(arr.begin(),arr.end());
        for(int j=0;j<n;j++){
            int i=0,k=n-1;
            while(i<j && k>j){
                int sum = arr[i]+arr[j]+arr[k];
                if(sum == target){
                    int itemp=i;
                    int ktemp=k;
                    while(itemp<j && arr[itemp]==arr[i]) itemp++;
                    while(ktemp>j && arr[ktemp]==arr[k]) ktemp--;
                    cnt += 1LL*(itemp-i)*(k-ktemp);
                    i=itemp;
                    k=ktemp;
                }
                else if(sum>target) k--;
                else i++;
            }
        }
        return cnt%mod;
    }
};