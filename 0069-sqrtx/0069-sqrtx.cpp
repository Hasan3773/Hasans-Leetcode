class Solution {
public:
    int mySqrt(int x) {

        if (x == 0 || x == 1) return x;

        // Binary Search aproach:
        // I start at the x and then divide by two
        // check if the new num is the val 
        // if not check if its less than or greater than the val
        int start = 1;
        int end = x;
        int middle = -1;
        while(start <= end){
            // calc the middle point
            middle = start + (end - start)/2;

            // calc square and convert to long long
            long long square = static_cast<long long>(middle) * middle;

            if (square > x)
                end = middle - 1;
            else if (square == x)
                return middle;
            else 
                start = middle + 1;
        }
        return static_cast<int>(round(end));
    }
};