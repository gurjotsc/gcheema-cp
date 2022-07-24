class NumberContainers {
public:
    map<int, int> m1;
    map<int, set<int>> m2;
    NumberContainers() {
        m1.clear();
        m2.clear();
    }
    
    void change(int index, int number) {
        if(m1.count(index)) {
            m2[m1[index]].erase(index);
            m1[index] = number;
            m2[number].insert(index);
        }
        else {
            m1[index] = number;
            m2[number].insert(index);
        }
        
    }
    
    int find(int number) {
        return (*m2[number].begin() > 0) ? *m2[number].begin() : -1;
    }
};

/**
 * Your NumberContainers object will be instantiated and called as such:
 * NumberContainers* obj = new NumberContainers();
 * obj->change(index,number);
 * int param_2 = obj->find(number);
 */