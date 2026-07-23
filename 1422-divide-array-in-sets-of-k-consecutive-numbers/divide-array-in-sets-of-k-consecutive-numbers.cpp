class Solution {
public:
vector<int> v;
int n,k;
bool solve() {
    map<int,int> mp;
    for(auto &i:v) mp[i]++;
    if(n%k) return false;
    int grps = n/k;
    int cnt = 0;
    while(!mp.empty()){
        int st = 1;
        if(cnt==grps) break;
        int x = mp.begin()->first;
        mp[x]--;
        if(mp[x] == 0) mp.erase(mp.find(x));
        while(st<k){
            if(mp.find(x+1) != mp.end()){
                int y = x+1;
                mp[y]--;
                if(mp[y] == 0) mp.erase(mp.find(y));
                x = y;
            }
            else break;
            st++;
        }
        cnt++;
    }
    if(cnt != grps || !mp.empty()) return false;
    return true;
}
    bool isPossibleDivide(vector<int>& nums, int K) {
        v.clear();
        v = nums;
        n=nums.size();
        k=K;
        return solve();
    }
};