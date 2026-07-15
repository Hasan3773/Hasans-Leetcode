class Solution {
public:
    vector<bool> kidsWithCandies(vector<int>& candies, int extraCandies) {
        int most_candies = 0;
        vector<bool> result;
        for (int i = 0; i < candies.size(); i++){
            most_candies = max(candies[i], most_candies);
        }
        for (int j = 0; j < candies.size(); j++){
            result.push_back(candies[j] + extraCandies >= most_candies);
        }
        return result;
    }
};