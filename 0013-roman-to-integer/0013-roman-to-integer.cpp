class Solution {
public:
    int romanToInt(string s) {
        unordered_map<char,int> table;

        table['I'] = 1;
        table['V'] = 5;
        table['X'] = 10;
        table['L'] = 50;
        table['C'] = 100;
        table['D'] = 500;
        table['M'] = 1000;
        int answer = 0;

        for (int i = 0; i < s.length(); i++){
            if (table[s[i]] < table[s[i + 1]])
                answer -= table[s[i]];
            else 
                answer += table[s[i]];
        } 
        return answer;
    }
};