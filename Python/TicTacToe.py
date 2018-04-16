print("Tic-Tac-Toe!")
print("Welcome...")

#Assigning values to the grid
#The grid will look like this:
#  1  2  3
#  4  5  6
#  7  8  9
TicTacToe = ['o', '1', '2', '3', '4', '5', '6', '7', '8', '9']
#Designation a number to player
player = 1

#Prints the grid of TicTacToe as the game progresses
def PrintGrid():
    print("Player 1: X\tvs\tPlayer 2: O\n");
    print("     |     |     ");
    print("  " + TicTacToe[1] + "  |  "+TicTacToe[2]+"  |  " + TicTacToe[3]+"  ")
    print("_____|_____|_____");
    print("     |     |     ");
    print("  " + TicTacToe[4] + "  |  "+TicTacToe[5]+"  |  " + TicTacToe[6]+"  ")
    print("_____|_____|_____");
    print("     |     |     ");
    print("  " + TicTacToe[7] + "  |  "+TicTacToe[8]+"  |  " + TicTacToe[9]+"  ")
    print("     |     |     ");


##Main Function starts
PrintGrid()
player = (player%2) ? 1 : 2; #Player number changes after each turn
