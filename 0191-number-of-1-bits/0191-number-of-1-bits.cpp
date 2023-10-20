class Solution {
public:
    int hammingWeight(uint32_t n) {
        // I am given a number
        // to find out how many 1 bits are in the binary representation of the num


        // Sol 1 O(n) time complexity & O(1) space complexity:
        // For loop that goes through each bit of n, checking if it = 1 then bit shifting
        int numOnes = 0;
        // int checkNum = 0x1;
        // for (int i = 0; i < sizeof(int)*8; i++){
        //     if (n & checkNum){
        //         numOnes++;
        //     }
        //     checkNum = checkNum << 1;
        // }
        // return numOnes;

        // Sol 1 O(logn) & 0(1) space complexity:
        // Using brian-kernighans algorithm
        while(n){
            n &= n - 1;
            numOnes++;
        }
        return numOnes;
        
    }
};
