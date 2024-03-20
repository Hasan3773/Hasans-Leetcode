class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        // given an array of nums and a target 
        // return two nums that add up to target 
        #include <unordered_map> 
        unordered_map<int,int> map;
        
        for (int i = 0; i < nums.size(); i++){        
            // calculate the value that we are looking for
            int value = target - nums[i];
            
            // go through the current map looking for our value
            if(map.find(value) != map.end()){
                return {map[value],i};
            }  
            map.insert(make_pair(nums[i], i));    
        }
        return vector<int>{0};
    }
};