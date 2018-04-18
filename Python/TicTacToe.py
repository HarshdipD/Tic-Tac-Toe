print("Tic-Tac-Toe!")
print("Welcome...")

#Assigning values to the grid
#The grid will look like this:
#  1  2  3
#  4  5  6
#  7  8  9
TicTacToe = ['o', '1', '2', '3', '4', '5', '6', '7', '8', '9']
#Designation a number to player:
player = 1

#Prints the grid of TicTacToe as the game progresses
def PrintGrid():
    print("Player 1: X\tvs\tPlayer 2: O");
    print("     |     |     ");
    print("  " + TicTacToe[1] + "  |  " + TicTacToe[2] + "  |  " + TicTacToe[3] + "  ")
    print("_____|_____|_____");
    print("     |     |     ");
    print("  " + TicTacToe[4] + "  |  " + TicTacToe[5]+"  |  " + TicTacToe[6] + "  ")
    print("_____|_____|_____");
    print("     |     |     ");
    print("  " + TicTacToe[7] + "  |  " + TicTacToe[8]+"  |  " + TicTacToe[9] + "  ")
    print("     |     |     ");

def Check():
    #If first row is full with same characters, the game is over and the player with that character has won
    if((TicTacToe[1] == TicTacToe[2]) and (TicTacToe[2] == TicTacToe[3])):
        return 1
    #If first column is full with same characters, the game is over and the player with that character has won
    elif((TicTacToe[1] == TicTacToe[4]) and (TicTacToe[4] == TicTacToe[7])):
        return 1

    elif((TicTacToe[1] == TicTacToe[5]) and (TicTacToe[5] == TicTacToe[9])):
        return 1

    elif((TicTacToe[2] == TicTacToe[5]) and (TicTacToe[5] == TicTacToe[8])):
        return 1

    elif((TicTacToe[3] == TicTacToe[6]) and (TicTacToe[6] == TicTacToe[9])):
        return 1

    elif((TicTacToe[3] == TicTacToe[5]) and (TicTacToe[5] == TicTacToe[7])):
        return 1

    elif((TicTacToe[4] == TicTacToe[5]) and (TicTacToe[5] == TicTacToe[6])):
        return 1

    elif((TicTacToe[7] == TicTacToe[8]) and (TicTacToe[8] == TicTacToe[9])):
        return 1

  #If the board is filled and no user has won, it's a tie
    elif(TicTacToe[1] != '1' and TicTacToe[2] != '2' and TicTacToe[3] != '3' and TicTacToe[4] != '4' and TicTacToe[5] != '5'
    and TicTacToe[6] != '6' and TicTacToe[7] != '7' and TicTacToe[8] != '8' and TicTacToe[9] != '9'):
            return 0

  #If no result, return -1 so the next user can play the next turn
    else:
        return -1



#MAIN FUNCTION STARTS
player = player % 2 #Player number changes after each turn
#i is a value returned by Check() function that determines whether the game is over or still incomplete
i = -1
while i == -1:
    PrintGrid()
    if player % 2:
        player = 1
    else:
        player = 2
    #Takes input from the user to fill in the grid
    print("player ", end="")
    print(player, end="")
    choice = int(input(", enter a number: "))

    mark = player
    if player == 1:
        mark = 'X'
    else:
        mark = 'O'
    print(choice)
    #Checks if the grid element is already filled or not. If not, fills it as user desired.
    if (choice == 1 and TicTacToe[1] == '1'):
        TicTacToe[1] = mark

    elif(choice == 2 and TicTacToe[2] == '2'):
        TicTacToe[2] = mark

    elif(choice == 3 and TicTacToe[3] == '3'):
        TicTacToe[3] = mark

    elif(choice == 4 and TicTacToe[4] == '4'):
        TicTacToe[4] = mark

    elif(choice == 5 and TicTacToe[5] == '5'):
        TicTacToe[5] = mark

    elif(choice == 6 and TicTacToe[6] == '6'):
        TicTacToe[6] = mark

    elif(choice == 7 and TicTacToe[7] == '7'):
        TicTacToe[7] = mark

    elif(choice == 8 and TicTacToe[8] == '8'):
        TicTacToe[8] = mark

    elif(choice == 9 and TicTacToe[9] == '9'):
        TicTacToe[9] = mark
    else:
        print("Invalid move!")
        player = player - 1

    #increase the number of player for next turn
    player = player + 1
    i = Check()
#Prints the grid one final time
PrintGrid()

#If I was returned as 1 from Check() function:
if(i == 1):
    print("Player ", end="")
    print(player-1, end="")
    print(" won!", end="")
else: #Otherwise, it's a tie
    print("Woah! That's a tie!")
