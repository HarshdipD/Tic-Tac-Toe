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
player = player%2 #Player number changes after each turn
i = -1
while i == -1:
    PrintGrid()
    if player%2:
        player = 1
    else:
        player = 2
    #Takes input from the user to fill in the grid
    print("player ", end="")
    print(player, end="")
    #Ask for the number to input in the grid
    choice = input(", enter a number: ")
    mark = player
    if player == 1:
        mark = 'X'
    else:
        mark = 'O'
    if(choice == 1 and TicTacToe[1] == '1'):
        TicTacToe[1] = [mark]

    elif(choice == 2 and TicTacToe[2] == '2'):
        TicTacToe[2] = [mark]

    elif(choice == 3 and TicTacToe[3] == '3'):
        TicTacToe[3] = [mark]

    elif(choice == 4 and TicTacToe[4] == '4'):
        TicTacToe[4] = [mark]

    elif(choice == 5 and TicTacToe[5] == '5'):
        TicTacToe[5] = [mark]

    elif(choice == 6 and TicTacToe[6] == '6'):
        TicTacToe[6] = [mark]

    elif(choice == 7 and TicTacToe[7] == '7'):
        TicTacToe[7] = [mark]

    elif(choice == 8 and TicTacToe[8] == '8'):
        TicTacToe[8] = [mark]

    elif(choice == 9 and TicTacToe[9] == '9'):
        TicTacToe[9] = [mark]
    else:
        print("Invalid move!")
        player = player - 1

    #increase the number of player for next turn
    player = player + 1
    print(TicTacToe)
