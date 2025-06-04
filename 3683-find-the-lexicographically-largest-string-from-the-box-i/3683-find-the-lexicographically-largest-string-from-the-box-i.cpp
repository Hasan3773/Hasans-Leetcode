class Solution {
public:
    string answerString(string word, int numFriends) {
        // the string word is split into numFriends # of strings 
        // the split cant be the same as the split from any previous rounds
        // how many rounds are there?
        // all the different strings are put into a box? lol
        // find the string in the 'box' of all the string that starts with the earliest alphabeticall letter
        // what data structure to hold the different combinations of the word -> list with tuples of size numfriends
        // -> map with key of the round # and value a tuple of size numFriends
        // okay so apperently a two pointer problem    
        // min(word.size() - numfriends + 1, word.size() - i)
        //  -> 5 - 2 + 1 = 4 || -> 6 - 1

        if (numFriends == 1) return word;
        string res;
        int n = word.length();
        for (int i = 0; i < n; i++){
            res = max(res, word.substr(i, min(n - numFriends + 1, n - i)));
        }
        return res;
    } 
};