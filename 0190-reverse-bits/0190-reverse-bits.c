uint32_t reverseBits(uint32_t n) {
    uint32_t reversed = 0;
    uint32_t curr = 0x01;

    for (int i = 31; i >= 0; i--){
        if ((n & curr) == curr){
            reversed += (uint32_t)0x01 << i;
        }
        curr = curr << 1;
    }

    return reversed;
    
}