class Solution {
public:
    int removeElement(vector<int>& nums, int val) {
        int arraySize = nums.size();
        int counter = 0;


        for (int i = 0; i < arraySize; i++){
            if (nums[i] != val){
                nums[counter] = nums[i];
                counter++;
            }
        }
        return counter;
    }
};