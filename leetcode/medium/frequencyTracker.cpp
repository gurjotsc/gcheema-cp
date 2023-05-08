class FrequencyTracker {
public:
    vector<int> num, freq;
    FrequencyTracker() {
        num.resize(1e5+1);
        freq.resize(1e5+1);
    }
    
    void add(int number) {
        freq[num[number]]--;
        num[number]++;
        freq[num[number]]++;
    }
    
    void deleteOne(int number) {
        if(num[number]) {
            freq[num[number]]--;
            num[number]--;
            freq[num[number]]++;
        }
    }
    
    bool hasFrequency(int frequency) {
        return freq[frequency];
    }
};

/**
 * Your FrequencyTracker object will be instantiated and called as such:
 * FrequencyTracker* obj = new FrequencyTracker();
 * obj->add(number);
 * obj->deleteOne(number);
 * bool param_3 = obj->hasFrequency(frequency);
 */