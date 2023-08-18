int hammingWeight(uint32_t n) {
    uint32_t current = 0x01;
    uint32_t ones = 0; 

    for (uint32_t i = 0; i<32; i++){
        if( (n & current) != 0)
        {
             ones++;
        }
        current = current << 1;
    }
    return ones;
}