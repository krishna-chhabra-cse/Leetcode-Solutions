class Solution {
public:
    long long appealSum(string s) {
        long long n = s.size();
        long long ans = 0;
        for(char ch='a';ch<='z';ch++){
            int last = -1;
            long long contribution = ((n)*(n+1))/2;
            for(int i=0;i<n;i++){
                if(s[i]==ch){
                    long long len = i-last-1;
                    contribution -= ((len)*(len+1))/2;
                    last = i;
                }
            }
            long long len = n-last-1;
            contribution -= ((len)*(len+1))/2;
            ans += contribution;
        }
        return ans;
    }
};