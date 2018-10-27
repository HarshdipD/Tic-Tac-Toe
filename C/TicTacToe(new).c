//Done a little different from they the assignment. Still works, even better maybe :')

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>
#include <unistd.h>

void PrintBoard();
int isValidBoard();
void InitializeBoard();
int TicTacToeGame();

//Initializing the array. For ease of numbering, there is a 'o' (It has no use).
//char TicTacToe[10] = {'o', '1', '2', '3', '4', '5', '6', '7', '8', '9'};

//Initializing the 2D array
char TicTacToe[3][3] = {{'1', '2', '3'}, {'4', '5', '6'}, {'7', '8', '9'}};
  /***************************
  The grid will look like this:
      1  2  3
      4  5  6
      7  8  9
  ***************************/


int main()
{
  int menu_option;

  /**
  MAIN MENU
  **/

  printf("Welcome!\n");
  printf("TicTacToe:\n");
  do
  {
    printf("MAIN MENU\n");
    printf("Press 1 to play, 0 to exit: ");
    scanf("%d", &menu_option);
    switch(menu_option){
      case 0:
      {
        printf("Alright, exiting the program...\n");
        //Pranking the user lol
	  	sleep(1);
	  	break;
      }

      case 1:
      {
        InitializeBoard();
        TicTacToeGame();
        break;
      }

      default:
      {
        //If entered number for menu is not a valid input
        printf("Unrecognized input, enter a valid number\n\n");
        break;
      }
    }
  }while(menu_option != 0); //End the program after user enters "0 " in the main menu

  printf("Thanks for playing!\n");  //Bye bye message
  return 0;
}

//FUNCTIONS START HERE

int TicTacToeGame(){
  int player = 1;
  int i;            //To get the return value of Check() function
  int choice;
  int menu_option;
  char mark;
  do
  {
  		  printf("\n\n");
          PrintBoard();

          player = (player % 2) ? 1 : 2;
          printf("Player %d, enter a number: ", player);
          scanf("%d", &choice);

          mark = (player == 1) ? 'X' : 'O';

          if(choice == 1 && TicTacToe[0][0] == '1')
          {
            TicTacToe[0][0] = mark;
          }
          else if(choice == 2 && TicTacToe[0][1] == '2')
          {
            TicTacToe[0][1] = mark;
          }
          else if(choice == 3 && TicTacToe[0][2] == '3')
          {
            TicTacToe[0][2] = mark;
          }
          else if(choice == 4 && TicTacToe[1][0] == '4')
          {
            TicTacToe[1][0] = mark;
          }
          else if(choice == 5 && TicTacToe[1][1] == '5')
          {
            TicTacToe[1][1] = mark;
          }
          else if(choice == 6 && TicTacToe[1][2] == '6')
          {
            TicTacToe[1][2] = mark;
          }
          else if(choice == 7 && TicTacToe[2][0] == '7')
          {
            TicTacToe[2][0] = mark;
          }
          else if(choice == 8 && TicTacToe[2][1] == '8')
          {
            TicTacToe[2][1] = mark;
          }
          else if(choice == 9 && TicTacToe[2][2] == '9')
          {
            TicTacToe[2][2] = mark;
          }
          else if(choice == -1)
          {
            printf("Exiting the program...\n\n Thanks for playing!\n");
            break;
          }
          else{
            printf("Invalid move! To exit the game, press -1.\n\n");
            player--;
          }
          player++;
          i = isValidBoard();

        }while(i == -1); //While the game has no result, it keeps taking input for the board. Here "-1" is a return from the Check() function   

        //Updates the grid one last time to show the reult
        PrintBoard();

        //If I was returned as 1 from Check() function: 
        if(i == 1)
        {
    		printf("Finding the winner...\n");
    		sleep(1);
          	printf("Player %d (%c) won!\n", player-1, mark);
        }
        else
        {
          printf("Woah, That's a tie!\n");    //Otherwise, it's a tie
        }
}

//CHECKS IF THE GAME IS FINISHED OR NOT
int isValidBoard()
{
  //Each if statement checks every possibility if the game is won by any user, or it's a tie, not nothing yet
  //See if the first row is matching with same 'X' or 'O'
  if((TicTacToe[0][0] == TicTacToe[0][1]) && (TicTacToe[0][1] == TicTacToe[0][2]))
  {
    return 1;
  }
  else if((TicTacToe[0][0] == TicTacToe[1][0]) && (TicTacToe[1][0] == TicTacToe[2][0]))
  {
    return 1;
  }
  else if((TicTacToe[0][0] == TicTacToe[1][1]) && (TicTacToe[1][1] == TicTacToe[2][2]))
  {
    return 1;
  }
  else if((TicTacToe[0][1] == TicTacToe[1][1]) && (TicTacToe[1][1] == TicTacToe[2][1]))
  {
    return 1;
  }
  else if((TicTacToe[0][2] == TicTacToe[1][2]) && (TicTacToe[1][2] == TicTacToe[2][2]))
  {
    return 1;
  }
  else if((TicTacToe[0][2] == TicTacToe[1][1]) && (TicTacToe[1][1] == TicTacToe[2][0]))
  {
    return 1;
  }
  else if((TicTacToe[1][0] == TicTacToe[1][1]) && (TicTacToe[1][1] == TicTacToe[1][2]))
  {
    return 1;
  }
  else if((TicTacToe[2][0] == TicTacToe[2][1]) && (TicTacToe[2][1] == TicTacToe[2][2]))
  {
    return 1;
  }
  //If the board is filled and no user has won, it's a tie
  else if(TicTacToe[0][0] != '1' && TicTacToe[0][1] != '2' &&
          TicTacToe[0][2] != '3' && TicTacToe[1][0] != '4' &&
          TicTacToe[1][1] != '5' && TicTacToe[1][2] != '6' &&
          TicTacToe[2][0] != '7' && TicTacToe[2][1] != '8' &&
          TicTacToe[2][2] != '9')
  {
            return 0;
  }

  //If no result, return -1 so the nest user can play the next turn
  else
  {
    return -1;
  }
}


//Prints the TicTacToe grid
void PrintBoard()
{
  //User interface
  printf("Player 1: X\tvs\tPlayer 2: O\n");

  printf("     |     |     \n");
  printf("  %c  |  %c  |  %c  \n", TicTacToe[0][0], TicTacToe[0][1], TicTacToe[0][2]);
  printf("_____|_____|_____\n");
  printf("     |     |     \n");
  printf("  %c  |  %c  |  %c \n", TicTacToe[1][0], TicTacToe[1][1], TicTacToe[1][2]);
  printf("_____|_____|_____\n");
  printf("     |     |     \n");
  printf("  %c  |  %c  |  %c \n", TicTacToe[2][0], TicTacToe[2][1], TicTacToe[2][2]);
  printf("     |     |     \n\n");
}



//Clears the grid back to default
void InitializeBoard()
{

	int c = 1;

	for(int i = 0; i < 3; i++)
	{
		for(int j = 0; j < 3; j++)
		{
	    	TicTacToe[i][j] = c + '0';
	    	c++; 
	    }
	    //TicTacToe[i] = i + '0';
	  }
}
