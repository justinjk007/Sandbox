# You wrote down many positive integers in a string called num. However, you realized that you
# forgot to add commas to seperate the different numbers. You remember that the list of integers was
# non-decreasing(increasing ?) and that no integer had leading zeros.

# Return the number of possible lists of integers that you could have written down to get the string
# num. Since the answer may be large, return it modulo 10^9 + 7.

# Example 1:

# Input: num = "327"
# Output: 2
# Explanation: You could have written down the numbers:
# 3, 27
# 327

# 4376
# 4,376
# 43,76

# Example 2:

# Input: num = "094"
# Output: 0
# Explanation: No numbers can have leading zeros and all numbers must be positive.

# Example 3:

# Input: num = "0"
# Output: 0
# Explanation: No numbers can have leading zeros and all numbers must be positive.

# [['monkey'],
#  ['m', 'onkey'],
#  ['mo', 'nkey'],
#  ['mon', 'key'],
#  ['monk', 'ey'],
#  ['monke', 'y'],
#  ['m', 'o', 'nkey'],
#  ['m', 'on', 'key'],
#  ['m', 'onk', 'ey'],
#  ['m', 'onke', 'y'],
#  ['mo', 'n', 'key'],
#  ['mo', 'nk', 'ey'],
#  ['mo', 'nke', 'y'],
#  ['mon', 'k', 'ey'],
#  ['mon', 'ke', 'y'],
#  ['monk', 'e', 'y'],
#  ['m', 'o', 'n', 'key'],
#  ['m', 'o', 'nk', 'ey'],
#  ['m', 'o', 'nke', 'y'],
#  ['m', 'on', 'k', 'ey'],
#  ['m', 'on', 'ke', 'y'],
#  ['m', 'onk', 'e', 'y'],
#  ['mo', 'n', 'k', 'ey'],
#  ['mo', 'n', 'ke', 'y'],
#  ['mo', 'nk', 'e', 'y'],
#  ['mon', 'k', 'e', 'y'],
#  ['m', 'o', 'n', 'k', 'ey'],
#  ['m', 'o', 'n', 'ke', 'y'],
#  ['m', 'o', 'nk', 'e', 'y'],
#  ['m', 'on', 'k', 'e', 'y'],
#  ['mo', 'n', 'k', 'e', 'y'],
#  ['m', 'o', 'n', 'k', 'e', 'y']]


class Solution:
    def numberOfCombinations(self, num: str) -> int:
        if(num[:1]==0):
            return 0


def check_valid(perms: []) -> bool:
    prev = perms[0]
    for var in perms:
        if(var >= prev):
            prev = var
        else:
            return False
    return True
