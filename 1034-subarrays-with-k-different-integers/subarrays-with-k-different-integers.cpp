class Solution {
public:
int subsum(vector<int>& v, int k){
    int head = -1,tail=0;
    int n = v.size();
    int dihcnt=0;
    int ans=0;
    map<int,int> mp;
    while(tail<n){
        while(head+1<n && (dihcnt < k || mp[v[head+1]] != 0)){
            head++;
            if(mp[v[head]]==0){
                dihcnt++;
            }
            mp[v[head]]++;
        }
        ans += (head-tail+1);
        if(tail > head){
            tail++;
            head = tail-1;
        }
        else{
            mp[v[tail]]--;
            if(mp[v[tail]] == 0) dihcnt--;
            tail++;
        }
    }
    return ans;
}
    int subarraysWithKDistinct(vector<int>& nums, int k) {
        return subsum(nums,k)-subsum(nums,k-1);
    }
};