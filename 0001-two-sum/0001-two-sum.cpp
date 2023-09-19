class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int,int> table;
        vector<int> answer;

        for (int i = 0; i < nums.size(); i++){
            int compliment = target - nums[i];
            if (table.count(compliment) > 0){
                return {table[compliment],i};
            }   
            table[nums[i]] = i;
        }
        return {};

    }
};