class MedianFinder {
public:
multiset<int> low,high;
    MedianFinder() {
    }
    void balance(){
        if(low.size() < high.size()){
            int x = *high.begin();
            high.erase(high.find(x));
            low.insert(x);
        }
        if(low.size() > high.size()+1){
            int x = *low.rbegin();
            low.erase(low.find(x));
            high.insert(x);
        }
    }
    void addNum(int num) {
        if(low.empty()) {low.insert(num);}
        else if( num <= (*low.rbegin())){
            low.insert(num);
        }
        else high.insert(num);
        balance();
    }
    
    double findMedian() {
        if(low.size()==high.size()) return (*high.begin() + *low.rbegin())/2.0;
        else{
            return *low.rbegin();
        }
    }
};

/**
 * Your MedianFinder object will be instantiated and called as such:
 * MedianFinder* obj = new MedianFinder();
 * obj->addNum(num);
 * double param_2 = obj->findMedian();
 */