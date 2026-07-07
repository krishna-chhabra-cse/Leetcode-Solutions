class Solution {
public:
    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
        int n = nums1.size();
        int m = nums2.size();
        vector<int> v(n);
        vector<int> nge(m);
        unordered_map<int,int> pos;
        for(int i=m-1;i>=0;i--){
            int next_idx = i+1;
            while( next_idx<m && nums2[next_idx] <= nums2[i]){
                next_idx = nge[next_idx];
            }
            nge[i] = next_idx;
            if(next_idx == m) pos[nums2[i]] = -1;
            else pos[nums2[i]] = nums2[next_idx];
        }
        for(int i=0;i<n;i++){
            v[i] = pos[nums1[i]];
        }
        return v;
    }
};