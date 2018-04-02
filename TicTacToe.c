#include <stdio.h>
#include <stdlib.h>
#include <time.h>


void Computer(char array[3][3]);

int main(){

  int row_input, col_input;

  printf("\nTicTacToe!\n");
  printf("Your symbol is 'X'\n");

  char TicTacToe[3][3] = { {'1', '2', '3'},
                            {'4', '5', '6'},
                            {'7', '8', '9'}};

  for (int i = 0; i < 3; i++) {
    for (int j = 0; j < 3; j++) {
      printf("%c ", TicTacToe[i][j]);
    }
    printf("\n");
  }
  printf("Enter where you want to put your X in the form \"row,col\":  \n");
  scanf("%d,%d\n", &row_input, &col_input);

  TicTacToe[row_input-1][col_input-1] = 'X';

  for (int i = 0; i < 3; i++) {
    for (int j = 0; j < 3; j++) {
      printf("%c ", TicTacToe[i][j]);
    }
    printf("\n");
  }
  Computer(TicTacToe);



  return 0;
}

void Computer(char array[3][3]){

  time_t t;
  srand((unsigned) time(&t));
  int random = rand() % 9;

  for(int i = 0; i < 3; i++){
    for(int j = 0; j < 3; j++){
      if(array[i][j] == random){
        array[i-1][j-1] = 'O';
      }
    }
  }
}
