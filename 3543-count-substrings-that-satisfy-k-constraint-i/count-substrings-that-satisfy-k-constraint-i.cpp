class Solution {
public:
int n;
int getbothcnt(string s, int k){
    int head=-1,tail=0;
    int ans = 0;
    int cnt0=0,cnt1=0;
    while(tail<n){
        while(head+1<n){
            int ncnt0 = cnt0 + (s[head + 1] == '0');
            int ncnt1 = cnt1 + (s[head + 1] == '1');
            
            if (ncnt0 > k && ncnt1 > k) break;
            head++;
            
            cnt0 = ncnt0;
            cnt1 = ncnt1;
        }
        ans += (head-tail+1);
        if(tail > head){
            tail++;
            head=tail-1;
            cnt1=0,cnt0=0;
        }
        else{
            if(s[tail]=='0') cnt0--;
            else cnt1--;
            tail++;
        }
    }
    return ans;
}
    int countKConstraintSubstrings(string s, int k) {
        n = s.size();
        // aub = s(A)+s(B)-s(A&B)
        // a -> cnt(0) <= k 
        // b -> cnt(1) <= k
        int ans = getbothcnt(s,k);
        return ans;
    }
};