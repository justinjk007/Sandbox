# https://leetcode.com/problems/string-to-integer-atoi/

class Solution:

    smallest = pow(-2, 31)
    largest = pow(2, 31)-1

    def myAtoi(self, s: str) -> int:
        result = ""
        for char in s:
            if(char == " " and result == ""):
                pass
            elif(char == "-" and result == ""):
                result = result+char
            elif(char == "+" and result == ""):
                result = result+char
            elif(ord(char) >= 48 and ord(char) <= 57): # use asci values to check if it's a digit
                result = result+char
            else:
                return self.convert(result)
        return self.convert(result)

    def convert(self, result:str) -> int:
        try:
            # print(self.clamp(int(result)))
            return self.clamp(int(result))
        except Exception as er:
            # print("An exception occurred when printing: "+result+"~") 
            # print(er) 
            return 0

    # -2^31, 2^31 - 1
    def clamp(self, result:int) -> int:
        if result < self.smallest:
            return self.smallest 
        elif result > self.largest:
            return self.largest
        else:
            return result

# obj = Solution()
# obj.myAtoi("4193 with words")
# obj.myAtoi("   +-1234.23")
# obj.myAtoi(" -91283472332")
