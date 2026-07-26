class Solution {
public:
    vector<vector<int>> aggregateTimeSeries(vector<vector<int>>& series1, vector<vector<int>>& series2) {

        int n = series1.size();
        int m = series2.size();
        map<int,int> mp1;
        map<int,int> mp2;
        map<int,int> fmp;
        int x = max(series1[n-1][0],series2[m-1][0]);
        vector<vector<int>> v;
        for(auto &vip:series1){
            mp1[vip[0]] = vip[1];
            fmp[vip[0]] += vip[1];
        }
        for(auto &vip:series2){
            mp2[vip[0]] = vip[1];
            fmp[vip[0]] += vip[1];
        }
        for(auto &i:mp1){
            int time = i.first;
            if(!mp2.contains(time)){
                auto it = mp2.upper_bound(time);
                fmp[time] += it->second;
            }
        }
        for(auto &i:mp2){
            int time = i.first;
            if(!mp1.contains(time)){
                auto it = mp1.upper_bound(time);
                fmp[time] += it->second;
            }
        }
        for(auto &it:fmp){
            v.push_back({it.first,it.second});
        }
        return v;
        // int j = 0;
        // for(int i=0;i<n;i++){
        //     int time = series1[i][0];
        //     if(mp1.contains(time)){
        //         fmp[time] = mp1[time];
        //         j=i;
        //     }
        //     else if(mp2.contains(time)){
        //         fmp[time] = 
        //     }
        // }
        // int st=1;
        // int j=0;
        // for(int i=1;i<=x;i++){
        //     if(j>=n){
        //         mp1[i]=0;
        //         continue;
        //     }
        //     else if(series1[j][0] == i)j++;
        //     else{
        //         mp1[i] = series1[j][0];
        //     }
        // }
        // j=0;
        // for(int i=1;i<=x;i++){
        //     if(j>=m){
        //         mp1[i]=0;
        //         continue;
        //     }
        //     else if(series2[j][0] == i)j++;
        //     else{
        //         mp2[i] = series2[j][0];
        //     }
        // }

        // for(int i=1;i<=x;i++){
        //     v[i-1][0] = i;
        //     v[i-1][1] = mp1[i] + mp2[i];
        // }
        return v;
    }
};