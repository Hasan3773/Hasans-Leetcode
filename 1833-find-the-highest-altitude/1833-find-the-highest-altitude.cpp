class Solution {
public:
    int largestAltitude(vector<int>& gain) {
        int prefixSum[gain.size() + 1];
        prefixSum[0] = 0;
        int highestAlt = 0;

        for (int i = 1; i <= gain.size(); i++){
            prefixSum[i] = prefixSum[i - 1] + gain[i - 1];
            if (prefixSum[i] > highestAlt) 
                highestAlt = prefixSum[i];
        }

        return highestAlt;

    }
};