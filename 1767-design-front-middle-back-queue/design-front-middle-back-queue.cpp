class FrontMiddleBackQueue {
public:
deque<int> leftist;
deque<int> rightist;
    FrontMiddleBackQueue() {
        leftist.clear();
        rightist.clear();
    }
    void balance(){
        if(leftist.size() < rightist.size()){
            leftist.push_back(rightist.front());
            rightist.pop_front();
        }
        else if(leftist.size() >= rightist.size() + 2){
            rightist.push_front(leftist.back());
            leftist.pop_back();
        }
    }
    void pushFront(int val) {
        leftist.push_front(val);
        balance();
    }
    
    void pushMiddle(int val) {
        if(leftist.size() > rightist.size()){
            int x = leftist.back();
            rightist.push_front(x);
            leftist.pop_back();
        }
        leftist.push_back(val);
        balance();
    }
    
    void pushBack(int val) {
        rightist.push_back(val);
        balance();
    }
    
    int popFront() {
        int x;
        if(leftist.size()==0 && rightist.size()==0) return -1;
        else{
            if(leftist.size()==0){
                x = rightist.front();
                rightist.pop_front();
                balance();
                return x;
            }
            else{
                x = leftist.front();
                leftist.pop_front();
                balance();
                return x;    
            }
        }
    }
    
    int popMiddle() {
        int x;
        if(leftist.size()==0 && rightist.size()==0) return -1;
        else{
            if(leftist.size()==0){
                x = rightist.front();
                rightist.pop_front();
                balance();
                return x;
            }
            else{
                x = leftist.back();
                leftist.pop_back();
                balance();
                return x;    
            }
        }
    }
    
    int popBack() {
        int x;
        if(leftist.size()==0 && rightist.size()==0) return -1;
        else{
            if(rightist.size()==0){
                x = leftist.back();
                leftist.pop_back();
                balance();
                return x;
            }
            else{
                x = rightist.back();
                rightist.pop_back();
                balance();
                return x;    
            }
        }
    }
};

/**
 * Your FrontMiddleBackQueue object will be instantiated and called as such:
 * FrontMiddleBackQueue* obj = new FrontMiddleBackQueue();
 * obj->pushFront(val);
 * obj->pushMiddle(val);
 * obj->pushBack(val);
 * int param_4 = obj->popFront();
 * int param_5 = obj->popMiddle();
 * int param_6 = obj->popBack();
 */