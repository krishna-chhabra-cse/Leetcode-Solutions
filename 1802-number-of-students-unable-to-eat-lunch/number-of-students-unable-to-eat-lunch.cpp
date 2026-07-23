class Solution {
public:
    int countStudents(vector<int>& students, vector<int>& sandwiches) {
        int n = students.size();
        multiset<int> st;
        for(auto &i:students) st.insert(i);
        for(int i=0;i<n;i++){
            if(st.contains(sandwiches[i])){
                st.erase(st.find(sandwiches[i]));
            }
            else break;
        }
        return st.size();
    }
};