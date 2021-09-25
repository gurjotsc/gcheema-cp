class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& temperatures) {
        unordered_map<int, int> m;
        int max  = 0;
        for(int i = temperatures.size() - 1; i >= 0; --i) {
            if(i == temperatures.size() - 1) {
                m[temperatures[i]] = i;
                max = temperatures[i];
                temperatures[i] = 0;
                continue;
            }

            if(temperatures[i] >= max) {
                m[temperatures[i]] = i;
                max = temperatures[i];
                temperatures[i] = 0;
                continue;
            }

            int tempIndex = INT_MAX;
            for(int j = temperatures[i] + 1; j <= 100; ++j) {
                if(m.find(j) != m.end() && m[j] < tempIndex) tempIndex = m[j];
            }

            m[temperatures[i]] = i;
            temperatures[i] = tempIndex - i;
        }

        return temperatures;
    }
};
