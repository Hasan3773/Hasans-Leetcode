class Solution {
public:
    bool containsDuplicate(vector<int>& nums) {
        int arraysize = nums.size();
        sort(nums.begin(), nums.end());
        for (int i = 1; i < arraysize; i++){
            if (nums[i] == nums[i - 1])
                return true;
        } 
        return false;
    }
};