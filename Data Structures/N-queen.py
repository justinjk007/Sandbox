'''
Assignment #1
Author  : Justin Kaipada
ID      : 100590167
Date    : 17-02-2017
Purpose : This program solves the N-queen problem in the recurive and the
          iterative way. Backtracking algorithm has been implmented here
'''

count = 0  # This is the placed queen counter
board = []  # This is the global array that store the queen


def iterativeMethod():
    "This solves the N-queen problem in the iterative way"
    return 0


def iterativeMethodAllSolution():
    "This solves the N-queen problem in the iterative way for all sollution"
    return 0


def recursiveMethod(n):
    "This solves the N-queen problem in the recursive way"

    return 0


def recursiveMethodAllSolution(board):
    "This solves the N-queen problem in the recursive way for all the solution"
    global count
    if (count != N):
        for i in range(0, N):
            for j in range(0, N):
                board[i][j] = "Q "  # Here we are assigining the queen & then sending it for checking
                count += 1
                if(conflictChecker(i, j)):
                    board[i][j] = "O "  # If there is a conflict we assign back the default charecter
                    count -= 1
                else:
                    pass  # There are no conflicts so we can continue
    else:
        return board


def conflictChecker(row, column):
    "This funtion checks for conflicts with other queens currently in the board"
    if(not(row == 0 and column == 0)):
        '''
        If row and coloumns are equal to 0, then there won't be any
        conflicts because we are only begining here, so skip and return
        true
        '''
        for i in range(0, N):  # This loop checks for conflicts diagonally
            if(board[row][column] == board[i][i]):
                return True  # There are conflicts
            else:
                pass
        for i in range(0, N):  # This loop checks for conflicts in each row and coloumn
            for j in range(0, N):
                if(board[row][j] == board[row][column] or board[i][column] == board[row][column]):
                    return True  # There are conflicts
                else:
                    pass
    return False  # There are no conflicts


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
for i in range(0, N):
    board.append(["O "]*N)

draw()

# http://stackoverflow.com/questions/4818201/n-queen-problem-in-python
