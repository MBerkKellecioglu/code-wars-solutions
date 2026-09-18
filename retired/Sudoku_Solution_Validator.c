#include<stdbool.h>
#include<stdlib.h>
#include<stdio.h>

bool validSolution(unsigned int board[9][9]){
  
   int i,j,k,l,m = 0,n,o, flag = 0;
  
  int sudo[10];
  
   for(i = 0; i < 7; i = i + 3){
    for(j = 0; j < 7; j = j + 3){
      for(k = j; k < j + 3; k++){
        for(l = i; l < i + 3; l++){
          sudo[m] = board[l][k];
          printf("%d ", sudo[m]);
          m++;
        }
      }
      m = 0;
      for(n = 0; n < 8; n++){
        for(o = n + 1; o < 9; o++){
          if(sudo[n] == sudo[o]){
            return false;
          }
        }
      }
    }
  }
  
  return true;
  
}