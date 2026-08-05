class Solution {
public:
    string minWindow(string s, string t) {
        int n = s.size();
        int m = t.size();
        if(s==t) return s;
        int start = -1;
        int matched = 0;
        int bestlen = INT_MAX;
        map<char,int> mp;
        for(auto ch:t) mp[ch]++;
        int head=-1,tail=0;
        while(tail<n){
            while(head+1<n && matched < m){
                head++;
                if(mp[s[head]] > 0) matched++;
                mp[s[head]]--;
            }
            if(matched == m){
                if(bestlen > head-tail+1){
                    bestlen = head-tail+1;
                    start = tail;
                }
            }
            if(tail > head){
                tail++;
                head = tail-1;
            }
            else{
                mp[s[tail]]++;
                if(mp[s[tail]] > 0) matched--;
                tail++;
            }
        }
        if(start == -1) return "";
        return s.substr(start,bestlen);
    }
};