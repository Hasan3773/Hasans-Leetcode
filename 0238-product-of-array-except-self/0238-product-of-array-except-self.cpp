class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        int totalProduct = 1;
        int arraySize = nums.size();
        vector<int> productArray(arraySize,1);
        vector<int> leftArray(arraySize,1);
        vector<int> rightArray(arraySize,1);

        int leftProduct = 1;
        for (int i = 0; i < arraySize; i++){
            leftArray[i] = leftProduct;
            leftProduct *= nums[i];
        }

        int rightProduct = 1;
        for (int j = arraySize - 1; j >= 0; j--){
            rightArray[j] *= rightProduct;
            rightProduct *= nums[j];
        }

        for (int k = 0; k < arraySize; k++){
            productArray[k] = leftArray[k] * rightArray[k];
        }

        return productArray;
    }
};