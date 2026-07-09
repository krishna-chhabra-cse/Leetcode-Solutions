class Solution {
public:
    string smallestSubsequence(string s) {
        int n = s.size();
        vector<bool> vis(26,0);
        int last_idx[26]={0};
        for(int i=0;i<n;i++){
            last_idx[s[i]-'a'] = i;
        }
        string ans = "";
        for(int i=0;i<n;i++){
            while(!ans.empty() && (last_idx[ans.back() -'a'] > i) && (ans.back() >= s[i]) && (!vis[s[i]-'a']) ){
                vis[ans.back()-'a']=0;
                ans.pop_back();
            }
            if(!vis[s[i]-'a']){
                ans += s[i];
                vis[s[i]-'a']=1;
            }
        }
        return ans;
    }
};