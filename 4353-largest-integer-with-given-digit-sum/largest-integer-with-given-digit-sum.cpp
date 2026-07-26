class Solution {
public:
    int largestInteger(int n, int s) {
        if(s>9*n) return -1;
        int ans = 0;
        n--;
        while(s>=9){
            s -= 9;
            ans += pow(10,n)*9;
            n--;
        }
        ans += pow(10,n)*s;
        return ans;
    }
};