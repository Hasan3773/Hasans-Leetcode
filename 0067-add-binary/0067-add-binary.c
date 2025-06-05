#define max(x,y) (((x) >= (y)) ? (x) : (y))

char* addBinary(char* a, char* b) {
    int a_len = strlen(a);
    int b_len = strlen(b);
    int size = max(a_len, b_len);
    char* output = (char *) malloc(size + 2); // one for overflow one for \0
    output[size + 1] = '\0';
    int i = a_len - 1;
    int j = b_len - 1;
    int k = size;
    int carry = 0;

    while (i >= 0 || j >= 0 || carry){
        int bitA = (i >= 0) ? a[i--] - '0': 0;
        int bitB = (j >= 0) ? b[j--] - '0': 0;
        int sum = bitA ^ bitB ^ carry;
        carry = (bitA & bitB) | (bitA & carry) | (bitB & carry);
        output[k--] = sum + '0';
    }
    if (k == -1) return output;
    return output + 1; // if we didnt use the spot for the carried 1    
}