class Solution {
public:
    void moveZeroes(vector<int>& nums) {

        // Brute force O(N^2):
        // Loop through array and if 0 remove 0 and reindex the array, assign 0 to the last index

        // Additional array O(N):
        // Loop through array & add all non-zero values to new array, count num zeros & add that many to the end

        // Double pointer O(2N):
        // Loop through array only if the value is non-zero, have a counter that keeps the index of the non-zero elements & reassign the corresponding index with the non-zero value

        int counter = 0;

        for (int i = 0; i < nums.size(); i++){
            if (nums[i] != 0){
                nums[counter] = nums[i];
                counter++;
            }
        }

        for (int j = counter; j < nums.size(); j++){
            nums[j] = 0;
        }

    }
};