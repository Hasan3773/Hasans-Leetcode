class Solution {
public:
    bool containsDuplicate(vector<int>& nums) {
        #include <unordered_map>
        unordered_map<int,int>map;
        
        for (int i = 0; i < nums.size(); i++){
            
            if (map.count(nums[i]) > 0){
                return true;
            }   
            map[nums[i]] = i;       
        }
        return false;
    }
};