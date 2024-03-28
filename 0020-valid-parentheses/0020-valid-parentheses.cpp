#include <stack>

class Solution {
public:
    bool isValid(string s) {
        // Given a string of brackets [] {} ()
        // return whether each open bracket has a closing in the right order
        // gonna use a stack, push each open bracket to a stack and then check that 
        // [ 
        // check if the next value is the correct bracket based off a hashmap 
        
        stack<int> stack;
        
        for (int i = 0; i < s.length(); i++){
            if (s[i] == '{' || s[i] == '[' || s[i] == '('){
                stack.push(s[i]);
            }
            
            if (stack.size() == 0  && (s[i] == ')' || s[i] == ']' || s[i] == '}')){
                return false;
            }
            
            //
            if (s[i] == '}' && stack.top() != '{'){
                return false;
            }
            if (s[i] == ']' && stack.top() != '['){
                return false;
            }
            if (s[i] == ')' && stack.top() != '('){
                return false;
            }  
            
            //
            if (s[i] == '}' && stack.top() == '{'){
                stack.pop();
            }
            if (s[i] == ']' && stack.top() == '['){
                stack.pop();
            }
            if (s[i] == ')' && stack.top() == '('){
                stack.pop();
            }  

        }
        if (!stack.size()){
            return true; 
        }
        return false;
    }
};