class Solution {
public:
    string removeKdigits(string num, int k) {
        int n = num.size();
        k = n-k;
        vector<char> v;
        for(int i=0;i<n;i++){
            while(!v.empty() && (num[i] < v.back()) &&(v.size() + n-i-1 >= k)) v.pop_back();
            v.push_back(num[i]);
        }
        string ans = "";
        bool flag = 1;
        for(int i=0;i<k;i++){
            if(v[i]=='0' && flag) continue;
            flag=0;
            ans += v[i];
        }
        if(ans == "") return "0";
        return ans;
    }
};