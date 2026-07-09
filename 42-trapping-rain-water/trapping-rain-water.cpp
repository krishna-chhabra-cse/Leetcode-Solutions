class Solution {
public:
    int trap(vector<int>& height) {
        int water = 0;
        int n = height.size();
        vector<int> L(n),R(n);
        int x = height[0];
        int y = height[n-1];
        for(int i=0;i<n;i++){
            x = max(x,height[i]);
            y = max(y,height[n-1-i]);
            L[i] = x;
            R[n-1-i] = y;
        }
        for(int i=0;i<n;i++){
            water += (min(L[i],R[i])-height[i]);
        }
        return water;
    }
};