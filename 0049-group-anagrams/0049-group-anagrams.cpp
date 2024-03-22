class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        // Okay so I am given an array of strings
        // the desired output is a 2D array of strings where each row contains all possible anagagrams with that combination of letters
        // Okay so I need to go through all the values of the first array and see which words are anagrams of eachother and populate them into the 2D array
        // The corner cases are probobly anagrams that can be made of less letters than the origional word, for example I think 'an' is a valid anagram of 'and'
        // Another corner case is mabye mutliple of the same word which need to be grouped together
        
        // So my method to solve it is prob gonna be a hashmap
        // so what if the key is the string as usual but then the value will be the index of the first unique string of that group, so then strings would be grouped by a common index value, I could assign this by making it so when I search the map it checks if each key it goes through is a valid anagram and if it is, it would add the current string to the map with the same index value as the first valid anagram, and if it does not find one it adds it with its own index
        // I think I could probobly populate the 2D array as I am searching the map as its pretty similar structure but just the map is easier to query 
        // To actually check if the value in the map is a valid palindrom I should prob just make a function 
        
        // Okay so this is pretty lame but yeah what I thought about the sorting was right, you just sort the anagrams and then check if theyre equal because sorting will turn anagrams into the sam string 
        // SO my new method will still use the hashmap but now will store the sorted string  as the value and the index as the key
        // then I will search the map for the same values and put them together in the 2D array
        // THe first for loop will go through the array and sort and put the values in the array
        // then the second loop will populate the 2D array by grouping the same strings
        #include <unordered_map>

        vector<vector<string>> answer;
        unordered_map<string, vector<string>> map;

        for (const string& s : strs) {
            map[getSignature(s)].push_back(s);
        }

        for (const auto& entry : map) {
            answer.push_back(entry.second);
        }

        return answer;
    }
    // I gave up and now I'm using this, ggs
    string getSignature(const string& s) {
        vector<int> count(26, 0);
        for (char c : s) {
            count[c - 'a']++;
        }

        stringstream ss;
        for (int i = 0; i < 26; i++) {
            if (count[i] != 0) {
                ss << (char)('a' + i) << count[i];
            }
        }
        return ss.str();
    }
};