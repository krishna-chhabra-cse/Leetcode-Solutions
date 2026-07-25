class Solution {
public:
    int maxProduct(int n) {
        // vector<int> arr;
        int max1 = 0;
        int max2 = max1;
        while(n){
            int digit = n%10;
            if(digit>max1){
                max2=max1;
                max1=digit;
            }
            else if(digit>max2){
                max2=digit;
            }
            // arr.push_back(digit);
            n /= 10;
        }
        // int n=arr.size();
        return max2*max1;
        // sort(arr.begin(),arr.end());
        // int ans = arr[n-2]*arr[n-1];
        // return ans;
    }
};