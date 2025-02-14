class Solution {
public:
    int singleNumber(vector<int>& nums) {
        // [1,2,3,1,2] & [1,2,3,1,2]
        // loop over the array and if an number is new put it in the hashmap
        // if the number is already in the map remove it
        // the last number in the map is the single one

        multiset<int> set;

        for (int i = 0; i < nums.size(); ++i){
            if (set.count(nums[i]) > 0){
                set.erase(nums[i]);
            }
            else{
                set.insert(nums[i]);
            }
        }
        return *set.begin();

    }
};