class Solution {
public:
    vector<int> arrayRankTransform(vector<int>& arr) {
        int n = arr.size();
        vector<int> rank(n);
        map<int,int> mp;
        for(auto &i:arr) mp[i]++;
        int x = 1;
        for(auto &i:mp){
            i.second = x;
            x++;
        }
        for(int i=0;i<n;i++){
            rank[i] = mp[arr[i]];
        }
        return rank;
    }
};