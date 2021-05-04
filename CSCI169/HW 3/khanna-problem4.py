
NQ = 8 # number of queens

def printBoard(board): # prints board, like printing a 2x2 matrix
    for i in range(NQ):
        for j in range(NQ):
            print(board[i][j], end=" ")
        print()

def checkQueen(row, col, board): #checks a fixed row to see where a queen can go
    for i in range(col): # checks if there is another queen to the left (in the row)
        if board[row][i]==1:
            return False
    for i, j in zip(range(row, -1, -1), range(col, -1, -1)):
        if board[i][j]==1: # checks if there is another queen in upper left diagonal
            return False
    for i, j in zip(range(row, NQ, 1), range(col, -1, -1)):
        if board[i][j]==1: # checks if there is another queen in lower left diagonal
            return False
    return True # if there are no threatening queens, then the coast is clear

def placeQueen(board, col):
    if (col>=NQ): # all queens have been placed
        return True
    for i in range(NQ):
        if checkQueen(i, col, board)==True: # checks all rows for a column to see if a queen can be placed
            board[i][col]=1 # places queen
            if placeQueen(board, col+1)==True: # recursive call to potentially place the next queen
                return True
            board[i][col]=0 # if the board is not safe, then it repositions the previous queen, sets place to 0 to reposition it
            # tries to reposition previous queen by continuing the for loop
            # note: if the for loop os completed for each queen, then the game fails
    return False # returns false if a queen cannot be placed

board = [ [0, 0, 0, 0, 0, 0, 0, 0],
          [0, 0, 0, 0, 0, 0, 0, 0],
          [0, 0, 0, 0, 0, 0, 0, 0],
          [0, 0, 0, 0, 0, 0, 0, 0],
          [0, 0, 0, 0, 0, 0, 0, 0],
          [0, 0, 0, 0, 0, 0, 0, 0],
          [0, 0, 0, 0, 0, 0, 0, 0],
          [0, 0, 0, 0, 0, 0, 0, 0] ]

if (placeQueen(board, 0)==True): # start the game at column index 0
    printBoard(board) # print result
else:
    print("Unable to solve.") # error message
    printBoard(board) # print attempt, which will be an empty board
