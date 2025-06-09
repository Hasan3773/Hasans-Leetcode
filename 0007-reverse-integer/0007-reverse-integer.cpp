class Solution {
public:
    int reverse(int x) {
        // something to do with mod and division
        // 123 -> 321 
        // 123 % 10 = 3 
        // 123 / 10 = 12.3 = 12 (floored)
        int answer = 0;
        while(x != 0){
            int digit = x % 10;
            x /= 10;
            if (answer > INT_MAX/10 || answer < INT_MIN/10)
                return 0;

            answer = answer * 10 + digit;
        }
        return answer;




        /*
        // turn into character array and reverse
        bool isNeg = false;
        if (x < 0) isNeg = true;
        auto number = to_string(x);
        // cout << number << " of type: " << typeid(number).name() << endl;
        ::reverse(number.begin(), number.end());

        auto answer = stoi(number);
        // cout << answer << " of type: " << typeid(answer).name() << endl;

        if(answer < pow(-2,31) || answer > pow(2,31) - 1 ) return 0;
        if (isNeg) return -answer;
        return answer;*/
    }
};