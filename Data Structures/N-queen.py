'''
Assignment #1
Author  : Justin Kaipada
ID      : 100590167
Date    : 17-02-2017
Purpose : This program solves the N-queen problem in the recurive and the
          iterative way. Backtracking algorithm has been implmented here
'''


def iterativeMethod():
    "This solves the N-queen problem in the iterative way"
    return 0


def recursiveMethod():
    "This solves the N-queen problem in the recursive way"
    return 0


def draw():
    "This method is used to draw the solved problem into human readable way"
    print "\n"
    print "The Q represents the queens"
    print "---------------------------------------"
    for i in range(0, N):
        print "|",
        for j in range(0, N):
            print board[i][j] + "|",
        print "\n"
    print "---------------------------------------"


# N = input("Please enter the value of N: ")
# print N
N = 5
board = []
for i in range(0, N):
    board.append(["O "]*N)

draw()
