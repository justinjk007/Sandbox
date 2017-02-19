'''
Assignment #1
Author  : Justin Kaipada
ID      : 100590167
Date    : 17-02-2017
Purpose : This program solves the N-queen problem in the recurive and the
          iterative way. Backtracking algorithm has been implmented here
'''

board = []  # This is the global array that store the queen


def iterativeMethod():
    "This solves the N-queen problem in the iterative way"
    return 0


def iterativeMethodAllSolution():
    "This solves the N-queen problem in the iterative way for all sollution"
    return 0


def recursiveMethod(column, size):
    "This solves the N-queen problem in the recursive way"
    global board
    global N
    for i in range(0, size):
        if(conflictChecker(i, column)):
            board[i][column] = 1
            if(recursiveMethod(column+1, size)):
                return True
            board[i][column] = 0
    return False


def recursiveMethodAllSolution(board):
    "This solves the N-queen problem in the recursive way for all the solution"
    return 0


def conflictChecker(row, column):
    "This funtion checks for conflicts with other queens currently in the board"
    global board
    global N
    for i in range(0, column):
        if(board[row][i] == 1):
            return False
    i = row
    j = column
    while(i >= 0 and j >= 0):
        if(board[i][j] == 1):
            return False
        j -= 1
        i -= 1
    i = row
    j = column
    while(i >= 0 and i < N):
        if(board[i][j] == 1):
            return False
        j -= 1
        i += 1
    return True  # There are no conflicts


def draw():
    "This method is used to draw the solved problem into human readable way"
    global board
    global N
    print "\n"
    print "The Q represents the queens"
    print "---------------------------------------"
    print "\n"
    for i in range(0, N):
        print "|",
        for j in range(0, N):
            print str(board[i][j]) + "|",
        print "\n"
    print "---------------------------------------"


# N = input("Please enter the value of N: ")
# print N
N = 8
for i in range(0, N):
    board.append([0]*N)

recursiveMethod(0, N)
draw()

# http://stackoverflow.com/questions/4818201/n-queen-problem-in-python
