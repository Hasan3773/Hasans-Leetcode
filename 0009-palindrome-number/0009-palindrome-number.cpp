class Solution {
public:
    bool isPalindrome(int x) {
        // corner cases
        if (x < 0) {
            return false;
        }
        if (x != 0 && (x % 10) == 0){
            return false;
        }
        
        // we will reverse on the second half of the number 
        int reversed = 0;

        while (x > reversed) {
            
            // Removes the last digit of the x and put the new num into reversed 
            reversed = (reversed * 10) + (x % 10);
            x /= 10;
        }
        
        if (reversed == x){
            return true;
        }
        if (x == reversed/10){
            return true;
        }
        return false;
    }
};