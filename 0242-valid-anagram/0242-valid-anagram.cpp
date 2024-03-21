class Solution {
public:
    bool isAnagram(string s, string t) {
        // We are given two strings 
        // Goal is to see if one string can be made by rearranging the other 
        // Output in a true or false
        // lol I could prob parse one string into a hashmap and then for loop the other to check the map 
        #include <unordered_map>
        unordered_map <char,int> map;
        // first value is the parsed char and the second is the index ig
        
        // think I need to parse s first
        for (int i = 0; i < s.size(); i++){
            if (map.find(s[i]) != map.end()){
                map[s[i]] += 1;
            }
            else {
                map[s[i]] = 1;
            }
        }
        
        for (int j = 0; j < t.size(); j++){
            // checks if this char of t in the map which should contain all values of s
            if (map.find(t[j]) != map.end()){
                map[t[j]] -= 1;
            }
            else {
                cout << "fail 1";
                return false;
            }

        }
        
        for (auto [key,value]:map){
            if (value != 0){
                cout << "fail 2";
                return false;
            }
        }
        
        return true;
        
    }
};