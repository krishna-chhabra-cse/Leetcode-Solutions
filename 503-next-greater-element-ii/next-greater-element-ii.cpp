class Solution {
public:
    vector<int> nextGreaterElements(vector<int>& nums) {
        int n = nums.size();
        for(int i=0;i<n;i++){
            nums.push_back(nums[i]);
        }
        vector<int> nge(2*n);
        stack<int> st;
        for(int i=2*n-1;i>=0;i--){
            while(!st.empty() && st.top() <= nums[i]){
                st.pop();
            }
            if(st.empty()) nge[i]=-1;
            else nge[i]=st.top();
            st.push(nums[i]);
        }
        return vector<int>(nge.begin(),nge.begin()+n);
    }
};