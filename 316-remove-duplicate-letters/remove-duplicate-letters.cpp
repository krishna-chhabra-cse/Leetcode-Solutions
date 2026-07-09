class Solution {
public:
    string removeDuplicateLetters(string s) {
        int n = s.size();
        string ans = "";
        int fre[26] = {0};
        for(int i=0;i<n;i++){
            fre[s[i]-'a'] = i;
        }
        vector<bool> vis(26,0);
        for(int i=0;i<n;i++){
            while(!ans.empty() && (ans.back() >= s[i]) && (fre[ans.back()-'a'] > i) && (!vis[s[i]-'a'])){
                vis[ans.back()-'a'] = 0;
                ans.pop_back();
            }
            if(!vis[s[i]-'a']){
                ans += s[i];
                vis[s[i]-'a'] = 1;
            }
        }
        return ans;
    }
};