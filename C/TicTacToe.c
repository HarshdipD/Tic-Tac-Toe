#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>

void PrintGrid();
int Check();
  //Initializing the array. For ease of numbering, there is a 'o' (It has no use).
  char TicTacToe[10] = {'o', '1', '2', '3', '4', '5', '6', '7', '8', '9'};
  /***************************
  The grid will look like this:
      1  2  3
      4  5  6
      7  8  9
  ***************************/

int main(){
  int player = 1;
  int i;            //To get the return value of Check() function
  int choice;
  int menu_option;
  char mark;

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

        }while(i == -1);

        PrintGrid();
        if(i == 1){
          printf("Player %d (%c) won!\n", player-1, mark);
        }
        else{
          printf("Woah, That's a tie!\n");
        }
        break;
      }

      default: {
        printf("Unrecognized input, enter a valid number\n\n");
        break;
      }
    }
  }while(menu_option != 0);

  printf("Thanks for playing!\n");
  return 0;
}


//CHECKS IF THE GAME IS FINISHED OR NOT
int Check(){
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
  else if(TicTacToe[1] != '1' && TicTacToe[2] != '2' && TicTacToe[3] != '3' && TicTacToe[4] != '4' &&
          TicTacToe[5] != '5' && TicTacToe[6] != '6' && TicTacToe[7] != '7' && TicTacToe[8] != '8'
          && TicTacToe[9] != '9')
          {
            return 0;
          }
  else{
    return -1;
  }
}


//Prints the TicTacToe grid

void PrintGrid(){
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
