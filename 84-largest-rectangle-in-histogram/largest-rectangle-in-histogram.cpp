class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        int n = heights.size();
        vector<int> nse(n),pse(n);
        for(int i=0;i<n;i++){
            int idx = i-1;
            while(idx!=-1 && heights[idx]>=heights[i]){
                idx = pse[idx];
            }
            pse[i] = idx;
        }
        for(int i=n-1;i>=0;i--){
            int idx = i+1;
            while(idx!=n && heights[idx]>=heights[i]){
                idx = nse[idx];
            }
            nse[i] = idx;
        }
        int area = 0;
        for(int i=0;i<n;i++){
            int ht = heights[i];
            int width = nse[i]-pse[i]-1;
            area = max(area,ht*width);
        }
        return area;
    }
};