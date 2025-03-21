class Solution {
public:
    int pivotIndex(vector<int>& nums) {
        int leftSum = 0;
        int rightSum = 0;

        for (int i = 0; i < nums.size(); i++){
            rightSum = rightSum + nums[i];
        }

        for (int i = 0; i < nums.size(); i++){
            rightSum = rightSum - nums[i];
            if (rightSum == leftSum)
                return i;

            leftSum = leftSum + nums[i];
        }
        return -1;
    }
};