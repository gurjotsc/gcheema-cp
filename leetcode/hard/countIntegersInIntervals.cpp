class CountIntervals {
public:
    map<int, int> m;
    int cnt;
    CountIntervals() {
        m.clear();
        cnt = 0;
    }
    
    void add(int left, int right) {
        auto it = m.upper_bound(left); //the interval whose left is > left
        if(it != m.begin() && prev(it)->second >= left) it = prev(it); //in the case where the prev interval's right is >= left
        //the reason we can use if instead of while in the above statement is becasue in the case where two intervals that come before "it" have prev(it)->second >= left, they would've gotten merged so there shouldn't be more that one interval where prev(it)->second >= left.
        //iteratre through all intervals that intersect with the interval you are adding
        while(it != m.end() && it->first <= right) { //until you get to the interval that doesn't intersect with left and right
            left = min(left, it->first);
            right = max(right, it->second);
            cnt -= (it->second - it->first + 1);
            m.erase(it++);
        }
        cnt += (right - left + 1);
        m[left] = right;
    }
    
    int count() {return cnt;}
};

/**
 * Your CountIntervals object will be instantiated and called as such:
 * CountIntervals* obj = new CountIntervals();
 * obj->add(left,right);
 * int param_2 = obj->count();
 */