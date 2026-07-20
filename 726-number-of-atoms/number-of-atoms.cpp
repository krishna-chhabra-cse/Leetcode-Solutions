class Solution {
public:
int n;
string s;
string getnum(int i){
    if(i>=n) return "";
    if(i<n && s[i]>='0' && s[i]<='9'){
        int j = i;
        while(j<n && s[j]>='0' && s[j]<='9') j++;
        return s.substr(i,j-i);
    }
    else return "";
}
string getAtom(int i){
    if(i>=n) return "";
    string ans; ans += s[i];
    int j = i+1;
    if(j<n && s[j]>='a' && s[j]<='z'){
        while(j<n && s[j]>='a' && s[j]<='z') j++;
        return s.substr(i,j-i);
    }
    else return ans;
}
map<string,int> parse(int st,int en){
    map<string,int> cur;
    if(st>en) return cur;
    if(s[st] == '('){
        int depth = 1;
        int j = st+1;
        for(;j<en;j++){
            if(s[j]=='(') depth++;
            else if(s[j]==')') depth--;
            if(depth == 0) break;
        }
        auto inside_mp = parse(st+1,j-1);
        string multiplier = getnum(j+1);
        int mul = 1;
        if(multiplier != "") mul = stoi(multiplier);
        auto rest_map = parse(j+1+multiplier.size(),en);
        for(auto &i:inside_mp){
            rest_map[i.first] += i.second*mul;
        }
        return rest_map;
    }
    else{ // caps letter
        string atom = getAtom(st);
        string count = getnum(st+atom.size());
        auto restmp = parse(st + atom.size() + count.size(),en);
        int cnt = 1;
        if(count != "") cnt = stoi(count);
        restmp[atom] += cnt;
        return restmp;
    }
}
    string countOfAtoms(string formula) {
        s = formula;
        n = formula.size();
        auto mp = parse(0,n-1);
        string ans;
        for(auto &i:mp){
            if(i.second == 1) ans += i.first;
            else{
                ans += i.first;
                ans += to_string(i.second);
            }
        }
        return ans;
    }
};