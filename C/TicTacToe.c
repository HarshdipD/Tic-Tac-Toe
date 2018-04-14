#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>

void PrintGrid();
int Check();
void ClearGrid();
int TicTacToeGame();

//Initializing the array. For ease of numbering, there is a 'o' (It has no use).
char TicTacToe[10] = {'o', '1', '2', '3', '4', '5', '6', '7', '8', '9'};
  /***************************
  The grid will look like this:
      1  2  3
      4  5  6
      7  8  9
  ***************************/


int main(){
  int menu_option;
  //MAIN MENU
  printf("Welcome!\n");
  printf("TicTacToe:\n");
  do{
    printf("MAIN MENU\n");
    printf("Press 1 to play, 0 to exit: ");
    scanf("%d", &menu_option);
    switch(menu_option){
      case 0:{
        printf("Alright, exiting the program...\n");
        break;
      }

      case 1:{
        ClearGrid();
        TicTacToeGame();
        break;
      }

      default: {
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
  do{
          PrintGrid();

          player = (player % 2) ? 1 : 2;
          printf("Player %d, enter a number: ", player);
          scanf("%d", &choice);

          mark = (player == 1) ? 'X' : 'O';

          if(choice == 1 && TicTacToe[1] == '1'){
            TicTacToe[1] = mark;
          }
          else if(choice == 2 && TicTacToe[2] == '2'){
            TicTacToe[2] = mark;
          }
          else if(choice == 3 && TicTacToe[3] == '3'){
            TicTacToe[3] = mark;
          }
          else if(choice == 4 && TicTacToe[4] == '4'){
            TicTacToe[4] = mark;
          }
          else if(choice == 5 && TicTacToe[5] == '5'){
            TicTacToe[5] = mark;
          }
          else if(choice == 6 && TicTacToe[6] == '6'){
            TicTacToe[6] = mark;
          }
          else if(choice == 7 && TicTacToe[7] == '7'){
            TicTacToe[7] = mark;
          }
          else if(choice == 8 && TicTacToe[8] == '8'){
            TicTacToe[8] = mark;
          }
          else if(choice == 9 && TicTacToe[9] == '9'){
            TicTacToe[9] = mark;
          }
          else{
            printf("Invalid move!\n");
            player--;
          }
          player++;
          i = Check();

        }while(i == -1); //While the game has no result, it keeps taking input for the board. Here "-1" is a return from the Check() function   

        //Updates the grid one last time to show the reult
        PrintGrid();

        //If I was returned as 1 from Check() function: 
        if(i == 1){
          printf("Player %d (%c) won!\n", player-1, mark);
        }
        else{
          printf("Woah, That's a tie!\n");    //Otherwise, it's a tie
        }
}

//CHECKS IF THE GAME IS FINISHED OR NOT
int Check(){
  //Each if statement checks every possibility if the game is won by any user, or it's a tie, not nothing yet
  if((TicTacToe[1] == TicTacToe[2]) && (TicTacToe[2] == TicTacToe[3])){
    return 1;
  }
  else if((TicTacToe[1] == TicTacToe[4]) && (TicTacToe[4] == TicTacToe[7])){
    return 1;
  }
  else if((TicTacToe[1] == TicTacToe[5]) && (TicTacToe[5] == TicTacToe[9])){
    return 1;
  }
  else if((TicTacToe[2] == TicTacToe[5]) && (TicTacToe[5] == TicTacToe[8])){
    return 1;
  }
  else if((TicTacToe[3] == TicTacToe[6]) && (TicTacToe[6] == TicTacToe[9])){
    return 1;
  }
  else if((TicTacToe[3] == TicTacToe[5]) && (TicTacToe[5] == TicTacToe[7])){
    return 1;
  }
  else if((TicTacToe[4] == TicTacToe[5]) && (TicTacToe[5] == TicTacToe[6])){
    return 1;
  }
  else if((TicTacToe[7] == TicTacToe[8]) && (TicTacToe[8] == TicTacToe[9])){
    return 1;
  }
  //If the board is filled and no user has won, it's a tie
  else if(TicTacToe[1] != '1' && TicTacToe[2] != '2' &&
          TicTacToe[3] != '3' && TicTacToe[4] != '4' &&
          TicTacToe[5] != '5' && TicTacToe[6] != '6' &&
          TicTacToe[7] != '7' && TicTacToe[8] != '8' &&
          TicTacToe[9] != '9'){
            return 0;
          }
  //If no result, return -1 so the nest user can play the next turn
  else{
    return -1;
  }
}


//Prints the TicTacToe grid
void PrintGrid(){
  //User interface
  printf("Player 1: X\tvs\tPlayer 2: O\n");

  printf("     |     |     \n");
  printf("  %c  |  %c  |  %c  \n", TicTacToe[1], TicTacToe[2], TicTacToe[3]);
  printf("_____|_____|_____\n");
  printf("     |     |     \n");
  printf("  %c  |  %c  |  %c \n", TicTacToe[4], TicTacToe[5], TicTacToe[6]);
  printf("_____|_____|_____\n");
  printf("     |     |     \n");
  printf("  %c  |  %c  |  %c \n", TicTacToe[7], TicTacToe[8], TicTacToe[9]);
  printf("     |     |     \n\n");
}



//Clears the grid back to default
void ClearGrid(){
  for(int i = 0; i <= 9; i++){
    TicTacToe[i] = i + '0';
  }
}
