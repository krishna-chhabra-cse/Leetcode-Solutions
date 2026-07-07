#define ll long long
class Solution {
public:
    long long sumAndMultiply(int n) {
        ll x = n;
        ll no = 0;
        ll y = 0;
        ll s = 0;
        while(n){
            if(n%10 != 0){
                s += n%10;
                no = n%10 + no*10;
            }
            n=n/10;
        }
        while(no){
            if(no%10 != 0){
                y = no%10 + y*10;
            }
            no=no/10;
        }
        ll ans = y*s;
        return ans;
    }
};