class Solution {
public:
    vector<int> deckRevealedIncreasing(vector<int>& deck) {
        int n = deck.size();
        vector<int> CJP;
        sort(deck.begin(),deck.end());
        if(n<=2) return deck;

        deque<int> dihh;
        dihh.push_back(deck[n-2]);
        dihh.push_back(deck[n-1]);
        for(int i=n-3;i>=0;i--){
            int x = dihh.back();
            dihh.pop_back();
            dihh.push_front(x);
            dihh.push_front(deck[i]);
        }
        while(!dihh.empty()){
            CJP.push_back(dihh.front());
            dihh.pop_front();
        }
        return CJP;
    }
};