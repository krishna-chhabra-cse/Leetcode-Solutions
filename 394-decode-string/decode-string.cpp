class Solution {
public:
    string decodeString(string s) {
        string ans = "";
        int n = s.size();
        stack<char> st;
        string fine = "";
        for(int i=0;i<n;i++){
            st.push(s[i]);
            if(st.top() == ']'){
                string temp = "";
                st.pop();
                while(!st.empty() && st.top() != '['){
                    temp = st.top() + temp;
                    st.pop();
                }
                if(!st.empty()) st.pop();
                int freq = 0;
                int j=0;
                while(!st.empty()&&(st.top() >= '0' && st.top() <= '9')){
                    int digit = st.top()-'0';
                    freq = digit*pow(10,j) + freq;
                    st.pop();
                    j++;
                }
                int count = 0;
                // fine 
                string a = temp;
                while(count != freq){
                    for(char &c:temp){
                       st.push(c);
                    }
                    count++;
                }
                
            }
        }
        while(!st.empty()){
            char ch = st.top();
            ans = ch + ans;
            st.pop();
        }
        return ans;
    }
};