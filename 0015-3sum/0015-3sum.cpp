class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {

        // sort array [1,2,3,4,5]
        sort(nums.begin(), nums.end());
        //for (int i = 0; i < nums.size(); i++) 
        //   cout << nums[i] << ",";
        vector<vector<int>> ret;
        
        // loop for every index in the array
        for (int i = 0; i < nums.size(); i++) {

            if (i > 0 && nums[i] == nums[i - 1]) {continue;}
            int start = i + 1;
            int end = nums.size() - 1;

            //[1,2,3,4,5]
            // | ^     ^ fix i and then two pointers for the rest of the array 
            while (start < end) {
                int lhs = nums[i] + nums[start] + nums[end];
                
                if (lhs == 0) {
                    ret.push_back({nums[i], nums[start], nums[end]});
                    start++;
                    end--;
                    // skip dupilicates
                    while (start < end && nums[start] == nums[start - 1]) { start++; } 
                    while (start < end && nums[end] == nums[end + 1]) { end--; }
                } else if (lhs < 0) {
                    start++;
                } else {
                    end--;
                }
            }
        }
        return ret;
    }
};