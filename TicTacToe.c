#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void PrintGrid();

  char TicTacToe[10] = {'o', '1', '2', '3', '4', '5', '6', '7', '8', '9'};


int main(){

  PrintGrid();
  
  return 0;
}

void PrintGrid(){
  printf("TicTacToe!\n");
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
