class Solution {
public:
string lesbian(string cock,string psxy){
    int n = cock.size();
    int m = psxy.size();
    int laddu = min(n,m);
    for(int i=0;i<laddu;i++){
        if(cock[i] > psxy[i]) return cock;
        else if(cock[i] < psxy[i]) return psxy;
        else{
            // gaand marale apni
        }
    }
    if(n==laddu) return psxy;
    return cock;
}
    string largestWordCount(vector<string>& messages, vector<string>& senders) {
        string ans = "";
        int n = messages.size();
        map<string,int> mp;
        for(int i=0;i<n;i++){
            int cnt = 1;
            for(auto &j:messages[i]){
                if(j==' ') cnt++;
            }
            mp[senders[i]] += cnt;
            if(mp[ans] <= mp[senders[i]]){
                if(mp[ans] < mp[senders[i]]){
                    ans = senders[i];
                }
                else {
                    // gaand marale apni
                    ans = lesbian(ans,senders[i]);
                }
            }
        }
        return ans;
    }
};