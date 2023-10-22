class Solution {
public:
    int getSum(int a, int b) {
        // The goal is to get the sum of two integers without using + or -
        // basically asking to implement algo that uses bitwise to do sum

        // lets say we have 0001 + 0010, which is 1 + 2, the & operator would work to 0011
        // but lets say 0011 + 0010, & would give us 0010
        // Idea lets for loop through each of the ints, adding the right most bit, then 
        // right shifting, I think we might be able to carry ones 
        int mask = 0x1;
        int round = 1;
        int num = 0;
        int carry = 0;

        for (int i = 0; i < sizeof(int)*8; i++){
            // mask a & b to get the LSB of each
            int bitA = a & mask;
            int bitB = b & mask;

            // calcs the sum of the two nums using xor
            int sum = bitA ^ bitB;

            // takes into acount the carry to the sum
            sum ^= carry;

            // calculates the carry for the next bit by 
            // by checking the case where a & b are 1 and
            // the case where 1 or the other is 1 and there is a carry 
            carry = (bitA & bitB) | (carry & (bitA ^ bitB));
            
            // adds the bit specifc sum to the overall sum
            num |= (sum << i);

            // right shifts for next bit
            a >>= 1;
            b >>= 1;
        }
    
        return num;
    }
};