# Prints the sum of digits using recursion
def sumD(num):
    if(num/10 != 0):
        return num % 10 + sumD(num/10)
    else:
        return num % 10


print sumD(1111)
