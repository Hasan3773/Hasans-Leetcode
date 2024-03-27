class Solution {
    public:
    bool isPalindrome(string s) {
        // given a string 
        // output true or false if the string is a valid palindrome 
        // might have to covert to lower case letters and remove non letters
        // so its a two pointer questions so obviously wants to use 2 pointers
        // ex: racecar, just have two pointers iterate through the string and make sure they are always equal to eachother, and perhaps the end condition is that you iterate through the string for num letters /2 so for racecar, or honestly just the whole length lol
        string cleanString;
        for (char c : s) {
            if (isalnum(c)) {
                cleanString += tolower(c);
            }
        }
        
        // Two pointers approach to check for palindrome
        int left = 0;
        int right = cleanString.length() - 1;
        while (left < right) {
            if (cleanString[left] != cleanString[right]) {
                return false;
            }
            left++;
            right--;
        }
        return true;
    }
};