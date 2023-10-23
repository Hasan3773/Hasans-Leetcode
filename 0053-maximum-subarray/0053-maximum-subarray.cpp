class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        // get an array and then return the sum of the largest subarray
        // Go through array keeping track of current subarray
        // if the subarray is the largest encountered so far update max sum
        int maxSum = -100000;
        int currentSum = 0;
        for (int i = 0; i < nums.size(); i++){
            currentSum += nums[i];
            if (currentSum > maxSum)
                maxSum = currentSum;
            if (currentSum < 0)
                currentSum = 0;
        }
        return maxSum;
    }
};