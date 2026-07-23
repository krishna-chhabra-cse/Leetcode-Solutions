class Solution {
public:
    int timeRequiredToBuy(vector<int>& tickets, int k) {
        int n = tickets.size();
        int cnt1 = 0;
        int cnt2 = 0;
        for(int i=0;i<=k;i++){
            cnt1 += min(tickets[i],tickets[k]);
        }
        for(int i=k+1;i<n;i++){
            cnt2 += min(tickets[i],tickets[k]-1);
        }
        return cnt1+cnt2;
    }
};