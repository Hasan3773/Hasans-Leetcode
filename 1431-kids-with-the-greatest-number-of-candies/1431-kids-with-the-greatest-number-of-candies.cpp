class Solution {
public:
    vector<bool> kidsWithCandies(vector<int>& candies, int extraCandies) {
        int most_candies = 0;
        vector<bool> result;
        for (int i = 0; i < candies.size(); i++){
            if (candies[i] > most_candies)
                most_candies = candies[i];
        }
        for (int j = 0; j < candies.size(); j++){
            if (candies[j] + extraCandies >= most_candies)
                result.push_back(true);
            else 
                result.push_back(false);
        }
        return result;
    }
};