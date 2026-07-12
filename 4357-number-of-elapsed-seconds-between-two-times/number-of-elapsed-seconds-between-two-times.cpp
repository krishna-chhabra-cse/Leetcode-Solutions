class Solution {
public:
    int secondsBetweenTimes(string startTime, string endTime) {
        int stsec = (startTime[6]-'0')*10 + startTime[7]-'0';
        int stmin = (startTime[3]-'0')*10 + startTime[4]-'0';
        int sthr = (startTime[0]-'0')*10 + startTime[1]-'0';
        int ensec = (endTime[6]-'0')*10 + endTime[7]-'0';
        int enmin = (endTime[3]-'0')*10 + endTime[4]-'0';
        int enhr = (endTime[0]-'0')*10 + endTime[1]-'0';
        int remsec = ensec-stsec;
        int remin = 0;
        if(remsec < 0) {remsec += 60; remin -= 1;}
        remin += (enmin-stmin);
        int remhr = 0;
        if(remin < 0) {remin += 60; remhr -= 1;}
        remhr += (enhr - sthr);
        int ans = remsec + remin*60 + remhr*3600;
        return ans;
    }
};