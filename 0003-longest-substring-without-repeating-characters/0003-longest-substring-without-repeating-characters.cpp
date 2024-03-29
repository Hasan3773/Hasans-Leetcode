#include <unordered_map>
class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        // given a string s 
        // find the length of the longest substring without repeating char's
        // go through the string and add each char to a hashmap
        // on each iteration check the hashmap to see if the char is duplicated, if not add to the maxLength 
        // some implecation of the answer thing that I'll figure out later
        int maxLength = 0;
        unordered_map<char, int> map;
    
        int left = 0; // Left pointer of the sliding window

        for (int right = 0; right < s.length(); right++) {
            char c = s[right];
            
            if (map.find(c) != map.end() && map[c] >= left) {
                left = map[c] + 1;
            }
            
            map[c] = right;
            maxLength = max(maxLength, right - left + 1);
        }
        return maxLength;
    }
};