class Solution {
public:
multiset<int> low,high;
int K;
void balance(){
    if(low.size() < high.size()){
        int x = *high.begin();
        auto it = high.find(x);
        low.insert(x);
        high.erase(it);
    }
    else if(low.size() > high.size()+1){
        int x = *low.rbegin();
        auto it = low.find(x);
        high.insert(x);
        low.erase(it);
    }
}
void add(int x){
    if(low.empty()) low.insert(x);
    else if(x <= *low.rbegin()) low.insert(x);
    else high.insert(x);
    balance();
}
void remove(int x){
    if(low.find(x)!=low.end()) low.erase(low.find(x));
    else if(high.find(x)!=high.end()) high.erase(high.find(x));
    balance();
}
long double median(){
    if(K%2){
        return *low.rbegin();
    }
    else{
        long double ans = ((long double)*low.rbegin() + (long double)*high.begin())/2.0;
        return ans;
    }
}
    vector<double> medianSlidingWindow(vector<int>& nums, int k) {
        int n = nums.size();
        K=k;
        low.clear();
        high.clear();
        vector<double> v;
        for(int i=0;i<n;i++){
            add(nums[i]);
            if(i>=k-1){
                long double ans = median();
                v.push_back(ans);
                remove(nums[i-k+1]);
            }
        }
        return v;
    }
};