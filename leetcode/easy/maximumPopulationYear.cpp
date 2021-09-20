class Solution {
public:
    int maximumPopulation(vector<vector<int>>& logs) {
        int N = 102; // represents 102 years for indexing issues
        vector<int> population(N); //stores the "entrance and exit" first and then the pop.
        int ans = 0;
        //iterate through logs and increment the year ppl were born and decrement when the died
        for(int i = 0; i < logs.size(); ++i) {
            ++population[logs[i][0] - 1950];
            --population[logs[i][1] - 1950];

        }
        //Since right now, population[i] just repreents the net gain of people in a certain year, we can keep a running total by iterating through all the years and representing the current popluation by taking the net gain of year i + how many people were alive last year (population[i-1])
        //The first iteration at one will take how many ppl were born in 1951 and add it with people born in 1950. Then we can add this with 1952 and so on.
        //Now it stores the population at year i
        for(int i = 1; i < N; ++i) {
            population[i] += population[i - 1];
        }

        int m = 0; //max
        //iterate through population to find the first year with the max population
        for(int i = 0; i < N; ++i) {
            if(m < population[i]) {
                m = population[i];
                ans = i;
            }
        }
        return ans + 1950;
    }
};
