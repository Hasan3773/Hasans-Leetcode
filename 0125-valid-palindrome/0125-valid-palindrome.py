class Solution(object):
    def isPalindrome(self, s):
        # remove all non letter/numbers
        # read through s backwards and see if its the same as s

        cleanstring = ''.join(c.lower() for c in s if(c.isalnum()))
        one = 0 
        two = len(cleanstring) - 1

        while (one < two):
            if (cleanstring[one] != cleanstring[two]):
                return False
            one += 1
            two -= 1

        return True 
        