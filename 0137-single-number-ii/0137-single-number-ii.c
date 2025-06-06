int singleNumber(int* nums, int numsSize) {
    // each element appears 3 times other than 1 which appears only once
    // [3, 3, 3, 1, 1, 2, 1] = 6 + 3 + 2 = 11 % 3 = 2 
    // have a hashmap for each value <value, # appearances> return key with value 1
    // everything is repeated an odd number of times so cant just use ^ operator
    // Single number 1 was solved using % 2, this is % 3
    // similarly we want to compute each bit by bit
    // want to add first bit of every number
    // 0101, 1101, 1110 
    // 
    long sol = 0;
    int mask = 0x01;

    for (int bit = 0; bit < 32; bit++){
        long bitsum = 0;
        for (int i = 0; i < numsSize; i++){
            bitsum += (nums[i] >> bit) & mask;
        }
        sol |= (bitsum % 3) << bit;
    }
    return sol;

}