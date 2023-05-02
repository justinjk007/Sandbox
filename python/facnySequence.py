# -*- compile-command: "python facnySequence.py" -*-

# Write an API that generates fancy sequences using the append, addAll, and multAll operations.

# Implement the Fancy class:

#     Fancy() Initializes the object with an empty sequence.
#     void append(val) Appends an integer val to the end of the sequence.
#     void addAll(inc) Increments all existing values in the sequence by an integer inc.
#     void multAll(m) Multiplies all existing values in the sequence by an integer m.

#     int getIndex(idx) Gets the current value at index idx
#     (0-indexed) of the sequence modulo 109 + 7. If the index is greater or equal than
#     the length of the sequence, return -1.


class Fancy:

    def __init__(self):
        self.obj = []
        self.add = 0
        self.multiple = 1
        self.operations

    def append(self, val: int) -> None:
        self.obj.append(val)
        # print(self.obj)

    def addAll(self, inc: int) -> None:
        if(len(self.obj) == 0):
            pass
        self.add += inc
        # print(self.obj)

    def multAll(self, m: int) -> None:
        if(len(self.obj) == 0):
            pass
        self.multiple *= m

        for i in range(0, len(self.obj)):
            self.obj[i] = self.obj[i]*m
        # print(self.obj)

    def getIndex(self, idx: int) -> int:
        try:
            return self.obj[idx] % (pow(10, 9) + 7)
        except Exception as e:
            return -1


# Your Fancy object will be instantiated and called as such:
# obj = Fancy()
# obj.append(val)
# obj.addAll(inc)
# obj.multAll(m)
# param_4 = obj.getIndex(idx)

# fancy = Fancy()
# fancy.append(2)   # fancy sequence: [2]
# fancy.addAll(3)   # fancy sequence: [2+3] -> [5]
# fancy.append(7)   # fancy sequence: [5, 7]
# fancy.multAll(2)  # fancy sequence: [5*2, 7*2] -> [10, 14]
# print(fancy.getIndex(0)) # return 10
# fancy.addAll(3)   # fancy sequence: [10+3, 14+3] -> [13, 17]
# fancy.append(10)  # fancy sequence: [13, 17, 10]
# fancy.multAll(2)  # fancy sequence: [13*2, 17*2, 10*2] -> [26, 34, 20]
# print(fancy.getIndex(0)) # return 26
# print(fancy.getIndex(1)) # return 34
# print(fancy.getIndex(2)) # return 20
