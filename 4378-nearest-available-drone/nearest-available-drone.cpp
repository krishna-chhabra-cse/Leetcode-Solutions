class Solution {
public:
    int nearestDrone(vector<vector<int>>& drones, vector<int>& target) {
        int n = drones.size();
        int tx = target[0];
        int ty = target[1];
        int idx = n;
        int diff = INT_MAX;
        for(int i=0;i<n;i++){
            int xi = drones[i][0];
            int yi = drones[i][1];
            int ri = drones[i][2];
            int val = abs(tx-xi) + abs(ty-yi);
            if( val <= ri && diff > val){
                idx = i;
                diff = val;
            }
        }
        if(idx == n) return -1;
        return idx;
    }
};